//
//  JDRequestManager.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-06-08
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <objc/NSObject.h>
#import <Foundation/Foundation.h>
#import "JDRequestConfiguration.h"
#import "JDURL.h"

@class JDResponse;
@class JDRequestConfiguration;

static NSString *const kJDRequestManagerErrorDomain = @"com.deere.services.request.manager.error.domain";

/**
 * @brief Request Manager for {@link JDRequest}.
 */
@interface JDRequestManager : NSObject

/**
 * Returns the single instance.
 * @return The instance
 */
+ (JDRequestManager *)sharedInstance;

/**
 * Performs a HTTP GET request.
 * @param url The JD URL
 * @param configuration The request configuration
 * @param success The success block
 * @param failure The failure block
 * @return Returns the task that was created for the get request
 */
- (NSURLSessionTask *)performGETRequestForURL:(JDURL *)url
                                configuration:(JDRequestConfiguration *)configuration
                                      success:(void (^)(id result, JDResponse *response))success
                                      failure:(void (^)(NSURLResponse *, NSError *))failure;

/**
 * Performs a HTTP POST request.
 * @param url The JD URL
 * @param body The request body
 * @param success The success block
 * @param failure The failure block
 * @return Returns the task that was created for the post request
*/
- (NSURLSessionDataTask *)performPOSTRequestForURL:(JDURL *)url
                                     configuration:(JDRequestConfiguration *)requestConfiguration
                                              body:(id)body
                                           success:(void (^)(NSURLSessionDataTask *, id))success
                                           failure:(void (^)(NSError *error))failure;

/**
 * Performs a HTTP PUT request.
 * @param url The JD URL
 * @param body The request body
 * @param success The success block
 * @param failure The failure block
 * @return Returns the task that was created for the put request
*/
- (NSURLSessionDataTask *)performPUTRequestForURL:(JDURL *)url
                                    configuration:(JDRequestConfiguration *)requestConfiguration
                                             body:(NSDictionary *)body
                                          success:(void (^)(NSURLSessionDataTask *, id))success
                                          failure:(void (^)(NSError *error))failure;

/**
 * Performs a HTTP DELETE request using the default request configuration.
 * @param url The JD URL
 * @param success The success block
 * @param failure The failure block
 * @return Returns the task that was created for the delete request
 */
- (NSURLSessionDataTask *)performDELETERequestForURL:(JDURL *)url
                                             success:(void (^)(NSDictionary *result))success
                                             failure:(void (^)(NSError *error))failure;

/**
 * Performs a HTTP DELETE request.
 * @param url The JD URL
 * @param configuration The request configuration
 * @param success The success block
 * @param failure The failure block
 * @return Returns the task that was created for the delete request
 */
- (NSURLSessionDataTask *)performDELETERequestForURL:(JDURL *)url
                                       configuration:(JDRequestConfiguration *)requestConfiguration
                                             success:(void (^)(NSDictionary *result))success
                                             failure:(void (^)(NSError *error))failure;

/**
 * Uploads data.
 * @param fileURL URL to the file to be uploaded
 * @param url The JD URL
 * @param method The HTTP method
 * @param success The success block
 * @param failure The failure block
 * @return A session data task
 */
- (NSURLSessionDataTask *)uploadFile:(NSURL *)fileURL
                               toURL:(JDURL *)url
                   withRequestMethod:(NSString *)method
                       configuration:(JDRequestConfiguration *)configuration
                             success:(void (^)(NSURLResponse *, id))success
                             failure:(void (^)(NSError *error))failure;

/**
 * Uploads data.
 * @param data data to be uploaded
 * @param url The JD URL
 * @param method The HTTP method
 * @param success The success block
 * @param failure The failure block
 * @return A session data task
 */
- (NSURLSessionDataTask *)uploadData:(NSData *)data
                               toURL:(JDURL *)url
                   withRequestMethod:(NSString *)method
                       configuration:(JDRequestConfiguration *)configuration
                             success:(void (^)(NSURLResponse *, id))success
                             failure:(void (^)(NSError *error))failure;

/**
* Cancels all API calls in the queue.
*/
- (void)cancelURLSessionDataTasks;

@end
