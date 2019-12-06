//
//  JDProductPackage.h
//  JDServices
//
//  Created by Schwamberger Martin on 2014-07-14
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

/**
 * @brief A product package found in a machine terminal.
 */
@interface JDProductPackage : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSString *displayName;
@property(nonatomic, strong, nullable) NSString *serialNumber;
@property(nonatomic, strong, nullable) NSDate *startDate;
@property(nonatomic, strong, nullable) NSDate *expirationDate;
@property(nonatomic, strong, nullable) NSString *state;
@property(nonatomic, strong, nullable) NSString *type;

@end