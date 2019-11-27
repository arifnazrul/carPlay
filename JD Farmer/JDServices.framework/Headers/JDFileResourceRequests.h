//
//  JDFileResourceRequests.h
//  JDServices
//
//  Created by Antonacci Luca on 2015-11-19
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDRequest.h"
#import "JDFileResource.h"

@class JDResponse;

/**
 * @brief API requests for {@link JDFileResource}.
 */
@interface JDFileResourceRequests : NSObject

/**
 * Downloads the data of a given file resource.
 * @param fileResourceId The ID of the file resource to be requested for the data.
 * @param completionBlock The completion block. Passes an NSError object when the resource doesn't exist or the file
 * resource has no associated data.
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)fetchFileResourceDataForFileResourceWithId:(NSString *_Nonnull)fileResourceId
                                      completionBlockWithResponse:
                                          (void (^_Nonnull)(NSData *_Nullable, NSError *_Nullable,
                                          JDResponse *_Nullable))completionBlock;

/**
 * Creates a file resource for the given note. This methods creates the plain resource object, only. To associate data
 * to the newly created file resource, you have to invoke the putFileResourceData:forFileResourceWithId:completionBlock:
 * method and pass the ID of the new file resource.
 * @param fileResource The {@link JDFileResource} object. At least the mimeType parameter must be set.
 * @param noteId The ID of the note file resource shall be attached to.
 * @param organizationId The id of the organization the note and the file resource belong to.
 * @param completionBlock The completion block. The URL of the new file resource is located under the "Location" key of
 * the response dictionary.
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)postFileResource:(JDFileResource *_Nonnull)fileResource
                                 noteId:(NSString *_Nonnull)noteId
                         organizationId:(NSString *_Nonnull)organizationId
                        completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                          NSError *_Nullable error))completionBlock;

/**
 * Deletes a file resource for the given id from the webservice.
 * @param fileResourceId The id of the file resource
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)deleteFileResourceWithId:(NSString *_Nonnull)fileResourceId
                                completionBlock:
                                    (void (^_Nonnull)(NSDictionary *_Nullable, NSError *_Nullable))completionBlock;

/**
 * Uploads data for a given file resource. The current data of the file resource gets overridden.
 * @param URL to the file to be uploaded.
 * @param fileResourceId The ID of the resource the data shall be associated with.
 * @param completionBlock The completion block.
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)putFileResourceFromFile:(NSURL *_Nonnull)fileURL
                         forFileResourceWithId:(NSString *_Nonnull)fileResourceId
                               completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                                 NSError *_Nullable error))completionBlock;

/**
 * Uploads data for a given file resource. The current data of the file resource gets overridden.
 * @param file resource data to be uploaded.
 * @param fileResourceId The ID of the resource the data shall be associated with.
 * @param completionBlock The completion block.
 * @return A {@link JDRequest} object which contains the tasks this request is performing
 */
+ (JDRequest *_Nonnull)putFileResourceData:(NSData *_Nonnull)data
                     forFileResourceWithId:(NSString *_Nonnull)fileResourceId
                           completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                             NSError *_Nullable error))completionBlock;

#pragma mark Deprecated

/**
 * @deprecated
 */
+ (JDRequest *_Nonnull)fetchFileResourceDataForFileResourceWithId:(nonnull NSString *)fileResourceId
                                                  completionBlock:
                                                      (void (^_Nonnull)(NSData *_Nullable data,
                                                                        NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
