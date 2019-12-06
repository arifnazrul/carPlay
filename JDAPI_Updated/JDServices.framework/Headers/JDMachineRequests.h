//
//  JDMachineRequests.h
//  JDServices
//
//  Created by Bott Sebastian 2015-09-22
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDRequest.h"
#import "JDRequestConfiguration.h"
#import <Foundation/Foundation.h>

// clang-format off
typedef NS_OPTIONS(NSUInteger, JDMachineEmbedOptions) {
    JDMachineEmbedNone = 0,
    JDMachineEmbedLocation DEPRECATED_ATTRIBUTE = 1 << 0,
    JDMachineEmbedTerminal DEPRECATED_ATTRIBUTE = 1 << 1,
    JDMachineEmbedBreadcrumbs = 1 << 2,
    JDMachineEmbedEquipmentIcon = 1 << 3,
    JDMachineEmbedTerminals = 1 << 4,
    JDMachineEmbedLocations = 1 << 5
};
// clang-format on

@class JDMachine;
@class JDResponse;
@class JDBreadcrumb;
@class JDMachineGeoLocation;

/**
 * @brief API requests for {@link JDMachine}.
 */
@interface JDMachineRequests : NSObject <JDRequestEmbed>

#pragma mark - GET Requests

/**
* Fetches a list of all machines from the webservice with the default configuration.
* @param organizationId The id of the organization
* @param embedOptions The {@link JDMachineEmbedOptions} which should be embedded to the response (bitmask)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchMachinesWithOrganizationId:(NSString *_Nonnull)organizationId
                                          embedOptions:(JDMachineEmbedOptions)embedOptions
                           completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDMachine *> *_Nullable,
                                                                         NSError *_Nullable,
                                                                         JDResponse *_Nullable))completionBlock;

/**
* Fetches a list of all machines from the webservice.
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param organizationId The id of the organization
* @param embedOptions The {@link JDMachineEmbedOptions} which should be embedded to the response (bitmask)
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchMachinesWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                       organizationId:(NSString *_Nonnull)organizationId
                                         embedOptions:(JDMachineEmbedOptions)embedOptions
                          completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDMachine *> *_Nullable,
                                                                        NSError *_Nullable,
                                                                        JDResponse *_Nullable))completionBlock;

/**
* Fetches a list of all machines from the webservice with the default configuration.
* @param organizationId The id of the organization
* @param embedOptions The {@link JDMachineEmbedOptions} which should be embedded to the response (bitmask)
* @param completionBlock The completion block
* @param includeInactive Pass yes if the api call should also include inactive machines.
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchMachinesWithOrganizationId:(NSString *_Nonnull)organizationId
                                          embedOptions:(JDMachineEmbedOptions)embedOptions
                                       includeInactive:(BOOL)includeInactive
                           completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDMachine *> *_Nullable,
                                                                         NSError *_Nullable,
                                                                         JDResponse *_Nullable))completionBlock;

/**
* Fetches a list of all machines from the webservice.
* @param requestConfiguration The request configuration (ETag, timeout, ...)
* @param organizationId The id of the organization
* @param embedOptions The {@link JDMachineEmbedOptions} which should be embedded to the response (bitmask)
* @param includeInactive Pass yes if the api call should also include inactive machines.
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchMachinesWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                       organizationId:(NSString *_Nonnull)organizationId
                                         embedOptions:(JDMachineEmbedOptions)embedOptions
                                      includeInactive:(BOOL)includeInactive
                          completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDMachine *> *_Nullable,
                                                                        NSError *_Nullable,
                                                                        JDResponse *_Nullable))completionBlock;

/**
 * Fetches the last known location for the given machine. For this request it doesn't matter if the position was
 * uploaded via a MTG or the Breadcrumb API.
 *
 * @param machineId The Id of the machine, for which the location should be fetched.
 * @param completionBlock The completion block which will be called after finishing the request.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)fetchLastKnownLocationForMachineId:(NSString *_Nonnull)machineId
                              completionBlockWithResponse:
                                  (void (^_Nonnull)(JDMachineGeoLocation *_Nullable machine, NSError *_Nullable error,
                                                    JDResponse *_Nullable response))completionBlock;

/**
 * Post a machine location breadcrumb for a specified machine to the webservice.
 * @param machineLocationBreadcrumb The breadcrumb to post.
 * @param machineId The machine identifier this breadcrumb is for.
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)createMachineLocationBreadcrumb:(JDBreadcrumb *_Nonnull)breadcrumb
                                             machineId:(NSString *_Nonnull)machineId
                                       completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable result,
                                                                         NSError *_Nullable error))completionBlock;

/**
 * Sends a post request which starts an active mtg module of a machine.
 * Starting the module will send mtg satalite data to the backend.
 * Only works if the machine has an active module.
 * When successful this returns status code 204.
 *
 * @param machineId The id of the machine, for which the mtg should be started.
 * @param completionBlock The completion block.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)startLocationStreamEvents:(NSString *_Nonnull)machineId
                                 completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable result,
                                                                   NSError *_Nullable error))completionBlock;

#pragma mark - Deprecated

/**
* @deprecated use {@link #fetchMachinesWithOrganizationId:(NSString *) embedOptions:(JDMachineEmbedOptions)
* completionBlock:(void (^)(NSArray *machines, NSError *error));} instead
*/
+ (JDRequest *_Nonnull)fetchMachinesWithOrganizationId:(NSString *_Nonnull)organizationId
                                       completionBlock:(void (^_Nonnull)(NSArray<JDMachine *> *_Nullable machines,
                                                                         NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
* @deprecated use {@link #fetchMachinesWithConfiguration:(JDRequestConfiguration *) organizationId:(NSString *)
* embedOptions:(JDMachineEmbedOptions) completionBlock:(void (^)(NSArray *machines, NSError *error));} instead
*/
+ (JDRequest *_Nonnull)fetchMachinesWithConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                                       organizationId:(NSString *_Nonnull)organizationId
                                      completionBlock:(void (^_Nonnull)(NSArray<JDMachine *> *_Nullable machines,
                                                                        NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
