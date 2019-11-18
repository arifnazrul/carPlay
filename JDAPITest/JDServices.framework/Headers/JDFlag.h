//
//  JDFlag.h
//  JDServices
//
//  Created by Wright Daniel W on 12/11/18.
//  Copyright © 2018 Deere & Company. All rights reserved.
//

#import "JDField.h"
#import "JDFlagCategory.h"
#import "JDGeoJsonGeometry.h"
#import "JDMetadata.h"
#import <Foundation/Foundation.h>

@interface JDFlag : JDAPIBaseObject<NSCopying>

@property(nonatomic, nullable) NSString *serverIdent;
@property(nonatomic) BOOL archived;
@property(nonatomic, nullable) NSString *notes;
@property(nonatomic, nullable) NSDate *createdDate;
@property(nonatomic, nullable) NSDate *lastModifiedDate;
@property(nonatomic, nullable) JDField *field;
@property(nonatomic, nullable) JDGeoJsonGeometry *geometry;
@property(nonatomic, nullable) JDFlagCategory *flagCategory;
@property(nonatomic, nullable) NSArray<JDMetadata *> *metadata;

- (NSDictionary *_Nonnull)createPostBodyWithNotesContributionId:(NSString *_Nonnull)contributionId;
- (NSDictionary *_Nonnull)createPutBodyWithNotesContributionId:(NSString *_Nonnull)contributionId
                                             andOrganizationId:(NSString *_Nonnull)orgId;
- (NSString *_Nullable)metadataValueForName:(NSString *_Nonnull)metadataName;

@end
