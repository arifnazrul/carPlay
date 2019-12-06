/**
 * \file AFNetworkingRequestHelper.h
 * \brief Header file for some methods to send data with various authentication methods
 *
 *  Copyright (c) Deere & Company as an unpublished work
 *  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
 *  DEERE & COMPANY.  ALL USE, DISCLOSURE, AND/OR
 *  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 *  DEERE & COMPANY IS PROHIBITED.
 */

#import <Foundation/Foundation.h>
#import <AFNetworking/AFHTTPRequestOperationManager.h>

@class AFNetworkingRequestHelper;
@class JDSecretManager;

/**
 *  \class UserDataUtils
 *  \brief Helper class that offers methods to send data with various authentication methods
 */
@interface AFNetworkingRequestHelper : NSObject

+ (BOOL)signNSURLRequeslRequestForOAuth:(NSMutableURLRequest*)request;

/**
 *  \brief Execute an OAuth authorized JSON url request
 *
 *  This method creates and executes a request operation that is fully signed and takes all needed oauth parameters. It uses AFNetworking (sending) and GTMOAuthAuthentication (oauth signing) methods.
 *
 *  @param type               The type of the request (e.g. GET, POST, PUT, DELETE, ...)
 *  @param resourceURL        The url to the resource (e.g. http://apitest.deere.com/mjdm/)
 *  @param body               The body of the request message
 *  @param headers            Some additional headers for the request (optional) -- application/json will be set automatically
 *  @param responseSerializer A custom response serializer (optional)
 *  @param successHandler     Handler that will be called in case of success
 *  @param failureHandler     Handler that will be called in case of failure
 */
+(void)authorizedURLJSONRequestForRequestType:(NSString*)type
                              withResourceURL:(NSString*)resourceURL
                                      andBody:(NSDictionary*)body
                        withAdditionalHeaders:(NSMutableDictionary*)headers
                        andResponseSerializer:(AFHTTPResponseSerializer*)responseSerializer
                               andDoOnSuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))successHandler
                               andDoOnFailure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failureHandler;

+ (AFHTTPRequestOperation*)operationForURLJSONRequestForRequestType:(NSString*)type
                                                    withResourceURL:(NSString*)resourceURL
                                                            andBody:(NSDictionary*)body
                                              withAdditionalHeaders:(NSMutableDictionary*)headers
                                              andResponseSerializer:(AFHTTPResponseSerializer*)responseSerializer
                                                     andDoOnSuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))successHandler
                                                     andDoOnFailure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failureHandler;

/**
 *  \brief Execute an OAuth authorized url request with a text/plain content type (UTF-8 encoding)
 *
 *  This method creates and executes a request operation that is fully signed and takes all needed oauth parameters. It uses AFNetworking (sending) and GTMOAuthAuthentication (oauth signing) methods.
 *
 *  @param type               The type of the request (e.g. GET, POST, PUT, DELETE, ...)
 *  @param resourceURL        The url to the resource (e.g. http://apitest.deere.com/mjdm/)
 *  @param body               The body of the request message
 *  @param headers            Some additional headers for the request (optional) -- application/json will be set automatically
 *  @param responseSerializer A custom response serializer (optional)
 *  @param successHandler     Handler that will be called in case of success
 *  @param failureHandler     Handler that will be called in case of failure
 */
+(void)authorizedURLPlainTextRequestForRequestType:(NSString*)type
                                   withResourceURL:(NSString*)resourceURL
                                           andBody:(NSString*)body
                             withAdditionalHeaders:(NSMutableDictionary*)headers
                             andResponseSerializer:(AFHTTPResponseSerializer*)responseSerializer
                                    andDoOnSuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))successHandler
                                    andDoOnFailure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failureHandler;

/**
 *  \brief Execute an OAuth authorized JSON url request with attachment
 *
 *  This method creates and executes a request operation that is fully signed and takes all needed oauth parameters. It uses AFNetworking (sending) and GTMOAuthAuthentication (oauth signing) methods. This method allows it to includes a stream body (fileURL)
 *
 *  @param type                     The type of the request (e.g. GET, POST, PUT, DELETE, ...)
 *  @param resourceURL              The url to the resource (e.g. http://apitest.deere.com/mjdm/)
 *  @param fileURL                  The NSURL object to the file on the file system
 *  @param mimeType                 The mime type of the file (e.g. image/jpeg)
 *  @param headers                  Some additional headers for the request (optional)
 *  @param responseSerializer       A custom response serializer (optional)
 *  @param uploadProgressHandler    Handler that will be called when an undetermined number of bytes have been downloaded from the server.
 *  @param downloadProgressHandler  Handler that will be called when an undetermined number of bytes have been uploaded to the server.
 *  @param successHandler           Handler that will be called in case of success
 *  @param failureHandler           Handler that will be called in case of failure
 */
