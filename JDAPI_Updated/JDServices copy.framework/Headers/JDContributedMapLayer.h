//
//  JDContributedMapLayer.h
//  JDServices
//
//  Created by Wright Daniel W on 12/18/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"
#import "JDMapExtent.h"
#import "JDMapLegend.h"
#import "JDMetadata.h"
#import <Foundation/Foundation.h>

@interface JDContributedMapLayer : JDAPIBaseObject

@property(nonatomic) NSString *ident;
@property(nonatomic) NSString *title;
@property(nonatomic) JDMapExtent *extent;
@property(nonatomic) JDMapLegend *legends;
@property(nonatomic) NSArray<JDMetadata *> *metadata;

@end
