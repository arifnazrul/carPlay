//
//  JDResponse.h
//  JDServices
//
//  Created by Fischer Arne on 2016-02-23
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

/**
 * @brief This class contains additional information about the received response.
 */
@interface JDResponse : NSObject

/**
 * This contains the eTag if it was received from the server.
 * This should be saved in the same database transaction as the received data is.
 */
@property(nonatomic, strong, nonnull) NSString *receivedETag;

/** This contains the eTagstatus if it was received from the server.
* This is checked if user has not logged in for long time
*/
@property(nonatomic, strong, nullable) NSString *eTagStatus;

/** This contains the url for which request was processed.
 * This is checked if the etag is saved against this url
 */
@property(nonatomic, strong, nullable) NSString *requestUrl;

/**
 * Links besides the 'values' payload of list requests. May be used to check permissions.
 */
@property(nonatomic, strong, nullable) NSDictionary<NSString *, NSURL *> *links;

/** This contains the Terms & Conditions url as value of header field x-deere-terms-location.
 */
@property(nonatomic, strong, nullable) NSString *termsLocation;

@end