+(void)authorizedURLMultipartFormDataRequestForRequestType:(NSString*)type
                                           withResourceURL:(NSString*)resourceURL
                                                andFileURL:(NSURL*)fileURL
                                              hasMimeTypes:(NSString*)mimeType
                                     withAdditionalHeaders:(NSMutableDictionary*)headers
                                     andResponseSerializer:(AFHTTPResponseSerializer*)responseSerializer
                                     andDoOnUploadProgress:(void (^)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite))uploadProgressHandler
                                   andDoOnDownloadProgress:(void (^)(NSUInteger bytesRead, long long totalBytesRead, long long totalBytesExpectedToRead))downloadProgressHandler
                                            andDoOnSuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))successHandler
                                            andDoOnFailure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failureHandler;

/**
 *  \brief Execute an OAuth authorized JSON url request with attachment
 *
 *  This method creates and executes a request operation that is fully signed and takes all needed oauth parameters. It uses AFNetworking (sending) and GTMOAuthAuthentication (oauth signing) methods. This method allows it to includes a stream body (fileURL)
 *
 *  @param type                     The type of the request (e.g. GET, POST, PUT, DELETE, ...)
 *  @param resourceURL              The url to the resource (e.g. http://apitest.deere.com/mjdm/)
 *  @param fileURL                  The NSURL object to the file on the file system
 *  @param mimeType                 The mime type of the file (e.g. image/jpeg)
 *  @param headers                  Some additional headers for the request (optional)
 *  @param responseSerializer       A custom response serializer (optional)
 *  @param uploadProgressHandler    Handler that will be called when an undetermined number of bytes have been downloaded from the server.
 *  @param downloadProgressHandler  Handler that will be called when an undetermined number of bytes have been uploaded to the server.
 *  @param successHandler           Handler that will be called in case of success
 *  @param failureHandler           Handler that will be called in case of failure
 */
+(AFHTTPRequestOperation*)operationForauthorizedURLMultipartFormDataRequestForRequestType:(NSString*)type
                                                                          withResourceURL:(NSString*)resourceURL
                                                                               andFileURL:(NSURL*)fileURL
                                                                             hasMimeTypes:(NSString*)mimeType
                                                                    withAdditionalHeaders:(NSMutableDictionary*)headers
                                                                    andResponseSerializer:(AFHTTPResponseSerializer*)responseSerializer
                                                                    andDoOnUploadProgress:(void (^)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite))uploadProgressHandler
                                                                  andDoOnDownloadProgress:(void (^)(NSUInteger bytesRead, long long totalBytesRead, long long totalBytesExpectedToRead))downloadProgressHandler
                                                                           andDoOnSuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))successHandler
                                                                           andDoOnFailure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failureHandler;

/**
 *  \brief Execute an basic authorized JSON url request
 *
 *  This method creates and executes a request operation that uses basic authentication. AFNetworking is used for sending the request.
 *
 *  @param type               The type of the request (e.g. GET, POST, PUT, DELETE, ...)
 *  @param resourceURL        The url to the resource (e.g. http://apitest.deere.com/mjdm/)
 *  @param body               The body of the request message
 *  @param headers            Some additional headers for the request (optional)
 *  @param username           Username for the basic authentication
 *  @param password           Password for the basic authentication
 *  @param responseSerializer A custom response serializer (optional)
 *  @param successHandler     Handler that will be called in case of success
 *  @param failureHandler     Handler that will be called in case of failure
 */
+(void)basicAuthorizedURLJSONRequestForRequestType:(NSString*)type
                                   withResourceURL:(NSString*)resourceURL
                                           andBody:(NSDictionary*)body
                             withAdditionalHeaders:(NSMutableDictionary*)headers
                                      usesUsername:(NSString*)username
                                       andPassword:(NSString*)password
                             andResponseSerializer:(AFHTTPResponseSerializer*)responseSerializer
                                    andDoOnSuccess:(void (^)(AFHTTPRequestOperation *operation, id responseObject))successHandler
                                    andDoOnFailure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failureHandler;

/**
 *  \brief Get the oauth token and token secret as a dictionary from the keychain
 *
 *  The token can be accessed as NSString* by using the key "oauth_token" and the token secret by using the key "oauth_token_secret".
 *
 *  @return A dictionary containing the token and token secret; nil if no token is available
 */
+(NSDictionary*)tokenAndTokenSecretFromKeychain;

+ (NSMutableURLRequest *)createSignedRequestForUrl:(NSString *)url withRequestType:(NSString *)type;

@end

/** End of File Copyright ****************************************************
 *
 *  Copyright (c) Deere & Company as an unpublished work
 *  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
 *  DEERE & COMPANY.  ALL USE, DISCLOSURE, AND/OR
 *  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 *  DEERE & COMPANY IS PROHIBITED.
 *
 *****************************************************************************/
