//
//  JDOrganization.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-01-12
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDAPIBaseObject.h"
#import "JDAddress.h"
#import "JDUnitOfMeasureSystem.h"

@class JDOrganizationPreferences;
@class JDAddress;

typedef NS_ENUM(NSUInteger, JDOrganizationPreferencePrioritization) {
    JDOrganizationPreferencePrioritizationUnknown = 0,
    JDOrganizationPreferencePrioritizationOperator,
    JDOrganizationPreferencePrioritizationMachine
};

/**
 * @brief Operation Center Organization.
 */
@interface JDOrganization : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *type;
@property(nonatomic, copy, nullable) NSArray <JDAddress *> *addresses;
@property(nonatomic, strong, nullable) JDOrganizationPreferences *organizationPreferences;
@property(nonatomic, assign) BOOL member;

@property(nonatomic, copy, nullable) NSString *organizationId DEPRECATED_ATTRIBUTE;

@end


/**
 * @brief Additional information embedded into {@link JDOrganization}.
 */
@interface JDOrganizationPreferences : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *jobPrioritizationPreference;
@property(nonatomic, assign) BOOL fieldDetection;
@property(nonatomic, copy, nullable) NSString *unitOfMeasure;
@property(nonatomic, copy, nullable) NSString *timeZone;
@property(nonatomic, copy, nullable) NSString *eulaCountry;
@property(nonatomic, copy, nullable) NSString *industryPreference;
@property(nonatomic, assign) BOOL manualDataRouting;
@property(nonatomic, copy, nullable) NSString *fileSmartNameType;
@property(nonatomic, copy, nullable) NSString *yieldPreference;

@property(nonatomic, copy, nullable) NSString *jobPrioritization DEPRECATED_ATTRIBUTE;

- (JDOrganizationPreferencePrioritization)jobPrioritizationType;

- (JDUnitOfMeasureType)unitOfMeasureType;

@end
