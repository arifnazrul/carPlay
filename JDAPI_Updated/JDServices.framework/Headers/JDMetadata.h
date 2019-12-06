//
//  JDMetadata.h
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

#import "JDJsonObject.h"
#import "JDAPIBaseObject.h"

/**
 * @brief Metadata for {@link JDFileResource}.
 */
@interface JDMetadata : JDAPIBaseObject <JDAPIPostBody, NSCoding>

@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *value;


@end
