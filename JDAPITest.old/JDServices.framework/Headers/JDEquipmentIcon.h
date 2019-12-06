//
//  JDEquipmentIcon.h
//  JDServices
//
//  Created by Bott Sebastian on 2019-03-20
//
//  Unpublished Work (c) 2019 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDIconStyle.h"

/**
 * @brief Equipment Icon for {@link JDMachine} and {@link JDImplement}.
 */
@interface JDEquipmentIcon : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, strong, nullable) JDIconStyle *iconStyle;

@end
