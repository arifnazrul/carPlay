package com.deere.api.axiom.generated.v3;

/**
 * Created by AR02349 on 11/3/2014.
 */

public class Permission extends Resource {

    protected String permissionId;
    protected String type;
    protected String status;

    public String getPermissionId() {
        return permissionId;
    }

    public void setPermissionId(String permissionId) {
        this.permissionId = permissionId;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }
}
