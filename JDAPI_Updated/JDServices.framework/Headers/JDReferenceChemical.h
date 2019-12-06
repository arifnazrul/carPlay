//
// Created by Nico Boder on 11.09.18.
// Copyright (c) 2018 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import "JDProduct.h"

@interface JDReferenceChemical : JDAPIBaseObject <JDAPIPostBody>
/**
 * The identifier of this product.
 */
@property(nonatomic, strong, nonnull) NSString *ident;
/**
 * [ADDITIVE, FUNGICIDE, INSECTICIDE, HERBICIDE, GROWTH_REGULATOR, NITROGEN_STABILIZER, MANURE, FERTILIZER]
 */
@property(nonatomic, strong, nonnull) NSString *type;
/**
 * {@link AgencyRegistration}
 */
@property(nonatomic, strong, nullable) NSArray<NSObject *> *agencyRegistrations;
/**
 * The name of the input manufacturer.
 */
@property(nonatomic, strong, nonnull) NSString *companyName;
/**
 * The common name of this product.
 */
@property(nonatomic, strong, nonnull) NSString *name;
/**
 * The reference id.
 */
@property(nonatomic, strong, nonnull) NSString *referenceId;
/**
 * Whether or not this product has been flagged for use as a tank mix carrier. Only applicable in an organizational
 * context. Defaults to NO.
 */
@property(nonatomic, assign) BOOL carrier;
/**
 * Modified time.
 */
@property(nonatomic, strong, nonnull) NSDate *modifiedTime;
/**
 * Archived flag.
 */
@property(nonatomic, assign) BOOL archived;
/**
 * Restricted use flag.
 */
@property(nonatomic, assign) BOOL restrictedUse;
/**
 * The category of this product (e.g. CHEMICAL).
 */
@property(nonatomic, strong, nonnull) NSString *category;
/**
 * The material classification of this product (e.g. LIQUID).
 */
@property(nonatomic, strong, nonnull) NSString *materialClassification;

@end
