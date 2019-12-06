//
//  JDRequestConfiguration.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-09-22
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDUnitOfMeasureSystem.h"

@protocol JDIncrementalCallbackDelegate;

/**
 * @brief Request Configuration for {@link JDRequest}.
 */
@interface JDRequestConfiguration : NSObject

/**
 * <code>YES</code> if ETag should be used, otherwise <code>NO</code>.
 * If use {@link #customETag} to set your ETag. You will receive ETag's from the Request callback within {@link
 * JDResponse}.
 * Save the received ETag in the same Database transaction as you save the received data. This makes sure there is no
 * inconsistency between ETag and actual data.
 */
@property(nonatomic, assign) BOOL useCustomETag;

/**
 * The entity tag of the request. Set your ETag for the request here. If the request is executed for the first time set
 * an empty string here.
 */
@property(nonatomic, strong, nullable) NSString *customETag;

/**
 * The interval the request times out in milliseconds.
 */
@property(nonatomic, assign) NSTimeInterval timeoutInterval;

/**
 * The interval the resource times out in seconds.
 */
@property(nonatomic, assign) NSTimeInterval resourceTimeoutInterval;

/**
 * The maximum wait to retry a request after a 429 in seconds. If the response has a `Retry-After` header value, the
 * time to wait before retrying is the lesser of the header value and this.
 */
@property(nonatomic, assign) NSTimeInterval maxRetryDelay;

/**
 * Automatically retry on a `429 Too Many Requests`. Defaults to true.
 */
@property(nonatomic, assign) bool autoRetryOn429;

/**
 * Optional request headers to be added to the request.
 */
@property(nonatomic, strong, nonnull) NSMutableDictionary<NSString *, NSString *> *headerParameters;

/**
 * The requested locale (language and territory).
 */
@property(nonatomic, strong, nullable) NSLocale *locale;

/**
 * The requested unit of measure (UOM) system.
 */
@property(nonatomic, assign) JDUnitOfMeasureType unitOfMeasureSystem;

/**
 * Only set this property if you don't want to use JSON v3.
 */
@property(nonatomic, strong, nullable) NSString *contentType;

/**
 * The response class. Use only with {@link JDIncrementalCallbackDelegate}.
 */
@property(nonatomic, strong, nullable) Class responseClass;

/**
 * Defines if the callback should be on the main queue.
 * Default is @{code YES}. This is the default AFNetworking behaviour.
 * If set to @{code NO} the callback will be received on a background queue.
 */
@property(nonatomic, assign) BOOL useMainQueueCallback;

/**
 * Overrides the base URL of the environment.
 * Base URL consists of protocol, hostname and path i.e. http://www.example.com/var/
 */
@property(nonatomic, strong, nullable) NSString *baseURL;

/**
 * Set this delegate to receive a callback for each object parsed.
 * If this is set the completion block of the request used will not contain any data. Instead each object will be
 * passed to the delegate.
 */
@property(nonatomic, weak, nullable) id<JDIncrementalCallbackDelegate> incrementalCallbackDelegate;

#pragma mark Deprecated Properties

/**
 * @deprecated use {@link #useCustomETag} instead and set / save your eTag manually.
 */
@property(nonatomic, assign) BOOL useETag DEPRECATED_ATTRIBUTE;

/**
 * @deprecated use {@link #customETag} instead.
 */
@property(nonatomic, strong, nullable) NSString *ETag DEPRECATED_ATTRIBUTE;

/**
 * Creates a new request configuration with the default values.
 * @return The default configuration
 */
+ (nonnull instancetype)defaultConfiguration;

/**
 * Creates a new request configuration with custom ETag (DTag) usage
 * and custom timeout interval.
 * @param customETag The ETag that should be used. Empty string for the first Request. Nil if no ETag should be used.
 * @param timeoutInterval The timeout interval
 * @return The configuration
 */
+ (nonnull instancetype)requestConfigurationCustomETag:(NSString *_Nullable)customETag
                                       timeoutInterval:(NSTimeInterval)timeoutInterval;

/**
 * Creates a new request configuration with custom ETag (DTag) usage
 * and custom timeout interval.
 * @param customETag The ETag that should be used. Empty string for the first Request. Nil if no ETag should be used.
 * @return The configuration
 */
+ (nonnull instancetype)requestConfigurationCustomETag:(NSString *_Nullable)customETag;

#pragma mark Deprecated Constructors

/**
 * @deprecated use {@link #requestConfigurationUsingETag:timeoutInterval:} instead
 */
+ (nonnull instancetype)requestConfigurationUsingETag:(BOOL)shouldUseETag
                                      timeoutInterval:(NSTimeInterval)timeoutInterval DEPRECATED_ATTRIBUTE;

@end
