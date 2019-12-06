//
//  JDLocalizedString.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-09-24
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#define JDLocalizedString(key, comment) [JDLocalizedString jdsLocalizedStringForKey:key]

@interface JDLocalizedString : NSObject

+ (NSString *)jdsLocalizedStringForKey:(NSString *)key DEPRECATED_ATTRIBUTE;

@end