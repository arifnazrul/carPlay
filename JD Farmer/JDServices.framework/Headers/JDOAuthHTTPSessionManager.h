//
//  JDOAuthHTTPSessionManager.h
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
//  Description
//  Subclassed AFHTTPSessionManager to add oAuth signing to overridden "dataTaskWithHTTPMethod...'
//

#import <AFNetworking/AFHTTPSessionManager.h>

/**
 * @brief Custom {@link AFHTTPSessionManager}.
 */
@interface JDOAuthHTTPSessionManager : AFHTTPSessionManager

/**
 * Returns a new session manager.
 * @param identifier The identifier
 * @param timeout  The request timeout
 * @param contentType The request content type
 * @return A new instance
 */
+ (JDOAuthHTTPSessionManager *_Nonnull)sessionManagerWithIdentifier:(NSString *_Nonnull)identifier
                                                            timeout:(NSTimeInterval)timeout
                                                        contentType:(NSString *_Nonnull)contentType;

/**
 * Returns a new session task.
 * @param method The HTTP method
 * @param URLString The URL string
 * @param parameters The parameters
 * @param progress The progress
 * @param destination The destination
 * @param completionHandler The completion handler
 * @return A new instance
 */
- (NSURLSessionTask *_Nonnull)
downloadTaskWithHTTPMethod:(NSString *_Nonnull)method
                 URLString:(NSString *_Nonnull)URLString
                parameters:(id _Nullable)parameters
               destination:(NSURL *_Nonnull (^_Nullable)(NSURL *_Nonnull, NSURLResponse *_Nullable))destination
         completionHandler:
             (void (^_Nullable)(NSURLResponse *_Nullable, NSURL *_Nonnull, NSError *_Nullable))completionHandler;

@end
