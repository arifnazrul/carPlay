//
//  JDJob.h
//  JDServices
//
//  Created by Patrick Haaser on 2014-11-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDLocation;
@class JDWorkAssignment;
@class JDOperation;
@class JDNote;
@class JDSimpleIdentName;
@class JDWorkPlan;
@class JDWorkOrder;
@class JDWorkRecord;
@class JDMeasurementTotal;

extern NSString *_Nonnull const kStatusCompleted;
extern NSString *_Nonnull const kStatusPlanned;
extern NSString *_Nonnull const kStatusStarted;
extern NSString *_Nonnull const kStatusSuspended;

extern NSString *_Nonnull const kJobTypeApplication;
extern NSString *_Nonnull const kJobTypeBaling;
extern NSString *_Nonnull const kJobTypeConditioning;
extern NSString *_Nonnull const kJobTypeHarvest;
extern NSString *_Nonnull const kJobTypeMiscellaneous;
extern NSString *_Nonnull const kJobTypeMowing;
extern NSString *_Nonnull const kJobTypeScouting;
extern NSString *_Nonnull const kJobTypeSeed;
extern NSString *_Nonnull const kJobTypeSoilSampling;
extern NSString *_Nonnull const kJobTypeTillage;
extern NSString *_Nonnull const kJobTypeTransport;
extern NSString *_Nonnull const kJobTypeUnknown;

/**
 * @brief Operation Center Job.
 */
@interface JDJob : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, assign) NSInteger cropYear;
@property(nonatomic, copy, nullable) NSDate *createdDate;
@property(nonatomic, strong, nullable) NSDate *startedDate;
@property(nonatomic, strong, nullable) NSDate *lastModifiedDate;
@property(nonatomic, copy, nullable) NSString *status;
@property(nonatomic, copy, nullable) NSString *type;
@property(nonatomic, copy, nullable) NSString *notes;
@property(nonatomic, strong, nullable) JDWorkPlan *workPlan;
@property(nonatomic, strong, nullable) NSArray<JDWorkOrder *> *workOrders;
@property(nonatomic, strong, nullable) NSArray<JDNote *> *jobNotes;
@property(nonatomic, strong, nullable) NSArray<JDWorkRecord *> *workRecords;
@property(nonatomic, strong, nullable) NSArray<JDMeasurementTotal *> *measurementTotals;

@property(nonatomic, copy, nullable) NSString *jobType DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) JDLocation *location DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) NSArray<JDOperation *> *operations DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) NSArray<JDWorkAssignment *> *workAssignments DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) NSArray<JDSimpleIdentName *> *guidanceLines DEPRECATED_ATTRIBUTE;

/**
 * Returns the POST body to create or update a job.
 * @param organizationId The id of the organization
 * @param clientId The id of the client
 * @return The POST body dictionary
 */
- (NSDictionary *_Nonnull)createPostBodyWithOrganizationId:(NSString *_Nonnull)organizationId
                                                  clientId:(NSString *_Nullable)clientId;

/**
 * Returns the POST body to create or update a job.
 * @param organizationId The id of the organization
 * @param clientId The id of the client
 * @param taskId The id of the task
 * @return The POST body dictionary
 */
- (NSDictionary *_Nonnull)createPostBodyWithOrganizationId:(NSString *_Nonnull)organizationId
                                                  clientId:(NSString *_Nullable)clientId
                                                  taskId:(NSString *_Nullable)taskId;

#pragma mark Deprecated

/**
 * @deprecated
 * Returns the POST body to create a new job.
 * @param job The job
 * @param organizationId The id of the organization
 * @param cropYear The crop year
 * @param note The note
 * @return The POST body dictionary
 */
+ (NSDictionary *_Nonnull)jobPostBodyWithJob:(JDJob *_Nonnull)job
                              organizationId:(NSString *_Nonnull)organizationId
                                    cropYear:(NSString *_Nonnull)cropYear
                                        note:(NSString *_Nonnull)note DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 * Creates an array of JDOperation from a raw dictionary.
 * @param dictionary The dictionary
 * @return An array
 */
+ (NSMutableArray *_Nonnull)createOperationsFromDictionary:(nonnull NSDictionary *)dictionary DEPRECATED_ATTRIBUTE;

@end
