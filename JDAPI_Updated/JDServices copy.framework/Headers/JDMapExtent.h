//
//  JDMapExtent.h
//  JDServices
//
//  Created by Wright Daniel W on 12/19/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDExtent.h"
#import "JDPoint.h"
#import <Foundation/Foundation.h>

@interface JDMapExtent : JDExtent

@property(nonatomic) double minimumLatitude;
@property(nonatomic) double maximumLatitude;
@property(nonatomic) double minimumLongitude;
@property(nonatomic) double maximumLongitude;

@end
