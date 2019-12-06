//
//  JDProductRequests.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-08-11
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//
#import "JDRequest.h"

@class JDRequestConfiguration;
@class JDProduct;
@class JDResponse;

/**
 * @brief API requests for {@link JDProduct}.
 */
@interface JDProductRequests : NSObject

/**
 * Fetches a list of all products from the webservice with the default configuration.
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchProductsWithOrganizationId:(NSString *_Nonnull)organizationId
                           completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDProduct *> *_Nullable,
                                                                         NSError *_Nullable,
                                                                         JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all products from the webservice.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchProductsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                       organizationId:(NSString *_Nonnull)organizationId
                          completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDProduct *> *_Nullable,
                                                                        NSError *_Nullable,
                                                                        JDResponse *_Nullable))completionBlock;

#pragma mark deprecated

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchProductsWithOrganizationId:(NSString *_Nonnull)organizationId
                                       completionBlock:(void (^_Nonnull)(NSArray<JDProduct *> *_Nullable products,
                                                                         NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchProductsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                       organizationId:(NSString *_Nonnull)organizationId
                                      completionBlock:(void (^_Nonnull)(NSArray<JDProduct *> *_Nullable products,
                                                                        NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
