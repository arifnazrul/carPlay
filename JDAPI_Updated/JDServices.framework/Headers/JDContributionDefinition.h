//
//  JDContributionDefinition.h
//  JDServices
//
//  Created by Wright Daniel W on 12/18/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDContributionProduct.h"
#import <Foundation/Foundation.h>

@interface JDContributionDefinition : JDAPIBaseObject

@property(nonatomic) NSString *ident;
@property(nonatomic) JDContributionProduct *contributionProduct;

@end
