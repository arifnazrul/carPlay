//
//  JDRadarRequestManager.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-10-30
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

@class JDRequestConfiguration;

/**
 * @brief Request Manager for radar API requests.
 */
@interface JDRadarRequestManager : NSObject

/**
* Returns a single instance. Must have created the instance first.
* @return The instance
*/
+ (JDRadarRequestManager *_Nonnull)sharedInstance;

/**
* Performs a HTTP GET request.
* @param url The URL
* @param configuration The request configuration
* @param success The success block
* @param failure The failure block
*/
- (NSURLSessionDataTask *_Nullable)performGETRequestForURL:(NSString *_Nonnull)url
                                             configuration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                                   success:(void (^_Nonnull)(id _Nullable result))success
                                                   failure:(void (^_Nonnull)(NSURLSessionDataTask *_Nullable,
                                                                             NSError *_Nullable))failure;

/**
* Cancel all API calls in the queue and calls the appropriate delegate methods.
*/
- (void)cancelURLSessionDataTasks;

@end