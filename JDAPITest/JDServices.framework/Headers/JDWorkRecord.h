//
//  JDWorkRecord.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-12-01
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDMachine;
@class JDUser;
@class JDWorkOrder;
@class JDWorkAssignment;
@class JDWorkAnswer;
@class JDStatusUpdate;

/**
 * @brief Work Record.
 */
@interface JDWorkRecord : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *status;
@property(nonatomic, copy, nullable) NSDate *startDate;
@property(nonatomic, copy, nullable) NSDate *endDate;
@property(nonatomic, strong, nullable) JDUser *operator;
@property(nonatomic, strong, nullable) JDMachine *machine;
@property(nonatomic, strong, nullable) JDWorkAssignment *workAssignment;
@property(nonatomic, strong, nullable) JDWorkOrder *workOrder;
@property(nonatomic, strong, nullable) NSArray<JDWorkAnswer *> *workAnswers;
@property(nonatomic, strong, nullable) NSArray<JDStatusUpdate *> *statusUpdates;

@end
