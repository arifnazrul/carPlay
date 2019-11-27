//
//  JDMapLegend.h
//  JDServices
//
//  Created by Wright Daniel W on 12/18/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDMapLegendItem.h"
#import <Foundation/Foundation.h>

@interface JDMapLegend : NSObject <JDJsonObject>

@property(nonatomic) NSString *unitId;
@property(nonatomic) NSArray<JDMapLegendItem *> *ranges;

@end
