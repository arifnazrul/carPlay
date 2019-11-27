//
//  JDContributedMapLayerSummary.h
//  JDServices
//
//  Created by Wright Daniel W on 12/18/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDContributedMapLayer.h"
#import "JDContributionDefinition.h"
#import "JDMetadata.h"
#import <Foundation/Foundation.h>

@interface JDContributedMapLayerSummary : JDAPIBaseObject

@property(nonatomic) NSString *ident;
@property(nonatomic) NSString *title;
@property(nonatomic) NSString *text;
@property(nonatomic) NSString *mapType;
@property(nonatomic) NSDate *dateCreated;
@property(nonatomic) NSDate *lastModifiedDate;
@property(nonatomic) NSArray<JDMetadata *> *metadata;
@property(nonatomic) NSArray<JDContributedMapLayer *> *contributedMapLayers;
@property(nonatomic) JDContributionDefinition *contributionDefinition;

@end
