//
//  JDEnvironmentConfiguration.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-10-08
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

/**
 * @brief Configuration for the MyJohnDeere environment {@link JDEnvironment}.
 */
@interface JDEnvironmentConfiguration : NSObject

@property(nonatomic, copy, nonnull) NSString *baseURL;
@property(nonatomic, copy, nonnull) NSString *akanaBaseURL;
@property(nonatomic, copy, nonnull) NSString *consentToUseDataURI;
@property(nonatomic, copy, nullable) NSString *scopeURI;
@property(nonatomic, copy, nullable) NSString *consumerKey;
@property(nonatomic, copy, nullable) NSString *secretKey;

/**
 * Default configuration for the DEV environment.
 */
+ (instancetype _Nonnull)environmentConfigurationDEV;

/**
 * Default configuration for the QA environment.
 */
+ (instancetype _Nonnull)environmentConfigurationQA;

/**
 * Default configuration for the CERT environment.
 */
+ (instancetype _Nonnull)environmentConfigurationCERT;

/**
 * Default configuration for the PROD environment.
 */
+ (instancetype _Nonnull)environmentConfigurationPROD;

/**
 * Default configuration for the STORE environment.
 */
+ (instancetype _Nonnull)environmentConfigurationSTORE;

@end
