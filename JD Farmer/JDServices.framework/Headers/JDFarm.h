//
//  JDFarm.h
//  JDServices
//
//  Created by Antonacci Luca on 2016-09-19
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDSimpleIdentName.h"

/**
 * @brief Farm of a {@link JDOrganization}.
 */
@interface JDFarm : JDSimpleIdentName

@property(nonatomic, strong, nullable) NSString *uniqueId;

+ (NSString *_Nonnull)uniqueIdentWithOrganization:(NSString *_Nonnull)orgIdent ident:(NSString *_Nonnull)ident;

@end
