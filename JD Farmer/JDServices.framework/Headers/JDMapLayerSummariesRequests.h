//
//  JDMapLayerSummariesRequests.h
//  JDServices
//
//  Created by Wright Daniel W on 12/18/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDContributedMapLayerSummary.h"
#import "JDRequest.h"
#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, JDMapLayerSummariesEmbedOptions) {
    JDMapLayerSummariesEmbedNone = 0,
    JDMapLayerSummariesEmbedMapLayers = 1 << 0,
    JDMapLayerSummariesEmbedContributionDefinition = 1 << 1,
    JDMapLayerSummariesEmbedContributionProduct = 1 << 2
};

@interface JDMapLayerSummariesRequests : NSObject <JDRequestEmbed>

/**
 * Fetches a list of all map layer summaries from the webservice with the given request configuration.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param orgId The id of the organization
 * @param fieldId The id of the field
 * @param embedOptions The {@link JDMapLayerSummariesEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchMapLayerSummariesWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                                         orgId:(NSString *_Nonnull)orgId
                                                       fieldId:(NSString *_Nonnull)fieldId
                                                  embedOptions:(JDMapLayerSummariesEmbedOptions)embedOptions
                                   completionBlockWithResponse:
                                       (void (^_Nonnull)(NSArray<JDContributedMapLayerSummary *> *_Nullable,
                                                         NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all map layer summaries from the webservice with the default request configuration.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param orgId The id of the organization
 * @param fieldId The id of the field
 * @param embedOptions The {@link JDMapLayerSummariesEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchMapLayerSummariesWithOrgId:(NSString *_Nonnull)orgId
                                               fieldId:(NSString *_Nonnull)fieldId
                                          embedOptions:(JDMapLayerSummariesEmbedOptions)embedOptions
                           completionBlockWithResponse:
                               (void (^_Nonnull)(NSArray<JDContributedMapLayerSummary *> *_Nullable, NSError *_Nullable,
                                                 JDResponse *_Nullable))completionBlock;

@end
