//
//  JDJSpatial.h
//  JDServices
//
//  Created by Patrick Haaser on 2014-11-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDPoint;

/**
 * @brief Extent of a {@link JDBoundary}.
 */
@interface JDExtent : JDAPIBaseObject

@property(nonatomic, strong, nullable) JDPoint *topLeft;
@property(nonatomic, strong, nullable) JDPoint *bottomRight;

@end
