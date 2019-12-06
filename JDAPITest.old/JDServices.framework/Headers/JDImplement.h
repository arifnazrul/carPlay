//
//  JDImplement.h
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

#import "JDAPIBaseObject.h"

@class JDSimpleIdentName;
@class JDEquipmentType;
@class JDEquipmentModel;
@class JDEquipmentApexType;
@class JDEquipmentIcon;
@class JDIconStyle;

/**
 * @brief Machine Implement.
 */

@interface JDImplement : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *guid;
@property(nonatomic, copy, nullable) NSString *vin;
@property(nonatomic, strong, nullable) JDSimpleIdentName *category;
@property(nonatomic, strong, nullable) JDSimpleIdentName *make;
@property(nonatomic, strong, nullable) JDSimpleIdentName *model;
@property(nonatomic, strong, nullable) JDSimpleIdentName *equipmentMake;
@property(nonatomic, strong, nullable) JDEquipmentType *equipmentType;
@property(nonatomic, strong, nullable) JDEquipmentApexType *equipmentApexType;
@property(nonatomic, strong, nullable) JDEquipmentModel *equipmentModel;
@property(nonatomic, strong, nullable) JDEquipmentIcon *icon;

@end
