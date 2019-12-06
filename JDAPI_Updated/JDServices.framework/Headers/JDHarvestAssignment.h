//
//  JDHarvestAssignment.h
//  JDServices
//
//  Created by Sebastian Bott on 2015-08-10
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDProduct;

/**
 * @brief Harvest Assignment for {@link JDOperationHarvest}.
 */
@interface JDHarvestAssignment : JDAPIBaseObject

@property (nonatomic, strong, nullable) JDProduct *product;


@end
