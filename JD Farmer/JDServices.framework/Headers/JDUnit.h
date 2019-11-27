//
//  JDUnit.h
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

#import "JDAPIBaseObject.h"

/**
 * @brief Unit of Measurement of a {@link JDVariableRepresentation}.
 */
@interface JDUnit : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *label;
@property(nonatomic, assign) BOOL isDefault;
@property(nonatomic, copy, nullable) NSString *unitOfMeasure;
@property(nonatomic, assign) double minimumValue;
@property(nonatomic, assign) double maximumValue;
@property(nonatomic, copy, nullable) NSString *decimal;
@property(nonatomic, copy, nullable) NSString *digits;

@end
