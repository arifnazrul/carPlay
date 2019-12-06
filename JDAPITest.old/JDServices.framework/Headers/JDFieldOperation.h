//
//  JDFieldOperation.h
//  JDServices
//
//  Created by Wright Daniel W on 12/12/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import "JDClient.h"
#import "JDFarm.h"
#import "JDField.h"
#import "JDFieldOperationMachine.h"
#import "JDFieldOperationMeasurement.h"
#import "JDFieldOperationProduct.h"
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, JDFieldOperationType) {
    JDFieldOperationTypeUnknown,
    JDFieldOperationTypeHarvest,
    JDFieldOperationTypeSeeding,
    JDFieldOperationTypeTillage,
    JDFieldOperationTypeApplication
};

@interface JDFieldOperation : JDAPIBaseObject

@property(nonatomic) NSString *ident;
@property(nonatomic) NSString *cropSeason;
@property(nonatomic) NSString *cropName;
@property(nonatomic) JDFieldOperationType fieldOperationType;
@property(nonatomic) JDClient *client;
@property(nonatomic) JDFarm *farm;
@property(nonatomic) JDField *field;
@property(nonatomic) JDFieldOperationProduct *product;
@property(nonatomic) NSDate *startDate;
@property(nonatomic) NSDate *endDate;
@property(nonatomic) NSArray<JDFieldOperationMachine *> *fieldOperationMachines;
@property(nonatomic) NSArray<JDFieldOperationMeasurement *> *measurementTypes;

@end
