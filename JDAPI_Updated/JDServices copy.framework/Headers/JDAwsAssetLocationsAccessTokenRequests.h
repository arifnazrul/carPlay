//
//  JDAwsAssetLocationsAccessTokenRequests.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-12-06
//
//  Unpublished Work (c) 2017 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDRequest;
@class JDResponse;
@class JDAwsAssetLocationsAccessTokenRequestContract;
@class JDAwsAssetLocationsAccessToken;

/**
 * @brief Retreive the temporary cognito credentials for the current user having required access rights to AWS
 * resources.
 */
@interface JDAwsAssetLocationsAccessTokenRequests : NSObject

/**
 * Retreive the temporary cognito credentials for the currently logged in MyJohnDeere user. With parameters specified,
 * credentials receive additional permissions to access AWS resources needed to publish asset locations or subscribe to
 * them. Furthermore, depending on the used parameters, response can contain other access information such as IoT topics
 * names and client name. The following parameter combinations are valid:
 *
 * @param contract The request contract
 *  - If allowPublishLocationsIoT=true then machineId MUST be specified
 *  - If allowSubscribeOrgLocations=true then orgId MUST be specified
 *  - At least one of allowPublishLocationsIoT, allowSubscribeOrgLocations MUST be true
 * @param completionBlock The completion block
 * @return The request containing the task that fetches the URL
 */
+ (JDRequest *_Nonnull)
fetchAwsAssetLocationsAccessTokenWithContract:(JDAwsAssetLocationsAccessTokenRequestContract *_Nonnull)contract
                              completionBlock:(void (^_Nonnull)(JDAwsAssetLocationsAccessToken *_Nullable,
                                                                NSError *_Nullable,
                                                                JDResponse *_Nullable))completionBlock;

@end
