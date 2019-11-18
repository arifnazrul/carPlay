//
//  JDCropType.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-06-09
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

@class JDSimpleUnitValue;

/**
 * @brief Crop Type.
 */
@interface JDCropType : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *densityFactor;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *standardPayableMoisture;

@end
