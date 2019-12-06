//
//  JDUserRequests.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-02-11
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDUser.h"
#import "JDRequestConfiguration.h"
#import "JDRequest.h"

@class JDResponse;
@class JDStaff;

/**
 * @brief API requests for {@link JDUser}.
 */
@interface JDUserRequests : NSObject

/**
 * Fetches the current user from the webservice.
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)fetchCurrentUserWithCompletionBlockWithResponse:
    (void (^_Nonnull)(JDUser *_Nullable, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

/**
 * Fetches the preferred organization id for a given account name.
 * @param accountName The account name of the user
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchPreferredOrganizationIdForUser:(NSString *_Nonnull)accountName
                               completionBlockWithResponse:(void (^_Nonnull)(NSString *_Nullable, NSError *_Nullable,
                                                                             JDResponse *_Nullable))completionBlock;

/**
 * Fetch all users for a specified organization.
 * @param organizationId The organization id.
 * @param completionBlock The completion block is called when the request completes.
 */
+ (JDRequest *_Nonnull)fetchStaffForOrganizationId:(NSString *_Nonnull)organizationId
                       completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDStaff *> *_Nullable, NSError *_Nullable,
                                                                     JDResponse *_Nullable))completionBlock;

/**
 * Fetch all users for a specified organization.
 * @param organizationId The organization id.
 * @param configuration The configuration for this request.
 * @param completionBlock The completion block is called when the request completes.
 */
+ (JDRequest *_Nonnull)fetchStaffForOrganizationId:(NSString *_Nonnull)organizationId
                                     configuration:(JDRequestConfiguration *_Nonnull)configuration
                       completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDStaff *> *_Nullable, NSError *_Nullable,
                                                                     JDResponse *_Nullable))completionBlock;

#pragma mark Deprecated

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchCurrentUserWithCompletionBlock:
    (void (^_Nonnull)(JDUser *_Nullable, NSError *_Nullable))completionBlock DEPRECATED_ATTRIBUTE;

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchPreferredOrganizationIdForUser:(NSString *_Nonnull)accountName
                                           completionBlock:(void (^_Nonnull)(NSString *_Nullable,
                                                                             NSError *_Nullable))completionBlock
    DEPRECATED_ATTRIBUTE;

/**
* @deprecated use {@link #fetchCurrentUserWithCompletionBlockWithResponse:(NSString *) completionBlock:(void (^)(NSArray
* *machines,
* NSError *error));} instead
*/
+ (void)currentUserWithCompletionBlock:
    (void (^_Nullable)(JDUser *_Nullable user, NSError *_Nullable error))completionBlock DEPRECATED_ATTRIBUTE;

@end
