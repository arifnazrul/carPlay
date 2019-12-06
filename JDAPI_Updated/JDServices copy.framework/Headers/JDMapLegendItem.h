//
//  JDMapLegendItem.h
//  JDServices
//
//  Created by Wright Daniel W on 12/18/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDJsonObject.h"
#import <Foundation/Foundation.h>

@interface JDMapLegendItem : NSObject <JDJsonObject>

@property(nonatomic) NSString *label;
@property(nonatomic) double minimum;
@property(nonatomic) double maximum;
@property(nonatomic) NSString *hexColor;
@property(nonatomic) double percent;

@end
