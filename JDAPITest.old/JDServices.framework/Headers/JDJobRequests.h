//
//  JDJobRequests.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-07-07
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDRequestConfiguration.h"
#import "JDRequest.h"

typedef NS_OPTIONS(NSUInteger, JDJobEmbedOptions) {
    JDJobEmbedNone = 0,

    JDJobEmbedJobNotes = 1 << 0,
    JDJobEmbedMeasurementTotals = 1 << 1,
    JDJobEmbedWorkOrders = 1 << 2,
    JDJobEmbedWorkPlan = 1 << 3,
    JDJobEmbedWorkRecords = 1 << 4,

    JDJobEmbedWorkOrderGuidanceLines = 1 << 5,
    JDJobEmbedWorkOrderLocation = 1 << 6,
    JDJobEmbedWorkOrderMeasurementTotals = 1 << 7,
    JDJobEmbedWorkOrderWorkRecords = 1 << 8,

    JDJobEmbedWorkPlanOperations = 1 << 9,
    JDJobEmbedWorkPlanWorkAssignments = 1 << 10,
    JDJobEmbedWorkPlanWorkQuestionAssignments = 1 << 11,

    JDJobEmbedWorkPlanWorkAssignmentImplements = 1 << 12,
    JDJobEmbedWorkPlanWorkAssignmentMachine = 1 << 13,
    JDJobEmbedWorkPlanWorkAssignmentUser = 1 << 14,

    JDJobEmbedWorkQuestionAssignmentWorkQuestion = 1 << 15,
    JDJobEmbedWorkRecordWorkAnswers = 1 << 16,
    JDJobEmbedWorkPlanWorkAssignmentWorkRecordWorkAnswer = 1 << 17,
    JDJobEmbedWorkPlanWorkAssignmentWorkRecordStatusUpdates = 1 << 18
};

@class JDJob;
@class JDResponse;
@class JDReorderContainer;

/**
 * @brief API requests for {@link JDJob}.
 */
@interface JDJobRequests : NSObject <JDRequestEmbed>

#pragma mark - GET Requests

