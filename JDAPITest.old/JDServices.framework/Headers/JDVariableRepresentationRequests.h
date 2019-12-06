//
//  JDVariableRepresentationRequests.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-08-08
//
//  Unpublished Work (c) 2017 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDServices.h"

@class JDVariableRepresentation;
@class JDRequest;
@class JDResponse;
@class JDRequestConfiguration;
@class JDUnitOfMeasureSystem;

/**
 * @brief API requests for {@link JDJDVariableRepresentation}.
 */
@interface JDVariableRepresentationRequests : NSObject

/**
 * Fetches a list of all variable representations from the webservice with the default configuration.
 * @param locale The locale (language and territory)
 * @param unitOfMeasureSystem The unit of measure system
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchVariableRepresentationsWithLocale:(NSLocale *_Nullable)locale
                                          unitOfMeasureSystem:(JDUnitOfMeasureType)unitOfMeasureSystem
                                  completionBlockWithResponse:
                                      (void (^_Nonnull)(NSArray<JDVariableRepresentation *> *_Nullable,
                                                        NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of all tvariable representations from the webservice.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param locale The locale (language and territory)
 * @param unitOfMeasureSystem The unit of measure system
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)
fetchVariableRepresentationsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                       locale:(NSLocale *_Nullable)locale
                          unitOfMeasureSystem:(JDUnitOfMeasureType)unitOfMeasureSystem
                  completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDVariableRepresentation *> *_Nullable,
                                                                NSError *_Nullable,
                                                                JDResponse *_Nullable))completionBlock;

/**
 * Fetches a variable representation with a given id from the webservice with the default request configuration.
 * @param variableRepresentationId The id of the variable representation
 * @param locale The locale (language and territory)
 * @param unitOfMeasureSystem The unit of measure system
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)
fetchVariableRepresentationWithVariableRepresentationId:(NSString *_Nonnull)variableRepresentationId
                                                 locale:(NSLocale *_Nullable)locale
                                    unitOfMeasureSystem:(JDUnitOfMeasureType)unitOfMeasureSystem
                            completionBlockWithResponse:(void (^_Nonnull)(JDVariableRepresentation *_Nullable,
                                                                          NSError *_Nullable,
                                                                          JDResponse *_Nullable))completionBlock;

/**
 * Fetches a variable representation with a given id from the webservice.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param variableRepresentationId The id of the variable representation
 * @param locale The locale (language and territory)
 * @param unitOfMeasureSystem The unit of measure system
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)
fetchVariableRepresentationWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                    variableRepresentationId:(NSString *_Nonnull)variableRepresentationId
                                      locale:(NSLocale *_Nullable)locale
                         unitOfMeasureSystem:(JDUnitOfMeasureType)unitOfMeasureSystem
                 completionBlockWithResponse:(void (^_Nonnull)(JDVariableRepresentation *_Nullable, NSError *_Nullable,
                                                               JDResponse *_Nullable))completionBlock;

@end
