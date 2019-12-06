//
//  JDMachineStylePreferences.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-08-09
//
//  Unpublished Work (c) 2017 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import "JDJsonObject.h"

@class JDEquipmentColor;

/**
 * @brief Machine Style Preferences for {@link JDMachine} and {@link JDImplement}
 */
@interface JDMachineStylePreferences : JDAPIBaseObject

@property(nonatomic, strong, nullable) JDEquipmentColor *deereAgDefault;
@property(nonatomic, strong, nullable) JDEquipmentColor *deereCFDefault;
@property(nonatomic, strong, nullable) JDEquipmentColor *competitiveDefault;
@property(nonatomic, strong, nullable) NSArray<JDEquipmentColor *> *customColors;

@end
