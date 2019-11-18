//
//  JDContributionProduct.h
//  JDServices
//
//  Created by Wright Daniel W on 12/18/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import <Foundation/Foundation.h>

@interface JDContributionProduct : JDAPIBaseObject

@property(nonatomic) NSString *ident;
@property(nonatomic) NSString *marketPlaceName;
@property(nonatomic) NSString *marketPlaceLogo;

@end
