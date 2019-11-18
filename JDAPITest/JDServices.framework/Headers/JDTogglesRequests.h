//
//  JDTogglesRequests.h
//  JDServices
//
//  Created by Tobias Riesbeck on 2019-04-26
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

@class JDRequest;
@class JDResponse;
@class JDEnabledToggles;
@class JDTogglesRequestContract;

@interface JDTogglesRequests : NSObject

/**
 * Fetches feature toggles for a specific user and a particular organization.
 * @param accountName The account name of the user.
 * @param organizationId The organization id.
 * @param completionBlock The completion which is called after the request has been completed. The block contains an
 * optional response and an error, if an error occurred.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)fetchTogglesWithContract:(JDTogglesRequestContract *_Nonnull)contract
                                completionBlock:(void (^_Nonnull)(JDEnabledToggles *_Nullable result,
                                                                  NSError *_Nullable error,
                                                                  JDResponse *_Nullable response))completionBlock;

@end
