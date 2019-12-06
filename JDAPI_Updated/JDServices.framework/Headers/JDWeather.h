//
//  JDWeather.h
//  JDServices
//
//  Created by Sebastian Bott on 2015-04-27
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <CoreLocation/CoreLocation.h>

/**
 * @brief Weather information.
 */
@interface JDWeather : NSObject

@property(nonatomic, assign) float temperatureValue;
@property(nonatomic, copy, nullable) NSString *temperatureUnit;
@property(nonatomic, assign) NSInteger weatherCode;
@property(nonatomic, assign) NSInteger windDirectionValue;
@property(nonatomic, assign) NSInteger windSpeedValue;
@property(nonatomic, copy, nullable) NSString *windSpeedUnit;
@property(nonatomic, assign) NSInteger rainProbability;
@property(nonatomic, assign) double totalRainAmount;
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;

@end
