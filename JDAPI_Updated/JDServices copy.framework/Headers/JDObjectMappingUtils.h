//
//  JDObjectMappingUtils.h
//  JDServices
//
//  Created by Sebastian Bott on 2014-11-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>

/**
 * @brief Collection of helper  methods for object unmarshalling (including NULL handling).
 */
@interface JDObjectMappingUtils : NSObject

/**
* Returns a dictionary for a given key from dictionary.
* @param key The key
* @param dictionary The dictionary
* @return A dictionary
*/
+ (nullable NSDictionary *)dictionaryForKey:(nullable NSString *)key fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a dictionary for a given selector from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return A dictionary
*/
+ (nullable NSDictionary *)dictionaryForSelector:(nonnull SEL)selectorName
                                  fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a string for a given key from dictionary.
* @param key The key
* @param dictionary The dictionary
* @return A string
*/
+ (nullable NSString *)stringForKey:(nullable NSString *)key fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a string for a given selector from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return A string
*/
+ (nullable NSString *)stringForSelector:(nonnull SEL)selectorName fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a boolean value for a given key from dictionary.
* @param key The key
* @param dictionary The dictionary
* @return A bool value
*/
+ (BOOL)boolForKey:(nullable NSString *)key fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a boolean value for a given selector from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return A bool value
*/
+ (BOOL)boolForSelector:(nonnull SEL)selectorName fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a integer value for a given key from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return An integer value
*/
+ (NSInteger)integerForKey:(nullable NSString *)key fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a integer value for a given selector from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return An integer value
*/
+ (NSInteger)integerForSelector:(nonnull SEL)selectorName fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a long value for a given key from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return A long value
*/
+ (long long)longForKey:(nullable NSString *)key fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a long value for a given selector from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return A long value
*/
+ (long long)longForSelector:(nonnull SEL)selectorName fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a double value for a given key from dictionary.
* @param key The key
* @param dictionary The dictionary
* @return A double value
*/
+ (double)doubleForKey:(nullable NSString *)key fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns a double value for a given selector from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return A double value
*/
+ (double)doubleForSelector:(nonnull SEL)selectorName fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns an array of values for a given key from dictionary.
* @param key The key
* @param dictionary The dictionary
* @return An array
*/
+ (nullable NSArray *)arrayForKey:(nullable NSString *)key fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns an array of values for a selector key from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @return An array
*/
+ (nullable NSArray *)arrayForSelector:(nonnull SEL)selectorName fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Returns an object for a given class from dictionary.
* @param key The key
* @param dictionary The dictionary
* @param className The name of the class
* @return An object
*/
+ (nullable id)objectForKey:(nullable NSString *)key
             fromDictionary:(nullable NSDictionary *)dictionary
                  withClass:(nonnull Class)className;

/**
* Returns an object for a given class from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @param className The name of the class
* @return An object
*/
+ (nullable id)objectForSelector:(nonnull SEL)selectorName
                  fromDictionary:(nullable NSDictionary *)dictionary
                       withClass:(nonnull Class)className;

/**
* Returns an array with object for a given class from dictionary.
* @param key The key
* @param dictionary The dictionary
* @param className The name of the class
* @return An array
*/
+ (nullable NSArray *)objectArrayForKey:(nullable NSString *)key
                         fromDictionary:(nullable NSDictionary *)dictionary
                              withClass:(nullable Class)className;

/**
* Returns an array with object for a given class from dictionary.
* @param selector The selector
* @param dictionary The dictionary
* @param className The name of the class
* @return An array
*/
+ (nullable NSArray *)objectArrayForSelector:(nonnull SEL)selectorName
                              fromDictionary:(nullable NSDictionary *)dictionary
                                   withClass:(nullable Class)className;

/**
* Get a string date from dictionary.
* This transforms the date of the passed format into a NSDate.
* @param key The key
* @param dictionary The dictionary
* @return A date
*/
+ (nullable NSDate *)dateForKey:(nullable NSString *)key fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Get a string date from dictionary.
* This transforms the date of the passed format into a NSDate.
* @param selector The selector
* @param dictionary The dictionary
* @return A date
*/
+ (nullable NSDate *)dateForSelector:(nonnull SEL)selectorName fromDictionary:(nullable NSDictionary *)dictionary;

/**
* Get a string date from dictionary with a given format.
* This transforms the date of the passed format into a NSDate.
* @param key The key
* @param dictionary The dictionary
* @param format The format in which the string within the dictionary is formatted
* @return A date
*/
+ (nullable NSDate *)dateForKey:(nullable NSString *)key
                 fromDictionary:(nullable NSDictionary *)dictionary
                     withFormat:(nonnull NSString *)format;

/**
* Get a string date from dictionary with a given format.
* This transforms the date of the passed format into a NSDate.
* @param selector The selector
* @param dictionary The dictionary
* @param format The format in which the string within the dictionary is formatted
* @return A date
*/
+ (nullable NSDate *)dateForSelector:(nonnull SEL)selectorName
                      fromDictionary:(nullable NSDictionary *)dictionary
                          withFormat:(nonnull NSString *)format;

/**
* Returns an object for a given class from dictionary.
* @param dictionary The dictionary
* @param className The name of the class
* @return An object
*/
+ (nullable NSObject *)objectFromDictionary:(nullable NSDictionary *)dictionary withClass:(nullable Class)className;

/**
* Filters an array for a specific object class
* @param array The source array
* @param filterClass The filter class
* @return A filtered array
*/
+ (nonnull NSArray *)filterArray:(nonnull NSArray *)array forClassInstance:(nonnull Class)filterClass;

/**
 * Returns an object without null values for a given object.
 * @param rawObject The raw object
 * @return The cleaned object
 */
+ (nullable id)removeNullValuesFromRawObject:(nonnull id)rawObject;

@end
