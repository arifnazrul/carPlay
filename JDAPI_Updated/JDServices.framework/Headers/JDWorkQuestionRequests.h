//
//  JDWorkQuestionRequests.h
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

#import "JDRequestConfiguration.h"
#import "JDRequest.h"

@class JDWorkQuestion;

/**
 * @brief API requests for {@link JDWorkQuestion}.
 */
@interface JDWorkQuestionRequests : NSObject

/**
* Fetches a list of all work questions from the webservice with the default configuration.
* @param organizationId The id of the organization
* @param locale The locale (language and territory)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchWorkQuestionsForOrganizationId:(NSString *_Nonnull)organizationId
                                                    locale:(NSLocale *_Nullable)locale
                               completionBlockWithResponse:
                                   (void (^_Nonnull)(NSArray<JDWorkQuestion *> *_Nullable workQuestions,
                                                     NSError *_Nullable error,
                                                     JDResponse *_Nullable response))completionBlock;

/**
* Fetches a list of all work questions from the webservice.
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param organizationId The id of the organization
* @param locale The locale (language and territory)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchWorkQuestionsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                            organizationId:(NSString *_Nonnull)organizationId
                                                    locale:(NSLocale *_Nullable)locale
                               completionBlockWithResponse:
                                   (void (^_Nonnull)(NSArray<JDWorkQuestion *> *_Nullable workQuestions,
                                                     NSError *_Nullable error,
                                                     JDResponse *_Nullable response))completionBlock;

/**
 * Fetches a work question with a given id from the webservice with the default request configuration.
 * @param workQuestionId The id of the work question
 * @param locale The locale (language and territory)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchWorkQuestionWithWorkQuestionId:(NSString *_Nonnull)workQuestionId
                                                    locale:(NSLocale *_Nullable)locale
                               completionBlockWithResponse:(void (^_Nonnull)(JDWorkQuestion *_Nullable,
                                                                             NSError *_Nullable,
                                                                             JDResponse *_Nullable))completionBlock;

/**
 * Fetches a work question with a given id from the webservice.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param workQuestionId The id of the work question
 * @param locale The locale (language and territory)
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchWorkQuestionWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                           workQuestionId:(NSString *_Nonnull)workQuestionId
                                                   locale:(NSLocale *_Nullable)locale
                              completionBlockWithResponse:(void (^_Nonnull)(JDWorkQuestion *_Nullable,
                                                                            NSError *_Nullable,
                                                                            JDResponse *_Nullable))completionBlock;

@end
