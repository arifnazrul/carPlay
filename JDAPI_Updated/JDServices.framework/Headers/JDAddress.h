//
//  JDAddress.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-01-12
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDServices.h"

@class JDAddressElement;

/**
 * @brief Address information of {@link JDOrganizationPreferences}.
 */
@interface JDAddress : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSString *country;
@property(nonatomic, strong, nullable) NSArray <JDAddressElement *>*addressElement;
@property(nonatomic, strong, nullable) NSArray <NSString *>*formattedLine;

@end

/**
 * @brief Address elements of {@link JDAddress}.
 */
@interface JDAddressElement : JDAPIBaseObject

@property(nonatomic, strong, nonnull) NSString *elementClass;
@property(nonatomic, strong, nonnull) NSString *elementValue;

@end
