//
//  JDURL.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-03-10
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@import Foundation;

/**
 * @brief URL object for an API request.
 * @author Bott Sebastian
 */
@interface JDURL : NSObject

/**
 * The keys to embed.
 */
@property(nonatomic, strong, nullable) NSArray<NSString *> *embedKeys;

/**
 * Returns the URL.
 * @return The URL
 */
- (NSURL *_Nonnull)url;

/**
 * Returns the URL string.
 * @return The URL string
 */
- (NSString *_Nonnull)urlString;

/**
 * Returns the URL string without the parameters.
 * @return The URL string without the parameters
 */
- (NSString *_Nonnull)pathString;

/**
 * Returns the raw endpoint without organization.
 * @return The raw endpoint
 */
- (NSString *_Nonnull)rawEndpoint;

/**
 * Returns the link relation.
 * @param relation The name of the relation
 * @return The dictionary with the link relation
 */
- (NSDictionary *_Nonnull)linkWithRelation:(NSString *_Nonnull)relation;

/**
 * Adds a parameter to the URL.
 * @param requestParameter The parameter as key / value pair.
 */
- (void)addRequestParameter:(NSDictionary<NSString *, NSString *> *_Nullable)requestParameter;

/**
 * Sets the parameters of the URL.
 * @param The parameters of the URL as key / value pairs
 */
- (void)setRequestParameters:(NSMutableDictionary<NSString *, NSString *> *_Nonnull)parameters;

/**
 * Sets a parameter of the URL.
 * @param The parameter of the URL.
 */
- (void)setRequestParameter:(NSDictionary<NSString *, NSString *> *_Nonnull)requestParameter;

/**
 * Adds the default request parameters for start and count.
 */
- (void)addDefaultListParameters;

/**
 * Sets a custom embed parameter name.
 */
- (void)setEmbedParameterName:(NSString *_Nonnull)embedParameterName;

/**
 * Overrides the base URL of the environment.
 * Base URL consists of protocol, hostname and path i.e. http://www.example.com/var/
 * Only change when you are absolutely sure!
 */
- (void)setBaseURL:(NSString *_Nonnull)baseURL;

/**
 * Returns a url parameter for status
 * @return The dictionary having keyvalue for status parameter
 */
- (void)addStatusAllParameter;

#pragma mark Init

/**
 * Creates a URL for a given endpoint.
 * @param endpoint The API endpoint without the base URL
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithEndpoint:(NSString *_Nonnull)endpoint;

/**
 * Creates a URL for a given endpoint.
 * @param endpoint The API endpoint without the base URL
 * @param organizationId The ID of the organization
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithEndpoint:(NSString *_Nonnull)endpoint organizationId:(NSString *_Nonnull)organizationId;

/**
 * Creates a URL for a given endpoint.
 * @param endpoint The API endpoint without the base URL
 * @param objectId The id of the requested object
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithEndpoint:(NSString *_Nonnull)endpoint objectId:(NSString *_Nonnull)objectId;

/**
 * Creates a URL for a given endpoint.
 * @param endpoint The API endpoint without the base URL
 * @param objectId The id of the requested object
 * @param action The action for the object
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithEndpoint:(NSString *_Nonnull)endpoint
                                objectId:(NSString *_Nonnull)objectId
                                  action:(NSString *_Nonnull)action;

/**
 * Creates a URL for a given endpoint.
 * @param endpoint The API endpoint without the base URL
 * @param organizationId The ID of the organization
 * @param objectId The id of the requested object
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithEndpoint:(NSString *_Nonnull)endpoint
                          organizationId:(NSString *_Nonnull)organizationId
                                objectId:(NSString *_Nonnull)objectId;

/**
 * Creates a URL for a given endpoint.
 * @param endpoint The API endpoint without the base URL
 * @param objectId The id of the requested object
 * @param action The action for the object
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithEndpoint:(NSString *_Nonnull)endpoint
                          organizationId:(NSString *_Nonnull)organizationId
                                objectId:(NSString *_Nonnull)objectId
                                  action:(NSString *_Nonnull)action;
/**
 * Creates a URL for a given endpoint.
 * @param endpoint The API endpoint without the base URL
 * @param organizationId The ID of the organization
 * @param objectId The id of the requested object
 * @param action The action for the object
 * @param actionId The id for the action
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithEndpoint:(NSString *_Nonnull)endpoint
                          organizationId:(NSString *_Nonnull)organizationId
                                objectId:(NSString *_Nonnull)objectId
                                  action:(NSString *_Nonnull)action
                                actionId:(NSString *_Nonnull)actionId;

/**
 * Creates a URL for a given endpoint.
 * @param endpoint The API endpoint without the base URL
 * @param objectId The id of the requested object
 * @param action The action for the object
 * @param actionId The id for the action
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithEndpoint:(NSString *_Nonnull)endpoint
                                objectId:(NSString *_Nonnull)objectId
                                  action:(NSString *_Nonnull)action
                                actionId:(NSString *_Nonnull)actionId;

/**
 * Creates a URL from a given string.
 * @param uri The API endpoint with the base URL
 * @return a URL object
 */
+ (instancetype _Nonnull)urlWithUri:(NSString *_Nonnull)uri;

/**
 * Returns a link with relation.
 * @param url The URL
 * @param relation The name of the relation
 * @return The dictionary with the link relation
 */
+ (NSDictionary *_Nonnull)createLinkWithURLString:(NSString *_Nonnull)urlString relation:(NSString *_Nonnull)relation;

/**
 * Returns a string for a given bool value
 * @param boolValue The bool value
 * @return The string representation for a bool value
 */
+ (NSString *_Nonnull)valueForBool:(BOOL)boolValue;

@end
