//
//  JDEmailAddress.h
//  JDServices
//
//  Created by Patrick Haaser on 2018-04-16
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  Deere & Company IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import <Foundation/Foundation.h>

/**
 * @brief Email Address of a {@link JDEmailAddresses}.
 */
@interface JDEmailAddress : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *value;

@end