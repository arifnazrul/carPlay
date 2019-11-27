//
//  JDProduct.h
//  JDServices
//
//  Created by Patrick Haaser on 2014-12-16
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

extern NSString *_Nonnull const kProducTypeChemical;
extern NSString *_Nonnull const kProducTypeFertilizer;
extern NSString *_Nonnull const kProducTypeSeed;

/**
 * @brief Operation Center Product.
 */

@interface JDProduct : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *guid;
@property(nonatomic, copy, nullable) NSString *cropId;
@property(nonatomic, copy, nullable) NSString *productName;
@property(nonatomic, copy, nullable) NSString *productType;
@property(nonatomic, copy, nullable) NSString *materialClassification;
@property(nonatomic, assign) NSInteger orgId;
@property(nonatomic, assign) NSInteger orgProductId;
@property(nonatomic, strong, nullable) NSArray<NSString *> *vrCodes;
@property(nonatomic, assign) BOOL archived;
@end
