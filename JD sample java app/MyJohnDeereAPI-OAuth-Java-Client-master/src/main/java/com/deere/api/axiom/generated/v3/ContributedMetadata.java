package com.deere.api.axiom.generated.v3;

public class ContributedMetadata extends Resource {
    protected String name;
    protected String value;

    public ContributedMetadata() {
    }

    public ContributedMetadata(String name, String value) {
        this.name = name;
        this.value = value;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }
}
