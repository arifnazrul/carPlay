//
//  JDBreadcrumb.h
//  JDServices
//
//  Created by Haaser Patrick on 2019-01-23
//
//  Unpublished Work (c) 2019 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDBreadcrumb.h"
#import <JDServices/JDAPIBaseObject.h>

@class JDSimpleUnitValue;
@class JDPoint;

/**
 * @brief Used to upload a machine location of type 'Breadcrumb'.
 */
@interface JDBreadcrumb : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, strong, nullable) JDPoint *point;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *speed;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *heading;
@property(nonatomic, strong, nullable) JDSimpleUnitValue *fuelLevel;
@property(nonatomic, strong, nullable) NSString *origin;
@property(nonatomic, strong, nullable) NSDate *createTimestamp;
@property(nonatomic, strong, nullable) NSDate *eventTimestamp;
@property(nonatomic, strong, nullable) NSString *correlationId;

@end
