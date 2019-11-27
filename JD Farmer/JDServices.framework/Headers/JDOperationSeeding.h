//
//  JDOperationSeeding.h
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

#import "JDOperation.h"

@class JDCropType;
@class JDSeedAssignment;
@class JDPrescriptionAssignment;

/**
 * @brief Seeding Operation.
 */
@interface JDOperationSeeding : JDOperation

- (instancetype _Nonnull)initWithGenericOperation:(JDOperation *_Nonnull)operation;

@property(nonatomic, strong, nullable) JDCropType *cropType;
@property(nonatomic, strong, nullable) NSArray<JDSeedAssignment *> *seedAssignments;
@property(nonatomic, strong, nullable) NSArray<JDPrescriptionAssignment *> *prescriptionAssignments;
@property(nonatomic, copy, nullable) NSString *shapeFileName;

@end
