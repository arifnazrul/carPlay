package com.deere.democlient.apis;

import com.deere.api.axiom.generated.v3.ApiCatalog;
import com.deere.api.axiom.generated.v3.File;
import com.deere.api.axiom.generated.v3.Link;
import com.deere.api.pagination.CollectionPage;
import com.deere.rest.HttpHeader;
import com.deere.rest.RestRequest;
import com.deere.rest.RestResponse;
import com.google.common.collect.ImmutableMap;
import org.codehaus.jackson.type.TypeReference;

import java.io.FileOutputStream;
import java.io.IOException;
import java.security.DigestOutputStream;
import java.security.NoSuchAlgorithmException;
import java.util.Map;

import static com.google.common.io.ByteStreams.copy;
import static java.lang.Math.min;
import static java.lang.String.format;
import static java.security.MessageDigest.getInstance;

public class Download extends AbstractApiBase {

    private static Map<String, Link> apiCatalog;
    private CollectionPage<File> files;
    private String firstFileSelfUri;
    private byte[] md5FromSinglePieceDownload;
    private String filename;
    int actualFileSize = 0;
    private File firstFileDetails;

    public static void main(String[] arg) throws Exception {
        final RestRequest apiCatalogRequest = oauthRequestTo(baseUri)
                .method("GET")
                .addHeader(new HttpHeader("Accept", V3_ACCEPTABLE_TYPE))
                .build();

        final RestResponse apiCatalogResponse = apiCatalogRequest.fetchResponse();

        Download download = new Download();

        apiCatalog = download.linksFrom(download.read(apiCatalogResponse).as(ApiCatalog.class));

        download.getFiles();

        download.retrieveMetadataForFile();
        if (download.firstFileDetails != null) {
            //download.downloadFileContentsAndComputeMd5();
            download.downloadFileInPiecesAndComputeMd5();
        }
    }


    public void getFiles() throws Exception {
        final RestRequest filesRequest = oauthRequestTo(apiCatalog.get("files").getUri())
                .method("GET")
                .addHeader(new HttpHeader("Accept", V3_ACCEPTABLE_TYPE))
                .build();

        final RestResponse filesResponse = filesRequest.fetchResponse();

        files = read(filesResponse).as(new TypeReference<CollectionPage<File>>() {
        });

    }

    public void retrieveMetadataForFile() {
        File fileForMetaData = getValidFile();
        if(fileForMetaData == null) {
            return;
        }
        final ImmutableMap<String, Link> linksFromFirstFile = linksFrom(fileForMetaData);

        firstFileSelfUri = linksFromFirstFile.get("self").getUri();

        final RestRequest fileDetails = oauthRequestTo(firstFileSelfUri)
                .method("GET")
                .addHeader(new HttpHeader("Accept", V3_ACCEPTABLE_TYPE))
                .build();

        final RestResponse fileDetailsResponse = fileDetails.fetchResponse();

        firstFileDetails = read(fileDetailsResponse).as(File.class);

        filename = firstFileDetails.getName();
        actualFileSize = firstFileDetails.getNativeSize().intValue();
    }

    private File getValidFile() {
        File fileForMetaData = null;
        for (File file : files) {
            if (file.getType() != "INVALID" || file.getType() != "UNKNOWN") {
                fileForMetaData = file;
                break;
            }
        }
        if (fileForMetaData == null) {
            System.out.println(" No Files to download");
        }
        return fileForMetaData;
    }

    public void downloadFileContentsAndComputeMd5() throws NoSuchAlgorithmException, IOException {

        final RestRequest fileDetails = oauthRequestTo(firstFileSelfUri)
                .method("GET")
                .addHeader(new HttpHeader("Accept", "application/octet-stream"))
                .build();

        final RestResponse fileDetailsResponse = fileDetails.fetchResponse();

        checkFilenameInContentDispositionHeader(fileDetailsResponse);

        java.io.File file = new java.io.File("src/main/resources/" + firstFileDetails.getName());
        if (!file.exists()) {
            file.createNewFile();
        }
        FileOutputStream fileOutputStream = new FileOutputStream(file);
        final DigestOutputStream byteDigest = new DigestOutputStream(fileOutputStream, getInstance("md5"));

        copy(fileDetailsResponse.getBody(), byteDigest);

        md5FromSinglePieceDownload = byteDigest.getMessageDigest().digest();
    }

    public void downloadFileInPiecesAndComputeMd5() throws NoSuchAlgorithmException, IOException {
        // Download the file in chunk of 16 MB
        int maxFileSize = 16 * 1024 * 1024;
        int chunkSize = Math.min(maxFileSize, actualFileSize);
        java.io.File file = new java.io.File("src/main/resources/" + firstFileDetails.getName());
        if (!file.exists()) {
            file.createNewFile();
        }
        FileOutputStream fileOutputStream = new FileOutputStream(file);
        final DigestOutputStream byteDigest = new DigestOutputStream(fileOutputStream, getInstance("md5"));

        getChunkFromStartAndRecurse(0, chunkSize, actualFileSize, byteDigest);

        System.out.println("File Name = " + firstFileDetails.getName());
        System.out.println("File Size(KB) = " + file.length() / 1024.0);
    }

    private void checkFilenameInContentDispositionHeader(final RestResponse fileDetailsResponse) {
        final String contentDispositionHeader = "Content-Disposition";

        if (fileDetailsResponse.getHeaderFields().contains(contentDispositionHeader)) {
            final String contentDisposition = fileDetailsResponse.getHeaderFields().valueOf(contentDispositionHeader);
            final java.util.regex.Matcher matcher = contentDispositionPattern.matcher(contentDisposition);
            if (matcher.matches()) {
                // checkThat("filename as reported by API", matcher.group(2), isEqualTo(filename));
            }
        }
    }

    private void getChunkFromStartAndRecurse(long start,
                                             long chunkSize,
                                             long fileSize,
                                             DigestOutputStream output) throws IOException {
        if(fileSize <= chunkSize){
            fileDownloadRequest(start, fileSize, output);
        }else{
            fileDownloadRequest(start, chunkSize, output);
            getChunkFromStartAndRecurse(start + chunkSize, chunkSize, fileSize - chunkSize, output);
        }
    }

    private void fileDownloadRequest(Long start, Long bytesToRead, DigestOutputStream byteDigest) throws IOException {
        StringBuilder uri = new StringBuilder(firstFileSelfUri)
                .append("?")
                .append("offset=").append(start.toString())
                .append("&")
                .append("size=").append(bytesToRead.toString());

        final RestRequest rangeRequest = oauthRequestTo(uri.toString())
                .method("GET")
                .addHeader(new HttpHeader("Accept", "application/octet-stream"))
                .build();

        final RestResponse rangeResponse = rangeRequest.fetchResponse();
        copy(rangeResponse.getBody(), byteDigest);
    }

}
