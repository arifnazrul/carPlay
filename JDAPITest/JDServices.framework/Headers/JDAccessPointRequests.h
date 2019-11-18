//
//  JDAccessPointRequests.h
//  JDServices
//
//  Created by Rico Dewein on 2016-06-06
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//
@class JDRequest;
@class JDAccessPoint;

/**
 * @brief API requests for {@link JDAccessPoint}.
 */
@interface JDAccessPointRequests : NSObject

/**
* Creates or updates a accessPoint with the given payload.
* @param accessPoint The accessPoint
* @param organizationId The ID of the organization
* @param locationId The ident of the location
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)createOrUpdateAccessPoint:(JDAccessPoint *_Nonnull)accessPoint
                                  organizationId:(NSString *_Nonnull)organizationId
                                      locationId:(NSString *_Nonnull)locationId
                                 completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                                   NSError *_Nullable error))completionBlock;

/**
* Deletes an accesspoint with the given ID.
 * @param accessPoint The id of the accessPoint
 * @param organizationId The ID of the organization
 * @param locationId The Id of the location
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)deleteAccessPointWithId:(NSString *_Nonnull)accessPointId
                                organizationId:(NSString *_Nonnull)organizationId
                                    locationId:(NSString *_Nonnull)locationId
                               completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                                 NSError *_Nullable error))completionBlock __deprecated;

/**
* Deletes an accesspoint with the given ID.
 * @param accessPointId The id of the accessPoint
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)deleteAccessPointWithId:(NSString *_Nonnull)accessPointId
                               completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                                 NSError *_Nullable error))completionBlock;

@end