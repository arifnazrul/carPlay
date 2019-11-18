//
//  JDSeedAssignment.h
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

@class JDProduct;
@class JDSimpleUnitValue;
@class JDFieldRate;

/**
 * @brief Seed Assignment for a {@link JDOperationSeeding}.
 */
@interface JDSeedAssignment : JDAPIBaseObject

@property(nonatomic, strong, nullable) JDSimpleUnitValue *rate;
@property(nonatomic, strong, nullable) JDProduct *product;
@property(nonatomic, copy, nullable) NSString *seed;
@property(nonatomic, strong, nullable) NSArray<JDFieldRate *> *fieldRates;

@end
