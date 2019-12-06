//
//  JDWorkAnswerRequests.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-04-19
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDRequest;
@class JDWorkAnswer;

/**
 * @brief API requests for {@link JDWorkAnswerRequests}
 * @author Bott Sebastian
 */
@interface JDWorkAnswerRequests : NSObject

/**
* Creates or updates a work answer with the given payload.
* @param workAnswer The work answer
* @param jobId The job for which the workAnswer is created
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)createOrUpdateWorkAnswer:(JDWorkAnswer *_Nonnull)workAnswer
                                          jobId:(NSString *_Nonnull)jobId
                               workAssignmentId:(NSString *_Nonnull)workAssignmentId
                                completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                                  NSError *_Nullable error))completionBlock;

/**
* Creates or updates a work answer with the given payload.
* @param workAnswer The work answer
* @param workOrderId The job for which the workAnswer is created
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)createOrUpdateWorkAnswer:(JDWorkAnswer *_Nonnull)workAnswer
                                    workOrderId:(NSString *_Nonnull)workOrderId
                               workAssignmentId:(NSString *_Nonnull)workAssignmentId
                                completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                                  NSError *_Nullable error))completionBlock;

/**
* Deletes the work answer for the provided id.
* @param workAnswerId The work answer id
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)deleteWorkAnswer:(NSString *_Nonnull)workAnswerId
                        completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                          NSError *_Nullable error))completionBlock;

@end
