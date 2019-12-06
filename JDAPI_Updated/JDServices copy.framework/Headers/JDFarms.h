//
//  JDFarm.h
//  JDServices
//
//  Created by Sebastian Bott on 2014-12-11
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import "JDFarm.h"
#import <Foundation/Foundation.h>

/**
 * @deprecated
 * @brief Farm container with a list of {@link JDFarm}.
 */
@interface JDFarms : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSArray<JDFarm *> *farms;

@end
