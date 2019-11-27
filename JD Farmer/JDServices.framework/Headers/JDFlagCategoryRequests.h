//
//  JDFlagCategoryRequests.h
//  JDServices
//
//  Created by Thielen Andrew P on 2/11/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDFlagCategory.h"
#import "JDRequest.h"

typedef NS_OPTIONS(NSUInteger, JDFlagCategoryEmbedOptions) {
    JDFlagCategoryEmbedNone = 0,
    JDFlagCategoryEmbedPreferences = 1 << 0
};

NS_ASSUME_NONNULL_BEGIN

@interface JDFlagCategoryRequests : NSObject

/**
 * Fetches a list of all flag categories from the webservice with the given request configuration.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param orgId The id of the organization
 * @param embedOptions The {@link JDFlagCategoryEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFlagCategoriesWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                             organizationId:(NSString *_Nonnull)organizationId
                                               embedOptions:(JDFlagCategoryEmbedOptions)embedOptions
                                completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDFlagCategory *> *_Nullable,
                                                                              NSError *_Nullable,
                                                                              JDResponse *_Nullable))completionBlock;

/**
 * Posts a flag category for the given organization to the webservice.
 * @param organizationId The id of the organization
 * @param contributionId The contribution id for flag category
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *)postFlagCategory:(JDFlagCategory *)flagCategory
                 organizationId:(NSString *)organizationId
                 contributionId:(NSString *)contributionId
                completionBlock:(void (^)(NSError *_Nullable, NSString *_Nullable))completionBlock;

/**
 * Puts an existing flag category for the given organization to the webservice.
 * @param organizationId The id of the organization
 * @param contributionId The contribution id for flag category
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *)putFlagCategory:(JDFlagCategory *)flag
                organizationId:(NSString *)organizationId
                contributionId:(NSString *)contributionId
               completionBlock:(void (^)(NSError *_Nullable))completionBlock;

/**
 * Fetches a list of all flag category preferences from the webservice with the given request configuration.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param flagCategoryId The id of the flag category
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFlagCategoryPreferencesWithConfiguration:(JDRequestConfiguration *)requestConfiguration
                                                      flagCategoryId:(NSString *_Nonnull)flagCategoryId
                                         completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDFlagCategoryPreference *>*_Nullable,
                                                                                       NSError *_Nullable,
                                                                                       JDResponse *_Nullable))completionBlock;
@end

NS_ASSUME_NONNULL_END
