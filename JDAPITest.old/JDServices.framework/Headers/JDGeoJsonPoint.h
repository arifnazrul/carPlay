//
//  JDGeoJsonPoint.h
//  JDServices
//
//  Created by Thielen Andrew P on 2/12/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDGeoJsonGeometry.h"
#import "JDGeoJsonPosition.h"

@interface JDGeoJsonPoint : JDGeoJsonGeometry <RawPosition *>

@property(nonatomic, readonly, nonnull) JDGeoJsonPosition *coordinate;

- (nonnull instancetype)initWithCoordinate:(nonnull JDGeoJsonPosition *)coordinate;

- (BOOL)isEqualToPoint:(nullable JDGeoJsonPoint *)point;

@end
