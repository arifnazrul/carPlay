//
//  JDStaff.h
//  JDServices
//
//  Created by Fischer Arne on 2016-04-29
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//
#import "JDAPIBaseObject.h"

@class JDUser;

/**
 * @brief Staff of a {@link JDOrganization}
 */
@interface JDStaff : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, strong, nullable) JDUser *user;
@property(nonatomic, copy, nullable) NSString *operatorId;
@property(nonatomic, assign) BOOL editable;
@property(nonatomic, assign) BOOL removable;

@end
