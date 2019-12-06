//
//  JDOperationHarvest.h
//  JDServices
//
//  Created by Sebastian Bott on 2015-05-07
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDOperation.h"

@class JDSimpleIdentName;
@class JDCropType;
@class JDHarvestAssignment;

/**
 * @brief Harvest Operation.
 */
@interface JDOperationHarvest : JDOperation

- (instancetype _Nonnull)initWithGenericOperation:(JDOperation *_Nonnull)operation;

@property(nonatomic, strong, nullable) JDCropType *cropType;
@property(nonatomic, strong, nullable) NSArray<JDHarvestAssignment *> *harvestAssignments;


@end
