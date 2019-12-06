//
//  JDMachine.h
//  JDServices
//
//  Created by Hack Marco on 2014-11-14
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import <Foundation/Foundation.h>

@class JDSimpleIdentName;
@class JDEquipmentType;
@class JDTerminal;
@class JDEquipmentModel;
@class JDEquipmentApexType;
@class JDDisplay;
@class JDBreadcrumb;
@class JDEquipmentIcon;
@class JDIconStyle;

/**
 * @brief Operation Center Machine.
 */
@interface JDMachine : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *visualizationCategory;
@property(nonatomic, copy, nullable) NSString *guid;
@property(nonatomic, copy, nullable) NSString *modelYear;
@property(nonatomic, copy, nullable) NSString *vin;
@property(nonatomic, copy, nullable) NSString *telematicsState;
@property(nonatomic, copy, nullable) NSString *productKey;
@property(nonatomic, strong, nullable) JDSimpleIdentName *category;
@property(nonatomic, strong, nullable) JDSimpleIdentName *make;
@property(nonatomic, strong, nullable) JDSimpleIdentName *model;
@property(nonatomic, strong, nullable) JDBreadcrumb *currentLocation;
@property(nonatomic, strong, nullable) NSArray<JDTerminal *> *terminals;
@property(nonatomic, strong, nullable) NSArray<JDDisplay *> *displays;
@property(nonatomic, strong, nullable) JDSimpleIdentName *equipmentMake;
@property(nonatomic, strong, nullable) JDEquipmentType *equipmentType;
@property(nonatomic, strong, nullable) JDEquipmentApexType *equipmentApexType;
@property(nonatomic, strong, nullable) JDEquipmentModel *equipmentModel;
@property(nonatomic, strong, nullable) JDEquipmentIcon *icon;

@property(nonatomic, copy, nullable) NSString *machineId DEPRECATED_ATTRIBUTE;

@end
