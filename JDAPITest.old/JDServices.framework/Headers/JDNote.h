//
//  JDNote.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-05-20
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDUser;
@class JDFileResource;

/**
 * @brief User note for {@link JDJob}.
 */
@interface JDNote : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *text;
@property(nonatomic, strong, nullable) JDUser *author;
@property(nonatomic, copy, nullable) NSString *organizationId;
@property(nonatomic, copy, nullable) NSString *jobId;
@property(nonatomic, copy, nullable) NSDate *createdDate;
@property(nonatomic, copy, nullable) NSDate *lastModifiedDate;
@property(nonatomic, copy, nullable) NSArray<JDFileResource *> *fileResources;
@property(nonatomic, copy, nullable) NSString *title;

@property(nonatomic, strong, nullable) JDUser *user DEPRECATED_ATTRIBUTE;
@property(nonatomic, copy, nullable) NSDate *dateCreated DEPRECATED_ATTRIBUTE;
@property(nonatomic, copy, nullable) NSDate *dateUpdated DEPRECATED_ATTRIBUTE;

@end
