//
// Created by Nico Boder on 11.09.18.
// Copyright (c) 2018 Deere & Company. All rights reserved.
//

#import "JDRequestContract.h"

@interface JDChemicalRequestContract : JDRequestContract

/**
 * ID of the Organization for the chemicals.
 */
@property(nonatomic, strong, nonnull) NSString *organizationId;

/**
 * The status of the chemicals to fetch.
 * Accepted values are ARCHIVED, AVAILABLE and ALL.
 * If this property is null, the default will fetch only available (non-archived) chemicals.
 */
@property(nonatomic, strong, nullable) NSString *status;

@end