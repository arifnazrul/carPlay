//
//  JDFieldRequestContract.h
//  JDServices
//
//  Created by Mumma Keegan R on 5/16/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDRequestContract.h"

/**
 * Options for embedded objects in the webservice request.
 */
typedef NS_OPTIONS(NSUInteger, JDFieldEmbedOptions) {
    JDFieldEmbedNone = 0,
    JDFieldEmbedClients = 1 << 0,
    JDFieldEmbedFarms = 1 << 1,
    JDFieldEmbedBoundaries = 1 << 2,
    JDFieldEmbedSimplifiedBoundaries = 1 << 3,
    JDFieldEmbedGuidanceLines = 1 << 4,
    JDFieldEmbedAccessPoints = 1 << 5,
    JDFieldEmbedLastFieldOperation = 1 << 6,
    JDFieldEmbedActiveSimplifiedBoundary = 1 << 7
};

@interface JDFieldRequestContract : JDRequestContract
@property(nonatomic, strong, nonnull) NSString *orgId;

@property(nonatomic, strong, nullable) NSString *fieldName;

@property(nonatomic, strong, nullable) NSString *clientName;

@property(nonatomic, strong, nullable) NSString *status;

@property(nonatomic, strong, nullable) NSString *farmName;

@property(nonatomic, strong, nullable) NSString *ascending;

@property(nonatomic, strong, nullable) NSString *search;

@property(nonatomic, assign) JDFieldEmbedOptions embed;

@property(nonatomic, strong, nullable) NSString *showLinks;

@property(nonatomic, strong, nullable) NSString *contextOrganizationId;

+ (JDFieldRequestContract *_Nonnull)fieldRequestContractWithOrgId:(NSString *_Nonnull)orgId;

@end
