//
//  JDEmailAddresses.h
//  JDServices
//
//  Created by Patrick Haaser on 2018-04-17
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  Deere & Company IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import <Foundation/Foundation.h>

@class JDEmailAddress;

/**
 * @brief Email Addresses of a {@link JDUser}.
 */
@interface JDEmailAddresses : JDAPIBaseObject

@property(nonatomic, strong) NSArray<JDEmailAddress *> *emailAddresses;
@property(nonatomic, strong) NSDictionary *otherAttributes;

@end