//
// Created by Nico Boder on 11.09.18.
// Copyright (c) 2018 Deere & Company. All rights reserved.
//
#import "JDAPIBaseObject.h"

/**
 * @brief A regulatory agency's designation for this product. This object contains a link to the corresponding agency.
 */
@interface JDAgencyRegistration : JDAPIBaseObject

@property(nonatomic, strong, nonnull) NSString *registrationId;

@end