//
//  JDFieldOperationMeasurement.h
//  JDServices
//
//  Created by Wright Daniel W on 12/12/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import "JDProductTotal.h"
#import "JDSimpleUnitValue.h"
#import "JDVarietyTotal.h"
#import <Foundation/Foundation.h>

@interface JDFieldOperationMeasurement : JDAPIBaseObject <NSCoding>

@property(nonatomic) NSString *ident;
@property(nonatomic) NSString *measurementName;
@property(nonatomic) NSString *measurementCategory;
@property(nonatomic) JDSimpleUnitValue *area;
@property(nonatomic) JDSimpleUnitValue *yield;
@property(nonatomic) JDSimpleUnitValue *averageYield;
@property(nonatomic) JDSimpleUnitValue *averageMoisture;
@property(nonatomic) JDSimpleUnitValue *wetMass;
@property(nonatomic) JDSimpleUnitValue *averageWetMass;
@property(nonatomic) JDSimpleUnitValue *averageSpeed;
@property(nonatomic) JDSimpleUnitValue *totalMaterial;
@property(nonatomic) JDSimpleUnitValue *averageMaterial;
@property(nonatomic) JDSimpleUnitValue *singulation;
@property(nonatomic) JDSimpleUnitValue *averageDepth;
@property(nonatomic) JDSimpleUnitValue *averagePressure;
@property(nonatomic) NSArray<JDVarietyTotal *> *varietyTotals;
@property(nonatomic) NSArray<JDProductTotal *> *productTotals;

@end
