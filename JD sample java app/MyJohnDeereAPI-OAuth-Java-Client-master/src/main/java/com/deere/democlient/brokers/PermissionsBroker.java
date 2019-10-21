package com.deere.democlient.brokers;

import com.deere.api.axiom.generated.v3.Permission;
import com.deere.api.axiom.generated.v3.Permissions;
import com.deere.democlient.apis.AbstractApiBase;
import com.deere.rest.HttpHeader;
import com.deere.rest.HttpStatus;
import com.deere.rest.RestRequest;
import com.deere.rest.RestResponse;
import com.google.common.io.ByteStreams;

import java.util.List;

import static org.hamcrest.core.IsEqual.equalTo;

public class PermissionsBroker extends AbstractApiBase {
    private static final String REQUESTED_PERMISSION_STATUS = "requested";
    private static final String APPROVED_PERMISSION_STATUS = "approved";

    public Permissions getPermissions(String uri) {
        final RestRequest permissionsRequest = oauthRequestTo(uri)
                .method("GET")
                .addHeader(new HttpHeader("Accept", V3_ACCEPTABLE_TYPE))
                .build();

        final RestResponse permissionsResponse = permissionsRequest.fetchResponse();
        return read(permissionsResponse).as(Permissions.class);
    }

    public void requestPermissions(String uri, List<String> permissionTypesToRequest) {
        updatePermissions(uri, permissionTypesToRequest, REQUESTED_PERMISSION_STATUS);
    }

    public void assignPermissions(String uri, List<String> permissionTypesToAssign) {
        updatePermissions(uri, permissionTypesToAssign, APPROVED_PERMISSION_STATUS);
    }

    private void updatePermissions(String uri, List<String> permissionTypesToUpdate, String desiredStatus) {
        Permissions permissions = getPermissions(uri);
        for (Permission permission : permissions.getPermissions()) {
            if (permissionTypesToUpdate.contains(permission.getType())) {
                permission.setStatus(desiredStatus);
            }
        }
        updatePermissions(uri, permissions);
    }

    private void updatePermissions(String uri, Permissions permissions) {
        RestRequest request = oauthRequestTo(uri)
                .method("POST")
                .addHeader(new HttpHeader("Accept", V3_ACCEPTABLE_TYPE))
                .addHeader(new HttpHeader("Content-Type", V3_CONTENT_TYPE))
                .body(ByteStreams.newInputStreamSupplier(getBytesForObject(permissions)))
                .build();
        final RestResponse response = request.fetchResponse();
//        System.out.println("Response code: " + response.getResponseCode());
        assertThat("Update permissions response is successful", response.getResponseCode(), equalTo(HttpStatus.NO_CONTENT));
    }
}
