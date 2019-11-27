//
//  JDOrganizationRequests.h
//  JDServices
//
//  Created by Bott Sebastian 2016-03-11
//
//  Unpublished Work (c) 2014-2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDRequestConfiguration.h"
#import "JDRequest.h"

typedef NS_OPTIONS(NSUInteger, JDOrganizationEmbedOptions) {
    JDOrganizationEmbedNone = 0,
    JDOrganizationEmbedPreferences = 1 << 0,
    JDOrganizationEmbedAddresses = 1 << 1
};

@class JDOrganization;
@class JDResponse;

/**
 * @brief API requests for {@link JDOrganization}.
 */
@interface JDOrganizationRequests : NSObject <JDRequestEmbed>

#pragma mark - GET Requests

/**
* Fetches a list of all organizations for the current user from the webservice with the default request configuration.
* @param embedOptions The {@link JDOrganizationEmbedOptions} which should be embedded in the response (bitmask)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchOrganizationsWithEmbedOptions:(JDOrganizationEmbedOptions)embedOptions
                              completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDOrganization *> *_Nullable,
                                                                            NSError *_Nullable,
                                                                            JDResponse *_Nullable))completionBlock;

/**
* Fetches a list of all organizations for the current user from the webservice.
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param embedOptions The {@link JDOrganizationEmbedOptions} which should be embedded in the response (bitmask)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchOrganizationsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                              embedOptions:(JDOrganizationEmbedOptions)embedOptions
                               completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDOrganization *> *_Nullable,
                                                                             NSError *_Nullable,
                                                                             JDResponse *_Nullable))completionBlock;

/**
* Fetches a list of all organizations for the current user from the webservice with the default request configuration.
* @param embedOptions The {@link JDOrganizationEmbedOptions} which should be embedded in the response (bitmask)
* @param filterForMemberOrganizations If <code>YES</code> The result contains only member organizations, otherwise all
* organizations are included
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchOrganizationsWithEmbedOptions:(JDOrganizationEmbedOptions)embedOptions
                             filterForMemberOrganizations:(BOOL)filterForMemberOrganizations
                              completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDOrganization *> *_Nullable,
                                                                            NSError *_Nullable,
                                                                            JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all organizations the user belongs to.
 * @param username The username
 * @param embedOptions The {@link JDOrganizationEmbedOptions} which should be embedded in the response (bitmask)
 * @param completionBlock The completion block
 */
+ (JDRequest *_Nonnull)fetchOrganizationsForUsername:(NSString *_Nonnull)username
                                        embedOptions:(JDOrganizationEmbedOptions)embedOptions
                         completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDOrganization *> *_Nullable,
                                                                       NSError *_Nullable,
                                                                       JDResponse *_Nullable))completionBlock;
#pragma mark - Deprecated

/**
* @deprecated
*/
+ (JDRequest *_Nonnull)fetchOrganizationsWihCompletionBlock:
    (void (^_Nonnull)(NSArray<JDOrganization *> *_Nullable organizations, NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
* @deprecated
*/
+ (JDRequest *_Nonnull)fetchOrganizationsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                           completionBlock:
                                               (void (^_Nonnull)(NSArray<JDOrganization *> *_Nullable organizations,
                                                                 NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
- (void)orgsForUserWithCompletion:(void (^_Nonnull)(NSArray *_Nullable orgs, NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
- (void)orgsWithPreferencesForUserWithCompletion:
    (void (^_Nonnull)(NSArray *_Nullable orgs, NSError *_Nullable error))completionBlock DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
- (void)memberOrgsForUserName:(NSString *_Nonnull)userName
               withCompletion:(void (^_Nonnull)(NSArray *_Nullable orgs, NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
- (void)orgsWithParameterString:(NSString *_Nonnull)parameterizedString
         shouldFilterMemberOrgs:(BOOL)shouldFilter
          forUserWithCompletion:(void (^_Nonnull)(NSArray *_Nullable orgs, NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