/**
* Fetches a list of jobs as well as the machine schedule from the webservice with the default request configuration.
* Both are required to generate the UI data (prioritized list of jobs grouped by machines).
* @param organizationId The id of the organization
* @param date The date
* @param embedOptions The {@link JDJobEmbedOptions} which should be embedded in the response (bitmask)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchJobsForOrganizationId:(NSString *_Nonnull)organizationId
                             excludeCompleteOlder:(NSDate *_Nonnull)date
                                     embedOptions:(JDJobEmbedOptions)embedOptions
                      completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDJob *> *_Nullable, NSError *_Nullable,
                                                                    JDResponse *_Nullable))completionBlock;

/**
* Fetches a list of jobs as well as the machine schedule from the webservice.
* Both are required to generate the UI data (prioritized list of jobs grouped by machines).
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param organizationId The id of the organization
* @param date The date
* @param embedOptions The {@link JDJobEmbedOptions} which should be embedded in the response (bitmask)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchJobsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                   organizationId:(NSString *_Nonnull)organizationId
                             excludeCompleteOlder:(NSDate *_Nonnull)date
                                     embedOptions:(JDJobEmbedOptions)embedOptions
                      completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDJob *> *_Nullable, NSError *_Nullable,
                                                                    JDResponse *_Nullable))completionBlock;

/**
* Fetches a single job from the webservice.
* @param jobId The id of the job
* @param embedOptions The {@link JDJobEmbedOptions} which should be embedded in the response (bitmask)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchJobWithJobId:(NSString *_Nonnull)jobId
                            embedOptions:(JDJobEmbedOptions)embedOptions
             completionBlockWithResponse:
                 (void (^_Nonnull)(JDJob *_Nullable, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
* Fetches a single job from the webservice.
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param jobId The id of the job
* @param embedOptions The {@link JDJobEmbedOptions} which should be embedded in the response (bitmask)
* @param completionBlock The completion block
*/
+ (JDRequest *_Nonnull)fetchJobWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                           jobId:(NSString *_Nonnull)jobId
                                    embedOptions:(JDJobEmbedOptions)embedOptions
                     completionBlockWithResponse:
                         (void (^_Nonnull)(JDJob *_Nullable, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

#pragma mark - PUT, POST, DELETE Requests

/**
* Creates or updates a job with the given payload.
* @param job The job
* @param organizationId The id of the organization
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)createOrUpdateJob:(JDJob *_Nonnull)job
                          organizationId:(NSString *_Nonnull)organizationId
                                clientId:(NSString *_Nullable)clientId
                         completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                           NSError *_Nullable error))completionBlock;

/**
* Creates or updates a job with the given payload.
* @param job The job
* @param organizationId The id of the organization
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)createOrUpdateJob:(JDJob *_Nonnull)job
                          organizationId:(NSString *_Nonnull)organizationId
                                clientId:(NSString *_Nullable)clientId
                                  taskId:(NSString *_Nullable)taskId
                         completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                           NSError *_Nullable error))completionBlock;

/**
* Deletes a job with the given ident.
* @param jobId The job ident
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)deleteJobWithId:(NSString *_Nonnull)jobId
                       completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                         NSError *_Nullable error))completionBlock;

/**
 * Reorder a job.
 * @param organizationId The id of the organization.
 * @param reorderContainer A array of reorder container.
 * @param completionBlock The block is called after the request completes.
 */
+ (JDRequest *_Nonnull)reorderJobForOrganizationId:(NSString *_Nonnull)organizationId
                                 reorderContainers:(NSArray<JDReorderContainer *> *_Nonnull)reorderContainers
                                   completionBlock:
                                       (void (^_Nonnull)(id _Nullable result, NSError *_Nullable error))completionBlock;

#pragma mark - Deprecated
/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchJobsForOrganizationId:(NSString *_Nonnull)organizationId
                             excludeCompleteOlder:(NSDate *_Nonnull)date
                                  completionBlock:(void (^_Nonnull)(NSArray<JDJob *> *_Nullable jobs,
                                                                    NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchJobsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                   organizationId:(NSString *_Nonnull)organizationId
                             excludeCompleteOlder:(NSDate *_Nonnull)date
                                  completionBlock:(void (^_Nonnull)(NSArray<JDJob *> *_Nullable jobs,
                                                                    NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchJobWithJobId:(NSString *_Nonnull)jobId
                         completionBlock:
                             (void (^_Nonnull)(JDJob *_Nullable job, NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchJobWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                           jobId:(NSString *_Nonnull)jobId
                                 completionBlock:
                                     (void (^_Nonnull)(JDJob *_Nullable job, NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
* @deprecated
* Creates a new job with the given data.
* @param job The job
* @param organizationId The id of the organization
* @param cropYear The crop year
* @param note The note aka additional instructions
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)postCreateJob:(JDJob *_Nonnull)job
                      organizationId:(NSString *_Nonnull)organizationId
                            cropYear:(NSString *_Nonnull)cropYear
                                note:(NSString *_Nonnull)note
                     completionBlock:(void (^_Nonnull)(NSString *_Nullable result,
                                                       NSError *_Nullable error))completionBlock DEPRECATED_ATTRIBUTE;

/**
* @deprecated Use {@link JDStatusUpdateRequests} #updateStatusForJobId:(NSString *)jobId
                                                                status:(NSString *)status
                                                          recordedDate:(NSDate *)recordedDate
                                                      workAssignmentId:(NSString *)workAssignmentId
                                                      sourceIdentifier:(NSString *)sourceIdentifier
                                                       completionBlock:(void (^)(NSDictionary * response,
                                                                                    NSError * error))completionBlock;
* Updates the status of a job or work assignment.
* @param ident The ident
* @param newStatus The new status
* @param isAssigned <code>YES</code>If a work assignment is assigned, otherwise <code>NO</code>
* @param sourceIdentifier The name of the source identifier
* @param dateCreated The date of the status change
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)updateStatusForJobOrWorkAssignmentId:(NSString *_Nonnull)ident
                                                  newStatus:(NSString *_Nonnull)newStatus
                                                   assigned:(BOOL)isAssigned
                                           sourceIdentifier:(NSString *_Nonnull)sourceIdentifier
                                                dateCreated:(NSDate *_Nonnull)dateCreated
                                            completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                                              NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
