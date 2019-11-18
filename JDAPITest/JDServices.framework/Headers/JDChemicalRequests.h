//
// Created by Nico Boder on 11.09.18.
// Copyright (c) 2018 Deere & Company. All rights reserved.
//

@class JDRequest;
@class JDChemicalRequestContract;
@class JDResponse;

#import "JDReferenceChemical.h"

@interface JDChemicalRequests : NSObject

/**
 * Fetches a list of all chemicals from the webservice with a specific request contract.
 * @param contract A {@link JDChemicalRequestContract} containing the request specifications.
 * @param completionBlock The completion block.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)fetchChemicalsWithContract:(JDChemicalRequestContract *_Nonnull)contract
                      completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDReferenceChemical *> *_Nullable,
                                                                    NSError *_Nullable,
                                                                    JDResponse *_Nullable))completionBlock;

/**
 * Creates a new chemical.
 *
 * @param chemical The reference chemical data model containing the data for the creation.
 * @param organizationId The organization identifier.
 * @param completionBlock Is called after the request execution has been finished.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)createChemical:(JDReferenceChemical *_Nonnull)chemical
                       organizationId:(NSString *_Nonnull)organizationId
                      completionBlock:
                          (void (^_Nonnull)(NSDictionary *_Nullable response, NSError *_Nullable error))completionBlock;

/**
 * Updates a new chemical.
 *
 * @param chemical The reference chemical data model containing the data for the update.
 * @param organizationId The organization identifier.
 * @param completionBlock Is called after the request execution has been finished.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)updateChemical:(JDReferenceChemical *_Nonnull)chemical
                       organizationId:(NSString *_Nonnull)organizationId
                      completionBlock:
                          (void (^_Nonnull)(NSDictionary *_Nullable response, NSError *_Nullable error))completionBlock;

@end