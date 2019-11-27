//
//  JDCropTypeRequests.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-06-09
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDRequestConfiguration.h"
#import "JDRequest.h"

@class JDCropType;
@class JDResponse;

/**
 * @brief API requests for {@link JDCropType}.
 */
@interface JDCropTypeRequests : NSObject

/**
 * Fetches a list of all crop types from the webservice with the default request configuration.
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchCropTypesWithCompletionBlockWithResponse:
    (void (^_Nonnull)(NSArray<JDCropType *> *_Nullable, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all crop types from the webservice.
 * @param requestConfiguration The request configuration
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchCropTypesWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                           completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDCropType *> *_Nullable,
                                                                         NSError *_Nullable,
                                                                         JDResponse *_Nullable))completionBlock;

#pragma mark Deprecated

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchCropTypesWithCompletionBlock:
    (void (^_Nonnull)(NSArray<JDCropType *> *_Nullable cropTypes, NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchCropTypesWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                       completionBlock:(void (^_Nonnull)(NSArray<JDCropType *> *_Nullable cropTypes,
                                                                         NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
