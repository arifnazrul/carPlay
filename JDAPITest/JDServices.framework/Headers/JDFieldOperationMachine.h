//
//  JDFieldOperationMachine.h
//  JDServices
//
//  Created by Gillispie Leah on 10/10/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import <Foundation/Foundation.h>

@interface JDFieldOperationMachine : JDAPIBaseObject <NSCoding>

- (instancetype)initWithDictionary:(NSDictionary *)data;

@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *vin;
@property(nonatomic, strong) NSString *GUID;
@property(nonatomic, strong) NSString *identifier;

@end
