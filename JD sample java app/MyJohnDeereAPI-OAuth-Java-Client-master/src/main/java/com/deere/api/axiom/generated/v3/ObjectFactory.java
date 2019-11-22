//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, vJAXB 2.1.10 in JDK 6 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2013.05.28 at 08:29:52 PM CDT 
//


package com.deere.api.axiom.generated.v3;

import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the com.soa.xsd.api._1 package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _AdminGroupID_QNAME = new QName("http://soa.com/xsd/api/1.0", "AdminGroupID");
    private final static QName _APIVersionID_QNAME = new QName("http://soa.com/xsd/api/1.0", "APIVersionID");
    private final static QName _APIID_QNAME = new QName("http://soa.com/xsd/api/1.0", "APIID");
    private final static QName _PlanID_QNAME = new QName("http://soa.com/xsd/api/1.0", "PlanID");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: com.soa.xsd.api._1
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link ApiCatalog }
     * 
     */
    public ApiCatalog createApiCatalog() {
        return new ApiCatalog();
    }

    public File createFile() {
        return new File();
    }

    public Link createLink() {
        return new Link();
    }

    public Organization createOrganization() {
        return new Organization();
    }

    public Organizations createOrganizations() {
        return new Organizations();
    }

    public User createUser() {
        return new User();
    }
}