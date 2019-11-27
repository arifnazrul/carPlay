//
//  JDStatusUpdateRequests.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-04-20
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

static const int kLocalErrorCodeIdentOrStatusNil = 10001;
extern NSString *_Nonnull const kJDUrlActionStatusChange;

@class JDRequest;

/**
 * @brief API requests for {@link JDStatusUpdate}.
 * @author Bott Sebastian
 */
@interface JDStatusUpdateRequests : NSObject

/**
* Updates the status of a {@link JDJob}.
* @param jobId The ident of the corresponding job
* @param status The new status
* @param recordedDate The date of the status update
* @param workAssignmentId The ident of the work assignment
* @param sourceIdentifier The name of the source application
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)updateStatusForJobId:(NSString *_Nonnull)jobId
                                     status:(NSString *_Nonnull)status
                               recordedDate:(NSDate *_Nonnull)recordedDate
                           workAssignmentId:(NSString *_Nullable)workAssignmentId
                           sourceIdentifier:(NSString *_Nonnull)sourceIdentifier
                            completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                              NSError *_Nullable error))completionBlock;

/**
* Updates the status of a {@link JDJob}.
* @param jobId The ident of the corresponding job
* @param status The new status
* @param recordedDate The date of the status update
* @param machineId The ident of the machine
* @param userAccountName The user account name of the operator
* @param sourceIdentifier The name of the source application
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)updateStatusForJobId:(NSString *_Nonnull)jobId
                                     status:(NSString *_Nonnull)status
                               recordedDate:(NSDate *_Nonnull)recordedDate
                                  machineId:(NSString *_Nullable)machineId
                            userAccountName:(NSString *_Nullable)userAccountName
                           sourceIdentifier:(NSString *_Nonnull)sourceIdentifier
                            completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                              NSError *_Nullable error))completionBlock;

/**
* Updates the status of a {@link JDWorkOrder}.
* @param jobId The ident of the corresponding job
* @param status The new status
* @param recordedDate The date of the status update
* @param sourceIdentifier The name of the source application
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)updateStatusForWorkOrderId:(NSString *_Nonnull)jobId
                                           status:(NSString *_Nonnull)status
                                     recordedDate:(NSDate *_Nonnull)recordedDate
                                 sourceIdentifier:(NSString *_Nonnull)sourceIdentifier
                                  completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                                    NSError *_Nullable error))completionBlock;

@end
