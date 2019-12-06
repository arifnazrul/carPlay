//
//  JDPreSignedUrlRequests.h
//  JDServices
//
//  Created by Riesbeck Tobias on 2016-03-07
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDRequest;
@class JDResponse;

extern NSString *_Nonnull const kJDPreSignedUrlRequestRegionUSEast;
extern NSString *_Nonnull const kJDPreSignedUrlRequestRegionEUCentral;

/**
 * @brief Provides requests to receive a pre signed URL for a file download from AWS.
 */
@interface JDPreSignedUrlRequests : NSObject

/**
 * Fetches a pre signed URL for a specific file on the AWS.
 *
 * @param bucketName The name of the bucket from which files should be downloaded.
 * @param bucketRegion Determines to which AWS server center the request will be sent.
 * @param objectKey The path of the file persisted by the AWS.
 * @param completionBlockWithResponse A delegate method that is called after the fetch has finished.
 * @return The request containing the task that fetches the URL.
 */
+ (JDRequest *_Nonnull)fetchPreSignedUrlWithBucketName:(NSString *_Nonnull)bucketName
                                          bucketRegion:(NSString *_Nonnull)bucketRegion
                                             objectKey:(NSString *_Nonnull)objectKey
                           completionBlockWithResponse:(void (^_Nonnull)(NSString *_Nullable, NSError *_Nullable,
                                                                         JDResponse *_Nullable))completionBlock;

@end