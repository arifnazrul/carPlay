
package com.deere.api.axiom.generated.v3;

import java.util.ArrayList;
import java.util.List;


public class Permissions {

    private final static long serialVersionUID = 1L;

    List<Permission> permissions = new ArrayList<Permission>();

    public List<Permission> getPermissions() {
        return permissions;
    }

    public void setPermissions(List<Permission> permissions) {
        this.permissions = permissions;
    }

    public void addPermission(Permission permission) {
        permissions.add(permission);
    }
}
