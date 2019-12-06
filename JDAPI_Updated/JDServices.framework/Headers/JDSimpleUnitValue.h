//
//  JDSimpleUnitValue.h
//  JDServices
//
//  Created by Sebastian Bott on 2014-11-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <objc/NSObject.h>
#import "JDJsonObject.h"
#import "JDAPIBaseObject.h"

/**
 * @brief Container for entity with unit and value.
 */
@interface JDSimpleUnitValue : JDAPIBaseObject <JDAPIPostBody, NSCoding>

@property(nonatomic, copy, nullable) NSString *unit;
@property(nonatomic, copy, nullable) NSDecimalNumber *valueAsNumber;
@property(nonatomic, copy, nullable) NSString *vrDomainId;

- (void)setValueAsDouble:(double)value;

- (void)setValueAsInteger:(NSInteger)value;

- (void)setValueAsString:(nonnull NSString *)value;

- (nullable NSString *)valueAsString;

/**
 * @brief Creates a dictionary representation of the object.
 * @param usesDoubleValue if YES the value in the dictionary representation is represented by the key valueAsDouble
 * otherwise it's represented by the key valueAsString.
 */
- (NSDictionary *_Nonnull)createPostBodyUsingDoubleValue:(BOOL)usesDoubleValue;

@end
