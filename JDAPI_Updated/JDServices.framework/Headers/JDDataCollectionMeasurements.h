//
//  JDDataCollectionMeasurements.h
//  JDServices
//
//  Created by Gillispie Leah on 10/5/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import "JDDataCollectionMeasurement.h"
#import "JDJsonObject.h"
#import "JDServicesConstants.h"
#import <Foundation/Foundation.h>

@interface JDDataCollectionMeasurements : JDAPIBaseObject

@property(nonatomic) NSDate *eventTime;

@property(nonatomic) JDDataCollectionMeasurement *latitude;

@property(nonatomic) JDDataCollectionMeasurement *longitude;

@property(nonatomic) NSArray<JDDataCollectionMeasurement *> *measurementSnapshots;

- (JDDataCollectionMeasurement *)getMeasurementForDomainTag:(JDDataCollectionMeasurementDomainTag)domainTag;

@end
