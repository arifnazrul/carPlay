//
//  JDPoint.h
//  JDServices
//
//  Created by Sebastian Bott on 2014-12-11
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDSimpleUnitValue;

/**
 * @brief Coordinate point for {@link JDMultipolygon}.
 */
@interface JDPoint : JDAPIBaseObject <JDAPIPostBody, NSCoding>

@property(nonatomic, assign) double latitude;
@property(nonatomic, assign) double longitude;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *altitude;

- (instancetype _Nonnull)initWithLatitude:(double)latitude longitude:(double)longitude;

@end
