//
//  JDVarietyTotal.h
//  JDServices
//
//  Created by Thielen Andrew P on 12/12/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDJsonObject.h"
#import "JDSimpleUnitValue.h"

@interface JDVarietyTotal : NSObject <JDJsonObject, NSCoding>

@property(nonatomic) NSString *name;
@property(nonatomic) JDSimpleUnitValue *area;
@property(nonatomic) JDSimpleUnitValue *yield;
@property(nonatomic) JDSimpleUnitValue *averageYield;
@property(nonatomic) JDSimpleUnitValue *averageMoisture;
@property(nonatomic) JDSimpleUnitValue *wetMass;
@property(nonatomic) JDSimpleUnitValue *averageWetMass;
@property(nonatomic) JDSimpleUnitValue *totalMaterial;
@property(nonatomic) JDSimpleUnitValue *averageMaterial;

@end
