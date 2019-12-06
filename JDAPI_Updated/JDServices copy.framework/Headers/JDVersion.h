//
//  JDVersion.h
//  JDServices
//
//  Created by Thielen Andrew P on 3/21/18.
//  Copyright © 2018 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"

@interface JDVersion : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSString *number;
@property(nonatomic, strong, nullable) NSString *type;

@end
