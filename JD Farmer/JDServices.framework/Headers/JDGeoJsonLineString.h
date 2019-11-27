//
//  JDGeoJsonLineString.h
//  JDServices
//
//  Created by Thielen Andrew P on 2/12/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDGeoJsonGeometry.h"
#import "JDGeoJsonPosition.h"

@interface JDGeoJsonLineString : JDGeoJsonGeometry <RawPositionList *>

@property(nonatomic, readonly, nonnull) NSArray<JDGeoJsonPosition *> *points;

- (nullable instancetype)initWithPoints:(nonnull NSArray<JDGeoJsonPosition *> *)points;
- (BOOL)isLinearRing;

- (BOOL)isEqualToLineString:(nullable JDGeoJsonLineString *)lineString;

@end
