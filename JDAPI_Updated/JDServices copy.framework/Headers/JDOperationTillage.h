//
//  JDOperationTillage.m
//  JDServices
//
//  Created by Sebastian Bott on 2015-08-05
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDOperation.h"

@class JDCropType;
@class JDSimpleUnitValue;
@class JDTillageType;

/**
 * @brief Tillage Operation.
 */
@interface JDOperationTillage : JDOperation

- (instancetype _Nonnull)initWithGenericOperation:(JDOperation *_Nonnull)operation;

@property(nonatomic, strong, nullable) JDSimpleUnitValue *depth;
@property(nonatomic, strong, nullable) JDTillageType *tillageType;


@end
