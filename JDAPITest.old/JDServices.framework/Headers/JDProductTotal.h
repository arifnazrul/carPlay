//
//  JDProductTotal.h
//  JDServices
//
//  Created by Thielen Andrew P on 12/12/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDJsonObject.h"
#import "JDSimpleUnitValue.h"

@interface JDProductTotal : NSObject <JDJsonObject, NSCoding>

@property(nonatomic) NSString *name;
@property(nonatomic) BOOL carrier;
@property(nonatomic) JDSimpleUnitValue *totalMaterial;
@property(nonatomic) JDSimpleUnitValue *averageMaterial;

@end
