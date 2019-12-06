//
//  JDRequest.h
//  JDServices
//
//  Created by Fischer Arne on 2015-10-02
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

@class JDRequest;
@class JDAPIBaseObject;

#import "JDRequestConfiguration.h"
#import "JDResponse.h"
#import "JDURL.h"

// TODO: Move to contract
extern NSString *_Nonnull const kJDUrlParamCount;
extern NSString *_Nonnull const kJDUrlParamEmbed;
extern NSString *_Nonnull const kJDUrlParamStart;
extern NSUInteger const kJDUrlParamCountMaxValue;
extern NSString *_Nonnull const kJDUrlParamStatus;

extern NSString *_Nonnull const kHeaderContentTypeJson;
extern NSString *_Nonnull const kHeaderContentTypeJsonV2;
extern NSString *_Nonnull const kHeaderContentTypeJsonV3;
extern NSString *_Nonnull const kHeaderContentTypeImageJsonV3;
extern NSString *_Nonnull const kHeaderContentTypeGeoJson;
extern NSString *_Nonnull const kHeaderContentTypeOctetStream;
extern NSString *_Nonnull const kHeaderContentTypeZip;
extern NSString *_Nonnull const kHeaderKeyAccept;
extern NSString *_Nonnull const kHeaderKeyAcceptLanguage;
extern NSString *_Nonnull const kHeaderKeyAuthorization;
extern NSString *_Nonnull const kHeaderKeyContentType;
extern NSString *_Nonnull const kHeaderKeyUomSystem;
extern NSString *_Nonnull const kHeaderKeyYieldPreference;
extern NSString *_Nonnull const kJDServerHeaderETag;
extern NSString *_Nonnull const kJDServerHeaderETagStatus;
extern NSString *_Nonnull const kJDServerHeaderTermsLocation;

/**
 * @brief The JDRequestDelegate can be used to receive progress notifications on a request.
 */
@protocol JDRequestDelegate <NSObject>
/**
 * This function is called on progress update.
 * @param progress The progress between 0.0 and 1.0
 */
- (void)request:(JDRequest *_Nonnull)request progressUpdate:(float)progress;
@end

/**
 * @brief The JDRequestEmbed.
 */
@protocol JDRequestEmbed <NSObject>
/**
 * Returns a list of the embed strings for a URL.
 * @param embedOptions The options to embed
 * @return An array with the string equivalents
 */
+ (NSArray<NSString *> *_Nullable)embeddedKeysForOptions:(NSUInteger)embedOptions;
@end

/**
 * @brief Helper for MyJohnDeere API requests.
 */
@interface JDRequest : NSObject
/**
 * The delegate.
 */
@property(nonatomic, weak, nullable) id<JDRequestDelegate> delegate;

/**
 * This array contains all tasks belonging to the request.
 * Tasks may be added while the request is executed.
 */
@property(nonatomic, strong, nullable) NSMutableArray<NSURLSessionTask *> *sessionTasks;

/**
 * This holds all currently fetched objects.
 */
@property(nonatomic, strong) NSMutableArray *_Nullable resultList;

/**
 * Cancel the request.
 * This cancels all tasks for this request.
 */
- (void)cancel;

/**
 * Add a session task to the local array.
 */
- (void)addNSURLSessionTask:(NSURLSessionTask *_Nonnull)sessionTask;

#pragma mark Fetch

/**
 * Fetches a single object and parses it to a given class.
 * @param entityClass The class of the fetched object (must conform to JDJsonObject)
 * @param requestURL The URL of the request
 * @param requestConfiguration The configuration of the request
 * @param completionBlock The completion block
 */
+ (JDRequest *_Nonnull)fetchObjectWithClass:(Class _Nonnull)objectClass
                                 requestURL:(JDURL *_Nonnull)requestURL
                       requestConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                            completionBlock:(void (^_Nullable)(JDAPIBaseObject *_Nullable, NSError *_Nullable,
                                                               JDResponse *_Nullable))completionBlock;

/**
 * Fetches a list of entities with pagination handling.
 * @param entityClass The class of the fetched object (must conform to JDJsonObject)
 * @param requestURL The URL of the request
 * @param requestConfiguration The configuration of the request
 * @param completionBlock The completion block
 */
+ (JDRequest *_Nonnull)fetchListWithClass:(Class _Nonnull)objectClass
                               requestURL:(JDURL *_Nonnull)requestURL
                     requestConfiguration:(JDRequestConfiguration *_Nonnull)requestConfiguration
                          completionBlock:(void (^_Nullable)(NSArray *_Nullable, NSError *_Nullable,
                                                             JDResponse *_Nullable))completionBlock;

@end
