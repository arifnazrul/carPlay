//
//  JDTerminal.h
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

@class JDVersion;
@class JDProductPackage;

/**
 * @brief Terminal object of a machine.
 */
@interface JDTerminal : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSString *ident;
@property(nonatomic, strong, nullable) NSString *serialNumber;
@property(nonatomic, strong, nullable) NSString *type;
@property(nonatomic, strong, nullable) NSString *hardwareType;
@property(nonatomic, strong, nullable) NSString *hardwareStatus;
@property(nonatomic, strong, nullable) NSDate *activeTransferDate;
@property(nonatomic, strong, nullable) NSDate *registrationDate;
@property(nonatomic, strong, nullable) NSString *registrationStatus;
@property(nonatomic, strong, nullable) JDVersion *firmwareVersion;
@property(nonatomic, strong, nullable) NSArray<JDProductPackage *> *productPackages;

@end
