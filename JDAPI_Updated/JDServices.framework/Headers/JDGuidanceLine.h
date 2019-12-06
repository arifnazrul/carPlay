//
//  JDGuidanceLine.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-12-17
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDSimpleIdentName.h"

@class JDSimpleUnitValue, JDPoint;

/**
 * @brief Guidance Line for {@link JDWorOrder}.
 */
@interface JDGuidanceLine : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *type;
@property(nonatomic, copy, nullable) NSString *guid;
@property(nonatomic, assign) BOOL archived;
@property(nonatomic, assign) BOOL locked;
@property(nonatomic, copy, nullable) NSString *saveMethod;
@property(nonatomic, assign) double tramOffset;
@property(nonatomic, assign) double tramSpacing;
@property(nonatomic, assign) double heading;
@property(nonatomic, copy, nullable) NSDate *lastModifiedTime;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *northShift;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *eastShift;
@property(nonatomic, strong, nullable) JDPoint *aPoint;
@property(nonatomic, strong, nullable) JDPoint *bPoint;

@end
