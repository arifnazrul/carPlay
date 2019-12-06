//
//  JDAwsAssetLocationsAccessToken.h
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

#import "JDAPIBaseObject.h"

/**
 * @brief Temporary credentials for an AWS IoT session to receive and send asset locations.
 * @author Bott Sebastian
 */
@interface JDAwsAssetLocationsAccessToken : JDAPIBaseObject

/**
 * AWS IoT endpoint without protocol.
 */
@property(nonatomic, strong, nullable) NSString *iotEndpoint;

/**
 * AWS region.
 */
@property(nonatomic, strong, nullable) NSString *awsRegion;

/**
 * Generated client id allowed to publish and subscribe locations to the given IoT queues.
 */
@property(nonatomic, strong, nullable) NSString *clientId;

/**
 * Temporary user name returned by Cognito.
 */
@property(nonatomic, strong, nullable) NSString *accessKeyId;

/**
 * Temporary password returned by Cognito.
 */
@property(nonatomic, strong, nullable) NSString *secretKey;

/**
 * Session token returned by Cognito.
 */
@property(nonatomic, strong, nullable) NSString *sessionToken;

/**
 * IoT topic name to publish locations for the given machine.
 */
@property(nonatomic, strong, nullable) NSString *machineIoTTopicToPublish;

/**
 * Org-specific topic to subscribe for locations.
 */
@property(nonatomic, strong, nullable) NSString *orgMachineTopicToSubscribe;

/**
 * Date when the token will expire.
 */
@property(nonatomic, strong, nullable) NSDate *expiration;

/**
 * Organization communication topic.
 */
@property(nonatomic, strong, nullable) NSString *orgCommTopic;

@end
