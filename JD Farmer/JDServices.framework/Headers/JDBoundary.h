//
//  JDBoundary.h
//  JDServices
//
//  Created by Patrick Haaser on 2014-11-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDExtent;
@class JDSimpleUnitValue;
@class JDMultipolygon;
@class JDLocation;

/**
 * @brief Boundary information of a {@link JDLocation}.
 */
@interface JDBoundary : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *area;
@property(nonatomic, strong, nullable) JDExtent *extent;
@property(nonatomic, strong, nullable) NSArray<JDMultipolygon *> *multipolygons;
@property(nonatomic, copy, nullable) NSDate *modifiedTime;
@property(nonatomic, assign) BOOL active;
@property(nonatomic, assign) BOOL irrigated;
@property(nonatomic, copy, nullable) NSString *sourceType;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *workableArea;

#pragma mark Transient Properties
@property(nonatomic, copy, nullable) NSString *uniqueId;
@property(nonatomic, copy, nullable) NSString *orgId;

@end
