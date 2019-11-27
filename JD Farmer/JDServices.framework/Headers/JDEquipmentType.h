//
//  JDEquipmentType.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-05-23
//
//  Unpublished Work (c) 2014-2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDJsonObject.h"
#import "JDAPIBaseObject.h"

/**
 * @brief Equipment Type for {@link JDMachine} and {@link JDImplement}.
 */
@interface JDEquipmentType : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *guid;
@property(nonatomic, copy, nullable) NSString *category;
@property(nonatomic, copy, nullable) NSString *marketSegment;
@property(nonatomic, assign) BOOL certified;

@end
