//
//  JDSimpleName.h
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

#import <objc/NSObject.h>
#import "JDJsonObject.h"
#import "JDAPIBaseObject.h"

/**
 * @brief Container for object with name.
 */
@interface JDSimpleName : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *name;


@end
