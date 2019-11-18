//
//  JDWeatherRequestManager.h
//  JDServices
//
//  Created by Davis Michael J (ISG-K) on 5/18/15.
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <CoreLocation/CoreLocation.h>
#import "JDServicesConstants.h"

@class JDWeather;
@class JDRequestConfiguration;

/**
 * @brief Request Manager for weather API requests.
 */
@interface JDWeatherRequestManager : NSObject

/**
* Returns a single instance. Must have created the instance first.
* @return The instance
*/
+ (JDWeatherRequestManager *)sharedInstance;

/**
* Performs a HTTP GET request.
* @param url The URL
* @param configuration The request configuration
* @param success The success block
* @param failure The failure block
*/
- (NSURLSessionDataTask *)performGETRequestForURL:(NSString *)url
                     parameters:(NSDictionary *)parameters
                  configuration:(JDRequestConfiguration *)requestConfiguration
                        success:(void (^)(id result))success
                        failure:(void (^)(NSURLSessionDataTask *, NSError *))failure;

/**
* Cancel all API calls in the queue and calls the appropriate delegate methods.
*/
- (void)cancelURLSessionDataTasks;

@end
