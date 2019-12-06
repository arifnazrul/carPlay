//
//  JDUser.h
//  JDServices
//
//  Created by Hack Marco on 2014-06-11
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDAPIBaseObject.h"

@class JDEmailAddresses;

/**
 * @brief Operation Center User.
 */
@interface JDUser : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *accountName;
@property(nonatomic, copy, nullable) NSString *familyName;
@property(nonatomic, copy, nullable) NSString *givenName;
@property(nonatomic, copy, nullable) NSString *userType;
@property(nonatomic, strong, nullable) JDEmailAddresses *emailAddresses;

@end
