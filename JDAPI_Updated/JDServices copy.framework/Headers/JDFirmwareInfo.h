//
//  JDFirmwareInfo.h
//  JDServices
//
//  Created by Andy Sheehan on 2015-10-26
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDAPIBaseObject.h"

/**
 * @brief Firmware Information.
 */

@interface JDFirmwareInfo : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSString *ident;
@property(nonatomic, strong, nullable) NSString *version;
@property(nonatomic, strong, nullable) NSString *icdVersion;
@property(nonatomic, strong, nullable) NSString *uid;
@property(nonatomic, strong, nullable) NSString *sharedSecret;
@property(nonatomic, strong, nullable) NSString *firmwareID DEPRECATED_ATTRIBUTE;

@end
