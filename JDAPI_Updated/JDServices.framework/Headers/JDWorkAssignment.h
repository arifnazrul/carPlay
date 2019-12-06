//
//  JDWorkAssignment.h
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

#import "JDAPIBaseObject.h"

@class JDMachine;
@class JDUser;
@class JDImplement;

/**
 * @brief Work Assignment for a {@link JDJob}.
 */
@interface JDWorkAssignment : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSDate *createdDate;
@property(nonatomic, assign) long long priority;
@property(nonatomic, strong, nullable) JDMachine *machine;
@property(nonatomic, strong, nullable) NSArray<JDImplement *> *implements;
@property(nonatomic, strong, nullable) JDUser *user;

@property(nonatomic, copy, nullable) NSString *status DEPRECATED_ATTRIBUTE;

@end
