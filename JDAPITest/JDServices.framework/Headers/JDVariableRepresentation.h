//
//  JDVariableRepresentation.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-08-08
//
//  Unpublished Work (c) 2017 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDUnit;

#import "JDAPIBaseObject.h"

/**
 * @brief Variable Representation Description.
 */
@interface JDVariableRepresentation : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *objectDescription;
@property(nonatomic, copy, nullable) NSString *unitOfMeasurementSystem;
@property(nonatomic, copy, nullable) NSString *unitType;
@property(nonatomic, assign) BOOL useThousandsSeparator;
@property(nonatomic, copy, nullable) NSString *decimal;
@property(nonatomic, copy, nullable) NSString *digits;
@property(nonatomic, copy, nullable) NSArray<JDUnit *> *units;

@end
