//
//  JDClientRequests.h
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

@class JDClient;
@class JDResponse;

/**
 * @brief API requests for {@link JDClient}.
 */

@interface JDClientRequests : NSObject

/**
* Fetches a list of all clients from the webservice with the default configuration.
* @param organizationId The id of the organization
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchClientsForOrganizationId:(NSString *_Nonnull)organizationId
                         completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDClient *> *_Nullable,
                                                                       NSError *_Nullable,
                                                                       JDResponse *_Nullable))completionBlock;

/**
* Fetches a list of all clients from the webservice.
* @param organizationId The id of the organization
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchClientsWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                      organizationId:(NSString *_Nonnull)organizationId
                         completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDClient *> *_Nullable Clients,
                                                                       NSError *_Nullable error,
                                                                       JDResponse *_Nullable response))completionBlock;

@end
