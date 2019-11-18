//
//  JDFlagRequests.h
//  JDServices
//
//  Created by Wright Daniel W on 12/11/18.
//  Copyright © 2018 Deere & Company. All rights reserved.
//

#import "JDFileResource.h"
#import "JDFlag.h"
#import "JDRequest.h"

typedef NS_OPTIONS(NSUInteger, JDFlagEmbedOptions) {
    JDFlagEmbedNone = 0,
    JDFlagEmbedFlagCategory = 1 << 0,
    JDFlagEmbedFlagCategoryWithPreferences = 1 << 1,
    JDFlagEmbedField = 1 << 2
};

typedef NS_OPTIONS(NSUInteger, JDFlagShapeTypeQuery) {
    JDFlagShapeTypeQueryDefault = 0,
    JDFlagShapeTypeQueryPoint = 1 << 0,
    JDFlagShapeTypeQueryLineString = 1 << 1,
    JDFlagShapeTypeQueryPolygon = 1 << 2
};

NS_ASSUME_NONNULL_BEGIN

@interface JDFlagRequests : NSObject

/**
 * Fetches the list of flags for the given organization from the webservice with the specified request configuration.
 * @param organizationId The id of the organization
 * @param embedOptions The {@link JDFlagEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *)fetchFlagsWithConfiguration:(JDRequestConfiguration *)configuration
                            organizationId:(NSString *)organizationId
                              embedOptions:(JDFlagEmbedOptions)embedOptions
               completionBlockWithResponse:
                   (void (^)(NSArray<JDFlag *> *_Nullable, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
 * Fetches the list of flags for the given organization from the webservice with the specified request configuration.
 * @param organizationId The id of the organization
 * @param embedOptions The {@link JDFlagEmbedOptions} which should be embedded to the response (bitmask)
 * @param shapeTypesQuery The flag shape types {@link JDFlagShapeTypeQuery} which should be returned (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *)fetchFlagsWithConfiguration:(JDRequestConfiguration *)configuration
                            organizationId:(NSString *)organizationId
                              embedOptions:(JDFlagEmbedOptions)embedOptions
                                shapeTypes:(JDFlagShapeTypeQuery)shapeTypesQuery
               completionBlockWithResponse:
                   (void (^)(NSArray<JDFlag *> *_Nullable, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
 * Posts a flag for the given organization from the webservice.
 * @param organizationId The id of the organization
 * @param contributionId The contribution id for flag notes
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *)postFlag:(JDFlag *)flag
         organizationId:(NSString *)organizationId
         contributionId:(NSString *)contributionId
        completionBlock:(void (^)(NSError *_Nullable, NSString *_Nullable))completionBlock;

/**
 * Puts a flag for the given organization from the webservice.
 * @param organizationId The id of the organization
 * @param contributionId The contribution id for flag notes
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *)putFlag:(JDFlag *)flag
        organizationId:(NSString *)organizationId
        contributionId:(NSString *)contributionId
       completionBlock:(void (^)(NSError *_Nullable))completionBlock;

/**
 * Deletes a flag for the given id from the webservice.
 * @param flagId The id of the flag
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *)deleteFlagById:(NSString *)flagId
              completionBlock:(void (^)(NSDictionary *_Nullable, NSError *_Nullable))completionBlock;

/**
 * Fetches the list of file resources for the given flag from the webservice with the specified request configuration.
 * @param flagId The id of the flag
 * @param completionBlock The completion block
 * @return A {@link JDFileResource} object which contains the tasks this request is performing
 */
+ (JDRequest *)fetchFileResourcesWithConfiguration:(JDRequestConfiguration *)configuration
                                            flagId:(NSString *)flagId
                       completionBlockWithResponse:(void (^)(NSArray<JDFileResource *> *_Nullable, NSError *_Nullable,
                                                             JDResponse *_Nullable))completionBlock;

/**
 * Posts a file resource for the given flag id to the webservice.
 * @param fileResource The file resource to post
 * @param flagId The id of the flag
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *)postFileResource:(JDFileResource *)fileResource
                         flagId:(NSString *)flagId
                 organizationId:(NSString *)organizationId
                completionBlock:(void (^)(NSError *_Nullable, NSString *_Nullable))completionBlock;

@end

NS_ASSUME_NONNULL_END
