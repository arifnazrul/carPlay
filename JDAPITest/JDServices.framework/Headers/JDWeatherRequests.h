//
//  JDWeatherRequests.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-07-09
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "JDServicesConstants.h"
#import "JDRequestConfiguration.h"
#import "JDRequest.h"
#import "JDOrganization.h"
#import "JDUnitOfMeasureSystem.h"

@class JDBoundingBox;
@class JDWeather;

//TODO: Write test cases
/**
 * @brief API requests for {@link JDWeather}.
 */
@interface JDWeatherRequests : NSObject

/**
* Fetches radar gif for bounding box and image size.
* Calling this function again cancels the current request.
* @param boundingBox The bounding box of the image
* @param imageSize The size of the image in pixel
* @param pastHours The last x hours. Maximum is 5!
* @param gifFrameFrequencyInMinutes The time frequency between the single GIF frames
* @param completion The completion block
* @return The request
*/
+ (JDRequest *_Nonnull)fetchRadarDataForLocation:(JDBoundingBox *_Nonnull)boundingBox
                                       imageSize:(CGSize)imageSize
                                       pastHours:(NSUInteger)pastHours
                      gifFrameFrequencyInMinutes:(NSUInteger)gifFrameFrequencyInMinutes
                                      completion:(void (^_Nonnull)(NSData *_Nullable data,
                                                                   NSError *_Nullable error))completionBlock;

/**
* Fetches the current weather for a given location and units.
* @param coordinate The location coordinate
* @param unitOfMeasureType The unit of measure type of your organization
* @param completion The completion block
* @return The request
*/
+ (JDRequest *_Nonnull)fetchWeatherNextHourForLocation:(CLLocationCoordinate2D)coordinate
                                     unitOfMeasureType:(JDUnitOfMeasureType)unitOfMeasureType
                                            completion:(void (^_Nonnull)(JDWeather *_Nullable weather,
                                                                         NSError *_Nullable error))completionBlock;

/**
 * Fetches the current weather for a given location, timespan, and units.
 * @param coordinate The location coordinate
 * @param timespan The number of hours we want the weather for
 * @param unitOfMeasureType The unit of measure type of your organization
 * @param complete The completion block
 */
+ (void)fetchWeatherForLocation:(CLLocationCoordinate2D)coordinate
                       timespan:(int)timespan
              unitOfMeasureType:(JDUnitOfMeasureType)unitOfMeasureType
                     completion:
                         (nonnull void (^)(JDWeather *_Nullable weather, NSError *_Nullable error))completionBlock;

@end
