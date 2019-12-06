//
//  JDGeoJsonPolygon.h
//  JDServices
//
//  Created by Thielen Andrew P on 2/12/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDGeoJsonGeometry.h"
#import "JDGeoJsonLineString.h"

@interface JDGeoJsonPolygon : JDGeoJsonGeometry <RawLineList *>

- (nullable instancetype)initWithLinearRings:(nonnull NSArray<JDGeoJsonLineString *> *)linearRings;

- (BOOL)isEqualToPolygon:(nullable JDGeoJsonPolygon *)polygon;

@property(nonatomic, readonly, nonnull) NSArray<JDGeoJsonLineString *> *linearRings;

@end
