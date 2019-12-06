//
//  JDDisplay.h
//  JDServices
//
//  Created by Thielen Andrew P on 3/21/18.
//  Copyright © 2018 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import "JDVersion.h"

/**
 * @brief Display object of a machine.
 */
@interface JDDisplay : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSString *ident;
@property(nonatomic, strong, nullable) NSString *serialNumber;
@property(nonatomic, strong, nullable) NSString *type;
@property(nonatomic, strong, nullable) JDVersion *firmwareVersion;

@end
