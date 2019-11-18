//
//  JDOperationProperty.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-03-01
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

/**
 * @brief Property of a @{JDOperation}.
 * Linked List of the properties of an operation.
 * @author Bott Sebastian
 */
@interface JDOperationProperty : NSObject

@property(nonatomic, strong, nullable) NSString *propertyKey;
@property(nonatomic, strong, nullable) NSObject *propertyValue;

- (instancetype _Nonnull)initWithPropertyKey:(NSString *_Nonnull)propertyKey
                               propertyValue:(NSObject *_Nonnull)propertyValue;

+ (instancetype _Nonnull)propertyWithPropertyKey:(NSString *_Nonnull)propertyKey
                                   propertyValue:(NSObject *_Nonnull)propertyValue;

@end
