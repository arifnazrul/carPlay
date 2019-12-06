//
//  JDAwsAssetLocationsAccessTokenRequestContract.h
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

#import "JDRequestContract.h"

@class JDURL;

/**
 * @brief Request contract for {@link JDAwsAssetLocationsAccessTokenRequests}.
 */
@interface JDAwsAssetLocationsAccessTokenRequestContract : JDRequestContract

/**
 * Machine id to publish locations for
 */
@property(nonatomic, assign) NSInteger machineId;

/**
 * Organization id to subscribe asset locations for.
 */
@property(nonatomic, assign) NSInteger orgId;

/**
 * Unique application id.
 */
@property(nonatomic, copy, nullable) NSString *applicationId;

/**
 * {@code YES} if the client needs publish access to the machine specific IoT queue for asset locations.
 */
@property(nonatomic, assign) BOOL allowPublishLocationsIoT;

/**
 * {@code YES} if the client needs to subscribe to the asset location IoT queue.
 */
@property(nonatomic, assign) BOOL allowSubscribeOrgLocations;

/**
 * IoT topic version.
 */
@property(nonatomic, strong, nullable) NSString *iotTopicVersion;

/**
 * Contribution definition id.
 */
@property(nonatomic, strong, nullable) NSString *contributionDefId;

/**
 * Default contract with the mandatory properties.
 * @return The contract
 */
+ (instancetype _Nonnull)contract;

@end
