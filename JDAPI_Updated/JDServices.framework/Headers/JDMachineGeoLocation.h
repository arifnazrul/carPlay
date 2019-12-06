//
//  JDMachineGeoLocation.h
//  JDServices
//
//  Created by Boder Nico on 2016-09-06
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import "JDGeoPoint.h"

@class JDProperties;

/**
 * @brief Used for machine location in a geo json format.
 */
@interface JDMachineGeoLocation : JDAPIBaseObject

@property(nonatomic, strong, nullable) JDGeoPoint *point;
@property(nonatomic, strong, nullable) JDProperties *properties;

@end
