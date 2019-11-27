//
//  JDEquipmentColor.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-08-07
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

/**
 * @brief Equipment Color for {@link JDEquipmentMake} and {@link JDEquipmentModel}.
 */
@interface JDEquipmentColor : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *equipmentMake;
@property(nonatomic, copy, nullable) NSString *equipmentModel;
@property(nonatomic, copy, nullable) NSString *primaryColor;
@property(nonatomic, copy, nullable) NSString *secondaryColor;
@property(nonatomic, copy, nullable) NSString *stripeColor;
@property(nonatomic, assign) BOOL defaultColors;

@end
