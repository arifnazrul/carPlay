//
//  JDOperation.h
//  JDServices
//
//  Created by Sebastian Bott on 2014-11-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import "JDOperationProperty.h"

@class JDPrescriptionAssignment;

extern NSString *_Nonnull const kOperationTypeApplication;
extern NSString *_Nonnull const kOperationTypeHarvest;
extern NSString *_Nonnull const kOperationTypeSeeding;
extern NSString *_Nonnull const kOperationTypeTillage;

/**
 * @brief Operation for {@link JDWorkPlan}.
 */
@interface JDOperation : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *type;
@property(nonatomic, strong, nullable) NSArray<JDOperationProperty *> *operationProperties;

@end
