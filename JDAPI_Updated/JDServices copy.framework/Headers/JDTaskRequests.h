//
//  JDTaskRequests.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-12-05
//
//  Unpublished Work (c) 2017 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDRequest.h"
@class JDTask;
@class JDResponse;

/**
 * @brief API requests for {@link JDTask}.
 * @author Bott Sebastian
 */
@interface JDTaskRequests : NSObject

/**
 * Fetches a list of all tasks from the webservice with the default configuration.
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchTasksWithOrganizationId:(NSString *_Nonnull)organizationId
                        completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDTask *> *_Nullable tasks,
                                                                      NSError *_Nullable error,
                                                                      JDResponse *_Nullable response))completionBlock;

/**
 * Fetches a list of all tasks from the webservice.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchTasksWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                    organizationId:(NSString *_Nonnull)organizationId
                       completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDTask *> *_Nullable tasks,
                                                                     NSError *_Nullable error,
                                                                     JDResponse *_Nullable response))completionBlock;

@end
