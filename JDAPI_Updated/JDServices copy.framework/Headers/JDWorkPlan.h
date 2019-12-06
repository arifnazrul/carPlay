//
//  JDWorkPlan.h
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

@class JDSimpleUnitValue;
@class JDWorkAssignment;
@class JDOperation;
@class JDWorkQuestionAssignment;

/**
 * @brief Work Plan for a {@link JDJob}.
 */
@interface JDWorkPlan : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *comments;
@property(nonatomic, assign) long long priority;
@property(nonatomic, copy, nullable) NSDate *plannedStartDate;
@property(nonatomic, copy, nullable) NSDate *plannedEndDate;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *plannedArea;
@property(nonatomic, strong, nullable) NSArray<JDWorkAssignment *> *workAssignments;
@property(nonatomic, strong, nullable) NSArray<JDOperation *> *operations;
@property(nonatomic, strong, nullable) NSArray<JDWorkQuestionAssignment *> *workQuestionAssignments;

@end
