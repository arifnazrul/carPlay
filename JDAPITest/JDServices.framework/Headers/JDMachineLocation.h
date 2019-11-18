//
//  JDMachineLocation.h
//  JDServices
//
//  Created by Dewein Rico on 2016-03-04
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDPoint;
@class JDSimpleUnitValue;

/**
 * @brief Location of a {@link JDMachine}.
 */
DEPRECATED_ATTRIBUTE
@interface JDMachineLocation : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *guid DEPRECATED_ATTRIBUTE;
@property(nonatomic, copy, nullable) NSString *origin DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) JDPoint *point DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) NSDate *eventTimeStamp DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) NSDate *createTimeStamp DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *speed DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *heading DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *fuelLevel DEPRECATED_ATTRIBUTE;

@end
