//
//  JDRequestContract.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-12-11
//
//  Unpublished Work (c) 2017 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDRequestConfiguration;
@class JDURL;

/**
 * @brief Request contract for a {@link JDRequest}.
 */
@interface JDRequestContract : NSObject

/**
 * The request configuration (ETag, timeout, ...)
 */
@property(nonatomic, strong, nonnull) JDRequestConfiguration *configuration;

/**
 * Creates the URL for the Axiom endpoint.
 * @return The URL
 */
- (JDURL *_Nonnull)createRequestURL;

@end
