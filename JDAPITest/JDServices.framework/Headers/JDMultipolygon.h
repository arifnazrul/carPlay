//
//  JDMultipolygon.h
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

extern NSString *_Nonnull const kJDMultipolygonExterior;
extern NSString *_Nonnull const kJDMultipolygonInterior;

@class JDMultipolygonRings;
@class JDPoint;

/**
 * @brief Polygon with multiple {@link JDMultipolygonRings} for {@link JDBoundary}.
 */
@interface JDMultipolygon : JDAPIBaseObject <NSCoding>

@property(nonatomic, strong, nullable) NSArray<JDMultipolygonRings *> *rings;

@end


/**
 * @brief Polygon ring for @{@link JDMultipolygon}.
 */
@interface JDMultipolygonRings : JDAPIBaseObject <NSCoding>

@property(nonatomic, strong, nullable) NSArray<JDPoint *> *points;
@property(nonatomic, copy, nullable) NSString *type;

- (BOOL)isExteriorRing;

@end
