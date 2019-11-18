//
//  JDMachineStylePreferencesRequests.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-08-09
//
//  Unpublished Work (c) 2017 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDRequest;
@class JDMachineStylePreferences;
@class JDResponse;
@class JDRequestConfiguration;

/**
 * @brief API requests for {@link JDMachineStylePreference}.
 */

@interface JDMachineStylePreferencesRequests : NSObject

/**
 * Fetches the MachineStylePreferences for a given organization with the default request configuration.
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchMachineStylePreferencesForOrganizationId:(NSString *_Nonnull)organizationId
                                         completionBlockWithResponse:
                                             (void (^_Nonnull)(JDMachineStylePreferences *_Nullable, NSError *_Nullable,
                                                               JDResponse *_Nullable))completionBlock;

/**
 * Fetches the MachineStylePreferences for a given organization with the default request configuration.
 * @param requestConfiguration The request configuration (ETag, timeout, ...)
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchMachineStylePreferencesWithConfiguration:
                           (JDRequestConfiguration *_Nonnull)requestConfiguration
                                                      organizationId:(NSString *_Nonnull)organizationId
                                         completionBlockWithResponse:
                                             (void (^_Nonnull)(JDMachineStylePreferences *_Nullable, NSError *_Nullable,
                                                               JDResponse *_Nullable))completionBlock;

@end
