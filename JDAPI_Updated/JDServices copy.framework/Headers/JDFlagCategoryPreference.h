//
//  JDFlagCategoryPreference.h
//  JDServices
//
//  Created by Haugh Leah on 6/4/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JDFlagCategoryPreference : JDAPIBaseObject <NSCopying>

@property(nonatomic) NSString *ident;
@property(nonatomic) NSString *_Nullable prefKey;
@property(nonatomic) NSString *hexColor;
@property(nonatomic) NSDate *createdDate;

- (NSDictionary *)createPutBodyWithContributionId:(NSString *)contributionId;

NS_ASSUME_NONNULL_END

@end
