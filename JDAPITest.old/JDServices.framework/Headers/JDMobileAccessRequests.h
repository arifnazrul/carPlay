//
//  JDMobileAccessRequests.h
//  JDServices
//
//  Created by Riesbeck Tobias on 2016-03-07
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDRequest;
@class JDResponse;

/**
 * @brief Provides requests to check if the current user is allowed to access Deere & Company software.
 */
@interface JDMobileAccessRequests : NSObject

/**
 * Requests the mobile access status for the current user.
 *
 * @param completionBlock A delegate method that is called after the fetch has finished.
 *                        The bool parameter of this block shows, whether the user is permitted or not.
 * @return The request containing the task that fetches the access permission status.
 */
+ (JDRequest *_Nonnull)fetchMobileAccessPermissionWithCompletionBlock:
    (void (^_Nonnull)(BOOL, NSError *_Nullable, JDResponse *_Nullable))completionBlock;

@end