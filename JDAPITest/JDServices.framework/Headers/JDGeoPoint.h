//
//  JDGeoPoint.h
//  JDServices
//
//  Created by Boder Nico on 2016-09-07
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

/**
* @brief GeoJSON Point for {@link JDMachineGeoLocation}
**/

@interface JDGeoPoint : NSObject

@property(nonatomic, assign) double latitude;
@property(nonatomic, assign) double longitude;
@property(nonatomic, assign) double altitude;

/**
 * Generates a new JDGeoPoint with the values of the given array.
 *
 * @param geoArray An array which should contain values for longitude, latitude and altitude, in that order.
 * The array must contain at least two values; the altitude is optional.
 *
 * @return The generated instance.
 */
- (instancetype _Nonnull)initWithGeoJsonArray:(NSArray *_Nonnull)geoArray;

/**
 * Generates a new JDGeoPoint with the given values.
 *
 * @param latitude The latitude.
 * @param longitude The longitude.
 * @param altitude The altitude.
 *
 * @return The generated instance.
 */
- (instancetype _Nonnull)initWithLatitude:(double)latitude longitude:(double)longitude altitude:(double)altitude;

@end
