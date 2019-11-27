//
//  JDWorkOrder.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-11-18
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDLocation;
@class JDWorkRecord;
@class JDMeasurementTotal;
@class JDWorkPlan;
@class JDWorkAssignment;
@class JDGuidanceLine;

/**
 * @brief Work Order for a {@link JDJob}.
 */
@interface JDWorkOrder : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, assign) long long priority;
@property(nonatomic, copy, nullable) NSString *status;
@property(nonatomic, copy, nullable) NSDate *startDate;
@property(nonatomic, copy, nullable) NSDate *endDate;
@property(nonatomic, strong, nullable) JDLocation *location;
@property(nonatomic, strong, nullable) NSArray<JDGuidanceLine *> *guidanceLines;
@property(nonatomic, strong, nullable) NSArray<JDWorkAssignment *> *workAssignments;
@property(nonatomic, strong, nullable) NSArray<JDWorkRecord *> *workRecords;
@property(nonatomic, strong, nullable) NSArray<JDMeasurementTotal *> *measurementTotals;

/**
 * Returns the POST body to create or update a job.
 * @param organizationId The id of the organization
 * @return The POST body dictionary
 */
- (NSDictionary *_Nonnull)createPostBodyWithOrganizationId:(NSString *_Nonnull)organizationId;

@end
