//
//  JDEquipmentApexType.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-08-04
//
//  Unpublished Work (c) 2014-2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import "JDJsonObject.h"

/**
 * @brief Equipment Apex Type for {@link JDMachine} and {@link JDImplement}.
 */
@interface JDEquipmentApexType : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *guid;
@property(nonatomic, copy, nullable) NSString *category;

@end
