//
//  JDServiceDateUtils.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-07-07
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>

/**
 * @brief Collection of date helper methods.
 */
@interface JDServiceDateUtils : NSObject

/**
* Converts NSDate to ISO String.
* This format is required for the API calls.
* @param date The date
* @return The formatted string
*/
+ (NSString *_Nonnull)formatDateToIsoString:(NSDate *_Nonnull)date;

/**
* Converts NSDate to today String.
* @param date The date
* @return The formatted string
*/
+ (NSString *_Nonnull)formatDateToTodayString:(NSDate *_Nonnull)date;

/**
* Converts NSString to a NSDate with ISO format.
* This format is required for the API calls.
 *
 * Note: The given date has to be conform to the ISO8061 formatg (yyyy-MM-dd'T'HH:mm:ssZ)
 * otherwise this function will return nil.
* @param dateString The date string
* @return The date
*/
+ (NSDate *_Nullable)createIsoDateFromString:(NSString *_Nonnull)dateString;

/**
 * Converts NSString to a NSDate with the given format.
 */
+ (NSDate *_Nonnull)createDateFromDateString:(NSString *_Nonnull)dateString
                        withDateFormatString:(NSString *_Nonnull)dateFormatString;

/**
 * Converts NSDate to a NSString with the given format.
 */
+ (NSString *_Nonnull)createDateStringFromDate:(NSDate *_Nonnull)date withDateFormat:(NSString *_Nonnull)dateFormat;

/**
 * Adds a specific number of hours to a given date.
 * @param hours The number of hours
 * @param date The date
 * @return The new date
 */
+ (NSDate *_Nonnull)addHours:(NSInteger)hours toDate:(NSDate *_Nonnull)date;

/**
 * Generates the formatted date string for the weather API.
 * @param startDate The start date
 * @param endDate The end date
 * @param interval The interval
 * @return The formatted string
 */
+ (NSString *_Nonnull)formattedRadarApiDateFrom:(NSDate *_Nonnull)startDate
                                             to:(NSDate *_Nonnull)endDate
                              intervalInMinutes:(NSUInteger)interval;

#pragma mark Deprecated

/**
* @deprecated
* DO NOT USE THIS METHOD. USE NSDATEFORMATTER TO INTERPRET TIMESTAMPS IN A SPECIFIC TIMEZONE.
* Converts a UTC date (GMT+0) to the local time zone.
* @param date The UTC date
* @return The local date
*/
+ (NSDate *_Nonnull)localDateFromUTCDate:(NSDate *_Nonnull)date DEPRECATED_ATTRIBUTE;

@end
