//
//  JDImplementRequests.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-03-23
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDRequest.h"

typedef NS_OPTIONS(NSUInteger, JDImplementsEmbedOptions) {
    JDImplementsEmbedNone = 0,
    JDImplementsEmbedEquipmentIcon = 1 << 0
};

@class JDImplement;
@class JDResponse;

/**
 * @brief API requests for {@link JDImplement}.
 * @author Bott Sebastian
 */
@interface JDImplementRequests : NSObject

/**
 * Fetches a list of all implements from the webservice with the default configuration.
 * @param organizationId The id of the organization
 * @param embedOptions The {@link JDImplementsEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchImplementsWithOrganizationId:(NSString *_Nonnull)organizationId
                                            embedOptions:(JDImplementsEmbedOptions)embedOptions
                             completionBlockWithResponse:
                                 (void (^_Nonnull)(NSArray<JDImplement *> *_Nullable implements,
                                                   NSError *_Nullable error,
                                                   JDResponse *_Nullable response))completionBlock;

/**
* Fetches a list of all implements from the webservice.
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param organizationId The id of the organization
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchImplementsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                         organizationId:(NSString *_Nonnull)organizationId
                            completionBlockWithResponse:
                                (void (^_Nonnull)(NSArray<JDImplement *> *_Nullable implements,
                                                  NSError *_Nullable error,
                                                  JDResponse *_Nullable response))completionBlock;

/**
 * Fetches an implement with a given id from the webservice with the default request configuration.
 * @param implementId The id of the implement
 * @param embedOptions The {@link JDImplementsEmbedOptions} which should be embedded to the response (bitmask)
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchImplementWithImplementId:(NSString *_Nonnull)implementId
                                        embedOptions:(JDImplementsEmbedOptions)embedOptions
                         completionBlockWithResponse:(void (^_Nonnull)(JDImplement *_Nullable, NSError *_Nullable,
                                                                       JDResponse *_Nullable))completionBlock;

/**
 * Fetches an implement with a given id from the webservice.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param implementId The id of the implement
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchImplementWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                           implementId:(NSString *_Nonnull)implementId
                           completionBlockWithResponse:(void (^_Nonnull)(JDImplement *_Nullable, NSError *_Nullable,
                                                                         JDResponse *_Nullable))completionBlock;

#pragma mark Deprecated

/**
 * Fetches a list of all implements from the webservice with the default configuration.
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchImplementsWithOrganizationId:(NSString *_Nonnull)organizationId
                             completionBlockWithResponse:
                                 (void (^_Nonnull)(NSArray<JDImplement *> *_Nullable implements,
                                                   NSError *_Nullable error,
                                                   JDResponse *_Nullable response))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * Fetches an implement with a given id from the webservice with the default request configuration.
 * @param implementId The id of the implement
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchImplementWithImplementId:(NSString *_Nonnull)implementId
                         completionBlockWithResponse:(void (^_Nonnull)(JDImplement *_Nullable, NSError *_Nullable,
                                                                       JDResponse *_Nullable))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
