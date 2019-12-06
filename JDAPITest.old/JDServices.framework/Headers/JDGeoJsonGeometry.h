//
//  JDGeoJsonGeometry.h
//  JDServices
//
//  Created by Thielen Andrew P on 2/12/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDJsonObject.h"

typedef NS_ENUM(NSUInteger, JDGeoJsonGeometryType) {
    JDGeoJsonGeometryTypeUnknown = 0,
    JDGeoJsonGeometryTypePoint = 1,
    JDGeoJsonGeometryTypeLineString = 2,
    JDGeoJsonGeometryTypePolygon = 3
};

typedef NSArray<NSNumber *> RawPosition;
typedef NSArray<NSArray<NSNumber *> *> RawPositionList;
typedef NSArray<NSArray<NSArray<NSNumber *> *> *> RawLineList;

//"Abstract" Geometry class. Do NOT instantiate base class
@interface JDGeoJsonGeometry <RawCoordinatesStructure> : NSObject

- (nullable instancetype)initWithGeoJsonCoordinateArray:(nonnull RawCoordinatesStructure)coordinates;

@property(nonatomic, readonly) JDGeoJsonGeometryType type;
@property(nonatomic, readonly, nonnull) RawCoordinatesStructure coordinatesGeoJson;

- (nonnull NSDictionary *)toGeoJson;
+ (nonnull NSString *)stringForType:(enum JDGeoJsonGeometryType)type;
+ (enum JDGeoJsonGeometryType)typeForString:(nonnull NSString *)type;

- (BOOL)isEqualToGeometry:(nullable JDGeoJsonGeometry *)geometry;

@end
