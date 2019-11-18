//
//  JDClient.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-01-22
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDSimpleIdentName.h"

/**
 * @brief Client of a {@link JDOrganization}.
 */
@interface JDClient : JDSimpleIdentName

@property(nonatomic, strong, nullable) NSString *uniqueId;

+ (NSString *_Nonnull)uniqueIdentWithOrganization:(NSString *_Nonnull)orgIdent ident:(NSString *_Nonnull)ident;

@end
