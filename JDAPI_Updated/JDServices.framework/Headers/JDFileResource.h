//
//  JDFileResource.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-11-19
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDMetadata;

/**
 * @brief File resource for a {@link JDNote}.
 */
@interface JDFileResource : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, assign) NSInteger version;
@property(nonatomic, copy, nullable) NSString *mimeType;
@property(nonatomic, copy, nullable) NSDate *timestamp;
@property(nonatomic, strong, nullable) NSArray<JDMetadata *> *metadata;
@property(nonatomic, copy, nullable) NSString *targetResourceIdent;

/**
 * Returns the POST body to create a new file resource.
 * @param organizationId The id of the organization
 * @return The POST body dictionary
 */
- (NSDictionary *_Nonnull)createPostBodyWithOrganizationId:(NSString *_Nonnull)organizationId;

/**
 * Returns the POST body to create a new file resource.
 * @return The POST body dictionary
 */
- (NSDictionary *_Nonnull)createPostBody;

@end
