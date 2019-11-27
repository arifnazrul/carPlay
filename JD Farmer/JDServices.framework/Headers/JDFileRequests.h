//
//  JDFileRequests.h
//  JDServices
//
//  Created by Sampath Kunta on 2014-09-08
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDFileInfo.h"

typedef NS_ENUM(NSUInteger, JDFilterType) { JDFilterTypeMachine, JDFilterTypeAll };
extern NSString *const JDFilterType_toString[];

typedef void (^JDFileUploadManagerDidFinishEventsForBackgroundURLSessionBlock)(NSURLSession *session);

@class JDFileRequestInfo;

/**
 * @brief API requests for files.
 */

@interface JDFileRequests : NSObject

+ (instancetype)sharedJDFileRequests;

#pragma mark - Utility methods
- (void)getStatusOfFileWithId:(NSString *)fileId
               withCompletion:(void (^)(JDFileStatus fileStatus, NSError *error))completionBlock;

#pragma mark - File list request methods
- (void)getListOfFilesForOrgId:(NSString *)orgId
                withFilterType:(JDFilterType)filterType
                      fileType:(JDFileType)fileType
                    startIndex:(uint)startIndex
                         count:(uint)count
                      archived:(BOOL)archived

               completionBlock:(void (^)(JDFileRequestInfo *fileRequestInfo, NSError *error))completionBlock;
- (void)getListOfFilesForOrgId:(NSString *)orgId
                withFilterType:(JDFilterType)filterType
                      fileType:(JDFileType)fileType
                    startIndex:(uint)startIndex
                         count:(uint)count
                      archived:(BOOL)archived
                     startDate:(NSDate *)startDate
                       endDate:(NSDate *)endDate
               completionBlock:(void (^)(JDFileRequestInfo *, NSError *))completionBlock;

- (void)getListOfFilesFromURLString:(NSString *)urlString
                    completionBlock:(void (^)(JDFileRequestInfo *, NSError *))completionBlock;

#pragma mark - File download requests
- (void)downloadFileFromURL:(NSURL *)fileURL
                      toURL:(NSURL *)destinationURL
                   progress:(NSProgress *__autoreleasing *)progress
             withCompletion:(void (^)(NSError *error))completionHandler;

#pragma mark - File upload requests
@property(nonatomic, copy)
    JDFileUploadManagerDidFinishEventsForBackgroundURLSessionBlock didFinishEventsForBackgroundURLSessionBlock;

// Gets fileId form My John Deere for a particular organizaiton
- (void)fileIdForFileNamed:(NSString *)fileName
                     orgId:(NSString *)orgId
            withCompletion:(void (^)(NSString *fileId, NSError *error))completionHandler;

// uploads a file from the local file system
- (void)uploadFileFromURL:(NSURL *)fileURL
               withFileId:(NSString *)fileId
                 progress:(NSProgress *__autoreleasing *)progress
           withCompletion:(void (^)(NSURLResponse *response, id responseObject, NSError *error))completionHandler;

- (void)cancelAllUploadTasks;

@end
