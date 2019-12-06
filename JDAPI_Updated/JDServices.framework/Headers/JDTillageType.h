//
//  JDTillageType.h
//  JDServices
//
//  Created by Sebastian Bott on 2015-08-05
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <objc/NSObject.h>
#import "JDJsonObject.h"
#import "JDAPIBaseObject.h"

/**
 * @brief Tillage Type.
 */
@interface JDTillageType : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *vrDomainId;
@property(nonatomic, copy, nullable) NSString *guid;
@property(nonatomic, copy, nullable) NSString *tillageTypeId;

@end
