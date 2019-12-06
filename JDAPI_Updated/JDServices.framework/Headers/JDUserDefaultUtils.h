//
//  JDUserDefaultUtils.h
//  JDServices
//
//  Created by Fischer Arne on 2015-06-11
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDServicesSetup.h"

extern NSString *_Nonnull const kJDUserDefaultsETags;
extern NSString *_Nonnull const kJDUserDefaultsJDEnvironment;

/**
 * @brief Accessor methods for user default settings, managed by JDServices.
 */
@interface JDUserDefaultUtils : NSObject

/**
 * Persists the ETag for a given URL.
 * @param tag The ETag
 * @param url The URL
 * @return <code>YES</code> if successful, otherwise <code>NO</code>
 */
+ (BOOL)setETag:(nonnull NSString *)tag forURL:(nonnull NSString *)url;

/**
 * Returns the persisted ETag for a given URL.
 * @return The persisted ETag
 */
+ (nonnull NSString *)eTagForURL:(nullable NSString *)url;

/**
 * Remove all persisted ETags.
 * @return <code>YES</code> if successful, otherwise <code>NO</code>
 */
+ (BOOL)removeAllETags;

/**
 * Persists the MyJohnDeereEnvironment.
 * @param environment The MyJohnDeereEnvironment
 */
+ (void)setJDEnvironment:(JDEnvironment)environment;

/**
 * Returns the persisted MyJohnDeereEnvironment
 * @return The persisted MyJohnDeereEnvironment
 */
+ (JDEnvironment)jdEnvironment;

/**
 * Clears the UserDefaults.
 */
+ (void)clear;

@end
