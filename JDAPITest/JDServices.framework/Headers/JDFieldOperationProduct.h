//
//  JDFieldOperationProduct.h
//  JDServices
//
//  Created by Wright Daniel W on 12/12/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDJsonObject.h"
#import "JDSimpleUnitValue.h"
#import <Foundation/Foundation.h>

@interface JDFieldOperationProduct : NSObject <JDJsonObject>

@property(nonatomic) NSString *name;
@property(nonatomic) JDSimpleUnitValue *rate;

@end
