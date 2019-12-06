//
//  JDMachineLocationBreadcrumb.h
//  JDServices
//
//  Created by Martin Schwamberger on 2016-07-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

/**
 * @brief Used to upload a machine location of type 'Breadcrumb'.
 */
DEPRECATED_ATTRIBUTE
@interface JDMachineLocationBreadcrumb : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, strong) NSDate *createTime DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong) NSDate *eventTime DEPRECATED_ATTRIBUTE;
@property(nonatomic, assign) double latitude DEPRECATED_ATTRIBUTE;
@property(nonatomic, assign) double longitude DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong) NSNumber *altitude DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong) NSNumber *speed DEPRECATED_ATTRIBUTE;
@property(nonatomic, strong) NSNumber *heading DEPRECATED_ATTRIBUTE;

@end