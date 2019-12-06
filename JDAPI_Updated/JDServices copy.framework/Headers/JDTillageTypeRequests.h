//
//  JDTillageTypeRequests.h
//  JDServices
//
//  Created by Sebastian Bott on 2015-08-21
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDRequestConfiguration.h"
#import "JDRequest.h"

@class JDTillageType;

/**
 * @brief API requests for {@link JDTillageType}.
 */

@interface JDTillageTypeRequests : NSObject

/**
* Fetches a list of all tillage types from the webservice with the default configuration.
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchTillageTypesWithCompletionBlockWithResponse:
    (void (^_Nonnull)(NSArray<JDTillageType *> *_Nullable, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
* Fetches a list of all tillage types from the webservice.
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchTillageTypesWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                              completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDTillageType *> *_Nullable,
                                                                            NSError *_Nullable,
                                                                            JDResponse *_Nullable))completionBlock;

#pragma mark deprecated

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchTillageTypesWithCompletionBlock:
    (void (^_Nonnull)(NSArray<JDTillageType *> *_Nullable tillageTypes, NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchTillageTypesWithConfiguration:(JDRequestConfiguration * _Nonnull)requestConfiguration
                                          completionBlock:
                                              (void (^_Nonnull)(NSArray<JDTillageType *> *_Nullable tillageTypes,
                                                                NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
