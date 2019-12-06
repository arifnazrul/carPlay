//
//  JDField.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-06-03
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDServicesConstants.h"
#import "JDAPIBaseObject.h"

@class JDFarms;
@class JDClients;
@class JDBoundary;
@class JDGuidanceLine;
@class JDAccessPoint;
@class JDFieldOperation;
@class JDFlag;

/**
 * @brief Operation Center Field.
 */
@interface JDField : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *uniqueId;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *orgId;
@property(nonatomic, strong, nullable) JDClients *clients;
@property(nonatomic, strong, nullable) JDFarms *farms;
@property(nonatomic, strong, nullable) NSArray<JDBoundary *> *boundaries;
@property(nonatomic, strong, nullable) NSArray<JDGuidanceLine *> *guidanceLines;
@property(nonatomic, strong, nullable) NSArray<JDAccessPoint *> *accessPoints;
@property(nonatomic, nullable) JDFieldOperation *lastFieldOperation;
@property(nonatomic, nullable) NSArray<JDFlag *> *flags;
@property(nonatomic, assign) BOOL archived;

/**
 * Returns the POST body to create or update a field.
 * @param organizationId The id of the organization
 * @param userAccountName The name of the user
 * @return The POST body dictionary
 */
- (NSDictionary *_Nonnull)createPostBodyWithOrganizationId:(NSString *_Nonnull)organizationId
                                           userAccountName:(NSString *_Nonnull)userAccountName;

+ (NSString *_Nonnull)uniqueIdentWithOrganization:(NSString *_Nonnull)orgIdent ident:(NSString *_Nonnull)ident;

@end
