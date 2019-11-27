//
//  JDFieldRate.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-11-03
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDSimpleUnitValue;

/**
 * @brief Field Rate for a {@link JDWorkOrder} specific {@link JDProduct} rate
 * @author Bott Sebastian
 */
@interface JDFieldRate : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, strong, nullable) JDSimpleUnitValue *rate;

@end
