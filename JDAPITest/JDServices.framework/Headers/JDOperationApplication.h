//
//  JDOperationApplication.h
//  JDServices
//
//  Created by Sebastian Bott on 2014-11-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDOperation.h"

@class JDProductAssignment;
@class JDPrescriptionAssignment;

/**
 * @brief Application Operation.
 */
@interface JDOperationApplication : JDOperation

- (instancetype _Nonnull)initWithGenericOperation:(JDOperation *_Nonnull)operation;

@property(nonatomic, strong, nullable) NSArray<JDProductAssignment *> *productAssignments;
@property(nonatomic, strong, nullable) NSArray<JDPrescriptionAssignment *> *prescriptionAssignments;
@property(nonatomic, assign) BOOL tankMix;

@end
