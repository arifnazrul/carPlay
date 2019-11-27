//
//  JDAccessPoint.h
//  JDServices
//
//  Created by Rico Dewein on 2016-06-06
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
 * @brief Access Point of a {@link JDField}
 */
@interface JDAccessPoint : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *accessPointDescription;
@property(nonatomic, strong, nullable) JDPoint *location;
@property(nonatomic, assign) BOOL isEntry;
@property(nonatomic, assign) BOOL isExit;
@property(nonatomic, assign) double direction;

@end