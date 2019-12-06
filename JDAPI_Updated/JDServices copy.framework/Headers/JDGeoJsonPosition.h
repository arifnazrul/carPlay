//
//  JDGeoJsonPosition.h
//  JDServices
//
//  Created by Thielen Andrew P on 2/13/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

@interface JDGeoJsonPosition : NSObject

@property(nonatomic, readonly, nonnull) NSNumber *latitude;
@property(nonatomic, readonly, nonnull) NSNumber *longitude;
@property(nonatomic, readonly, nullable) NSNumber *altitude;

- (nonnull instancetype)initWithLongitude:(nonnull NSNumber *)longitude
                                 latitude:(nonnull NSNumber *)latitude
                                 altitude:(nullable NSNumber *)altitude;

- (nonnull instancetype)initWithCoordinate2D:(CLLocationCoordinate2D)coordinate;

- (nullable instancetype)initWithGeoJsonArray:(nonnull NSArray<NSNumber *> *)geoJson;

- (nonnull NSArray<NSNumber *> *)toGeoJsonArray;
- (BOOL)isEqualToPosition:(nullable JDGeoJsonPosition *)otherPosition;

@end
