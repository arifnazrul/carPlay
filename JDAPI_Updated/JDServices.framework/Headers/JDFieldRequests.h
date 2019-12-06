//
//  JDFieldRequests.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-06-03
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDFieldRequestContract.h"
#import "JDOrganization.h"
#import "JDRequest.h"
#import "JDRequestConfiguration.h"

@class JDField;
@class JDResponse;
@protocol JDRequestEmbed;

/**
 * @brief API requests for {@link JDField}.
 */
@interface JDFieldRequests : NSObject <JDRequestEmbed>

#pragma mark - GET Requests
/**
 * Fetches a list of all fields from the webservice with the given contract.
 * @param contract The {@link JDFieldRequestContract}
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldsWithContract:(JDFieldRequestContract *_Nonnull)contract
                   completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDField *> *_Nullable, NSError *_Nullable,
                                                                 JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all fields from the webservice with the default request configuration.
 * @param organizationId The id of the organization
 * @param embedOptions The {@link JDFieldEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchFieldsForOrganizationId:(NSString *_Nonnull)organizationId
                                       embedOptions:(JDFieldEmbedOptions)embedOptions
                        completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDField *> *_Nullable, NSError *_Nullable,
                                                                      JDResponse *_Nullable))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * Fetches a list of all fields from the webservice.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param organizationId The id of the organization
 * @param embedOptions The {@link JDFieldEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                     organizationId:(NSString *_Nonnull)organizationId
                                       embedOptions:(JDFieldEmbedOptions)embedOptions
                        completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDField *> *_Nonnull, NSError *_Nonnull,
                                                                      JDResponse *_Nonnull))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * Fetches a field with a given id from the webservice with the default request configuration.
 * @param fieldId The id of the field
 * @param organizationId The id of the organization
 * @param embedOptions The {@link JDFieldEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldWithFieldId:(NSString *_Nonnull)fieldId
                              organizationId:(NSString *_Nonnull)organizationId
                                embedOptions:(JDFieldEmbedOptions)embedOptions
                 completionBlockWithResponse:
                     (void (^_Nonnull)(JDField *_Nullable, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
 * Fetches a field with a given id from the webservice.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param fieldId The id of the field
 * @param organizationId The id of the organization
 * @param embedOptions The {@link JDFieldEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                           fieldId:(NSString *_Nonnull)fieldId
                                    organizationId:(NSString *_Nonnull)organizationId
                                      embedOptions:(JDFieldEmbedOptions)embedOptions
                       completionBlockWithResponse:(void (^_Nonnull)(JDField *_Nullable, NSError *_Nullable,
                                                                     JDResponse *_Nullable))completionBlock;

#pragma mark - POST Requests

/**
 * Creates or updates a field with the given payload.
 * @param field The field
 * @param organizationId The id of the organization
 * @param userAccountName The user account name of the user
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)postField:(JDField *_Nonnull)field
                  organizationId:(NSString *_Nonnull)organizationId
                 userAccountName:(NSString *_Nonnull)userAccountName
                 completionBlock:
                     (void (^_Nonnull)(NSDictionary *_Nullable response, NSError *_Nullable error))completionBlock;

#pragma mark - Deprecated

/**
* @deprecated use {@link #fetchFieldsForOrganizationId:(nonnull NSString *)organizationId
                                          embedOptions:(JDFieldEmbedOptions)embedOptions
                                       completionBlock:(void (^_Nonnull)(NSArray<JDField *> *_Nullable fields, NSError
*_Nullable error))completionBlock;} instead
*/
+ (JDRequest *_Nonnull)fetchFieldsForOrganizationId:(NSString *_Nonnull)organizationId
                               embedClientsAndFarms:(BOOL)embedClientsAndFarms
                                    completionBlock:(void (^_Nonnull)(NSArray<JDField *> *_Nullable fields,
                                                                      NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
* @deprecated use {@link #fetchFieldsWithConfiguration:(JDRequestConfiguration *)requestConfiguration
                                        organizationId:(NSString *)organizationId
                                          embedOptions:(JDFieldEmbedOptions)embedOptions
                                       completionBlock:(void (^)(NSArray<JDField *> *fields, NSError
*error))completionBlock;} instead
 */
+ (JDRequest *_Nonnull)fetchFieldsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                     organizationId:(NSString *_Nonnull)organizationId
                               embedClientsAndFarms:(BOOL)embedClientsAndFarms
                                    completionBlock:(void (^_Nonnull)(NSArray<JDField *> *_Nullable fields,
                                                                      NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
