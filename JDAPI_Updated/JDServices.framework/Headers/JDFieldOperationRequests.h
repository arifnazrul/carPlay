//
//  JDFieldOperationRequests.h
//  JDServices
//
//  Created by Wright Daniel W on 12/13/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDFieldOperation.h"
#import "JDRequest.h"

typedef NS_OPTIONS(NSUInteger, JDFieldOperationEmbedOptions) {
    JDFieldOperationEmbedNone = 0,
    JDFieldOperationEmbedMeasurementTypes = 1 << 0,
    JDFieldOperationEmbedClient = 1 << 1,
    JDFieldOperationEmbedFarm = 1 << 2,
    JDFieldOperationEmbedField = 1 << 3,
    JDFieldOperationEmbedFieldOperationMachines = 1 << 4
};

@interface JDFieldOperationRequests : NSObject <JDRequestEmbed>

/**
 * Fetches a list of all field operations from the webservice with the given request configuration.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param orgId The id of the organization
 * @param startDate The starting date for field operations
 * @param endDate The ending date for field operations
 * @param embedOptions The {@link JDFieldOperationEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldOperationsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                                       orgId:(NSString *_Nonnull)orgId
                                                   startDate:(NSDate *_Nullable)startDate
                                                     endDate:(NSDate *_Nullable)endDate
                                                embedOptions:(JDFieldOperationEmbedOptions)embedOptions
                                 completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDFieldOperation *> *_Nullable,
                                                                               NSError *_Nullable,
                                                                               JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all field operations from the webservice with the default request configuration.
 * @param orgId The id of the organization
 * @param startDate The starting date for field operations
 * @param endDate The ending date for field operations
 * @param embedOptions The {@link JDFieldOperationEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldOperationsForOrgId:(NSString *_Nonnull)orgId
                                          startDate:(NSDate *_Nullable)startDate
                                            endDate:(NSDate *_Nullable)endDate
                                       embedOptions:(JDFieldOperationEmbedOptions)embedOptions
                        completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDFieldOperation *> *_Nullable,
                                                                      NSError *_Nullable,
                                                                      JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all field operations from the webservice with the given request configuration.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param orgId The id of the organization
 * @param fieldId The id of the field
 * @param embedOptions The {@link JDFieldOperationEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldOperationsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                                       orgId:(NSString *_Nonnull)orgId
                                                     fieldId:(NSString *_Nonnull)fieldId
                                                embedOptions:(JDFieldOperationEmbedOptions)embedOptions
                                 completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDFieldOperation *> *_Nullable,
                                                                               NSError *_Nullable,
                                                                               JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all field operations from the webservice with the default request configuration.
 * @param orgId The id of the organization
 * @param fieldId The id of the field
 * @param embedOptions The {@link JDFieldOperationEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldOperationsForOrgId:(NSString *_Nonnull)orgId
                                            fieldId:(NSString *_Nonnull)fieldId
                                       embedOptions:(JDFieldOperationEmbedOptions)embedOptions
                        completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDFieldOperation *> *_Nullable,
                                                                      NSError *_Nullable,
                                                                      JDResponse *_Nullable))completionBlock;

/**
 * Fetches a field operation from the webservice with the given request configuration.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param fieldOperationId The id of the field operation
 * @param embedOptions The {@link JDFieldOperationEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldOperationWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                           fieldOperationId:(NSString *_Nonnull)fieldOperationId
                                               embedOptions:(JDFieldOperationEmbedOptions)embedOptions
                                completionBlockWithResponse:(void (^_Nonnull)(JDFieldOperation *_Nullable,
                                                                              NSError *_Nullable,
                                                                              JDResponse *_Nullable))completionBlock;

/**
 * Fetches a field operation from the webservice with the default request configuration.
 * @param fieldOperationId The id of the field operation
 * @param embedOptions The {@link JDFieldOperationEmbedOptions} which should be embedded to the response (bitmask)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFieldOperationForFieldOperationId:(NSString *_Nonnull)fieldOperationId
                                                 embedOptions:(JDFieldOperationEmbedOptions)embedOptions
                                  completionBlockWithResponse:(void (^_Nonnull)(JDFieldOperation *_Nullable,
                                                                                NSError *_Nullable,
                                                                                JDResponse *_Nullable))completionBlock;

@end
