//
//  JDFlagCategory.h
//  JDServices
//
//  Created by Haugh Leah on 1/7/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import "JDFlagCategoryPreference.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JDFlagCategory : JDAPIBaseObject <NSCopying>

@property(nonatomic) NSString *categoryTitle;
@property(nonatomic) NSString *sourceNode;
@property(nonatomic) NSString *ident;
@property(nonatomic) BOOL preferred;
@property(nonatomic) NSDate *createdDate;
@property(nonatomic) NSDate *lastModifiedDate;
@property(nonatomic) NSArray<JDFlagCategoryPreference *> *preferences;

- (NSDictionary *_Nonnull)createPostBodyWithContributionId:(NSString *_Nonnull)contributionId;
- (NSDictionary *_Nonnull)createPutBodyWithContributionId:(NSString *_Nonnull)contributionId
                                        andOrganizationId:(NSString *_Nonnull)orgId;

@end

NS_ASSUME_NONNULL_END
