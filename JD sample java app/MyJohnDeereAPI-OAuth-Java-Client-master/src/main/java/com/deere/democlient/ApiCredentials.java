package com.deere.democlient;

import com.deere.rest.OAuthClient;
import com.deere.rest.OAuthToken;

public abstract class ApiCredentials {
    
    public static final OAuthClient CLIENT = new OAuthClient("johndeere-UjyYr2hb6keQbkphg0wgJBc6uf9i2lX95KKUPyWv", "c8ebefb89ad12fb7a361326b79d19d7c8982bee1048ec957ec713c0fc9ac2578");
    
    public static final OAuthToken TOKEN = new OAuthToken("627c313b-0aa9-4f1b-98c4-a9b079ab26b7", "J9ZL63KAUdX4dlbM+zlxN6+MqtzeucOYTC+yOvUxQWo+Vx8gb4b+9LoLlQH3cMX2AH3OPwlayJ4xIzCz1UdXTUrPBwc7ZRv1gWWydwDKIS4=");
}
