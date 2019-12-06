//
// Created by Nico Boder on 11.09.18.
// Copyright (c) 2018 Deere & Company. All rights reserved.
//

#import "JDProduct.h"

@interface JDVariety : JDAPIBaseObject <JDAPIPostBody>
/**
 * The name of the input manufacturer.
 */
@property(nonatomic, strong, nonnull) NSString *companyName;
/**
 * The name of the crop that this variety is associated with. Refer to axiom-db for a list of supported crop names.
 */
@property(nonatomic, strong, nonnull) NSString *cropName;
/**
 * Variety type.
 */
@property(nonatomic, strong, nonnull) NSString *type;
/**
 * The common name of this variety.
 */
@property(nonatomic, strong, nonnull) NSString *name;
/**
 * Modified time.
 */
@property(nonatomic, strong, nonnull) NSDate *modifiedTime;
/**
 * Archived flag.
 */
@property(nonatomic, assign) BOOL archived;
/**
 * The reference identifier.
 */
@property(nonatomic, strong, nonnull) NSString *referenceId;
/**
 * The identifier of this variety.
 */
@property(nonatomic, strong, nonnull) NSString *ident;

@end