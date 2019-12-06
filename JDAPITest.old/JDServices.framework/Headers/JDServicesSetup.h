//
//  JDServicesSetup.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-10-08
//
//  Unpublished Work (c) 2015 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import <AFNetworking/AFNetworkReachabilityManager.h>

@class JDEnvironmentConfiguration;
@class JDRequestConfiguration;

/**
 * @brief MyJohnDeere Environment.
 */
typedef NS_ENUM(NSUInteger, JDEnvironment) {
    /**
    * DEVL environment.
    */
    JDEnvironmentDEV = 1,
    /**
    * QUAL environment.
    */
    JDEnvironmentQA = 2,
    /**
    * CERT environment.
    */
    JDEnvironmentCERT = 3,
    /**
    * PROD environment (without SOA proxy).
    */
    JDEnvironmentPROD = 4,
    /**
    * Custom SANDBOX environment.
    */
    JDEnvironmentSANDBOX = 5,
    /**
    * PROD environment (with SOA proxy)
    */
    JDEnvironmentSTORE = 6
};

extern NSString *_Nonnull const kJDEnvironmentDEV;
extern NSString *_Nonnull const kJDEnvironmentQA;
extern NSString *_Nonnull const kJDEnvironmentCERT;
extern NSString *_Nonnull const kJDEnvironmentPROD;
extern NSString *_Nonnull const kJDEnvironmentSTORE;
extern NSString *_Nonnull const kJDEnvironmentSANDBOX;


/**
 * @brief Initialization for JDServices with https://developer.deere.com keys.
 */
@interface JDServicesSetup : NSObject

/**
 * Overrides the keychain group identifier. Default is the bundle identifier of the app.
 * @param keychainGroup The keychainGroup
 */
+ (void)setKeychainGroup:(nonnull NSString *)keychainGroup;

/**
 * Initializes JDServices with the default environment.
 * @param consumerKey The OAuth consumer key
 * @param secretKey The OAuth secret key
 */
+ (void)setupConsumerKey:(nonnull NSString *)consumerKey andSecretKey:(nonnull NSString *)secretKey;

/**
 * Initializes JDServices.
 * @param environment The MyJohnDeere environment
 * @param consumerKey The OAuth consumer key
 * @param secretKey The OAuth secret key
 */
+ (void)setupEnvironment:(enum JDEnvironment)environment
         withConsumerKey:(nonnull NSString *)consumerKey
            andSecretKey:(nonnull NSString *)secretKey;

/**
 * Sets the active environment.
 * @param environment The environment. The parameter will be ignored if the user has selected an environment!
 */
+ (void)setActiveEnvironment:(enum JDEnvironment)environment;

/**
 * Sets the active environment with a specific keychain group.
 * Default is STORE.
 * @param environment The environment. The parameter will be ignored if the user has selected an environment!
 * @param keychainGroup The keychain group, usually the bundle identifier of the app
 */
+ (void)setActiveEnvironment:(enum JDEnvironment)environment keychainGroup:(nullable NSString *)keychainGroup;

/**
 * Initializes a custom SANDBOX environment.
 * @param environmentConfiguration The sandbox environment configuration
 */
+ (void)setupSandboxEnvironmentWithConfiguration:(nonnull JDEnvironmentConfiguration *)environmentConfiguration;

/**
 * Returns the active environment.
 * @return The John Deere environment
 */
+ (enum JDEnvironment)activeEnvironment;

/**
 * Returns the keychain group.
 * @return The keychain group
 */
+ (nonnull NSString *)keychainGroup;

/**
 * Returns the active environment configuration.
 * @return The active John Deere environment configuration
 */
+ (nullable JDEnvironmentConfiguration *)activeEnvironmentConfiguration;

/**
 * Converts the passed environment enum to a matching string.
 * @return The string for an environment.
 */
+ (nonnull NSString *)stringForJDEnvironment:(enum JDEnvironment)environment;

/**
 * Resets the setup for all environments.
 */
+ (void)reset;

/**
 * Checks if a given environment is initialized with consumer and secret key.
 * @param environment The environment
 * @return <code>YES</code> if the the environment is initialized, otherwise <code>NO</code>
 */
+ (BOOL)isEnvironmentInitialized:(enum JDEnvironment)environment;

@end
