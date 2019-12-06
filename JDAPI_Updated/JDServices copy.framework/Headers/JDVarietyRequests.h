//
// Created by Nico Boder on 11.09.18.
// Copyright (c) 2018 Deere & Company. All rights reserved.
//

@class JDRequest;
@class JDVarietyRequestContract;
@class JDResponse;
@class JDVariety;

@interface JDVarietyRequests : NSObject

/**
 * Fetches a list of all varieties from the webservice with a specific request contract.
 * @param contract A {@link JDVarietyRequestContract} containing the request specifications.
 * @param completionBlock The completion block.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)fetchVarietiesWithContract:(JDVarietyRequestContract *_Nonnull)contract
                      completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDVariety *> *_Nullable, NSError *_Nullable,
                                                                    JDResponse *_Nullable))completionBlock;

/**
 * Creates a new variety.
 *
 * @param variety The variety data model containing the data for the creation.
 * @param organizationId The organization identifier.
 * @param completionBlock Is called after the request execution has been finished.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)createVariety:(JDVariety *_Nonnull)variety
                      organizationId:(NSString *_Nonnull)organizationId
                     completionBlock:
                         (void (^_Nonnull)(NSDictionary *_Nullable response, NSError *_Nullable error))completionBlock;

/**
 * Updates a new variety.
 *
 * @param variety The variety data model containing the data for the creation.
 * @param organizationId The organization identifier.
 * @param completionBlock Is called after the request execution has been finished.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)updateVariety:(JDVariety *_Nonnull)variety
                      organizationId:(NSString *_Nonnull)organizationId
                     completionBlock:
                         (void (^_Nonnull)(NSDictionary *_Nullable response, NSError *_Nullable error))completionBlock;

@end