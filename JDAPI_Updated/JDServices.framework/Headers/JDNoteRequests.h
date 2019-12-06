//
//  JDNoteRequests.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-07-08
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDRequest.h"

@class JDNote;

/**
 * @brief API requests for {@link JDNote}.
 */
@interface JDNoteRequests : NSObject

/**
* Creates or updates a note with the given payload.
* @param note The note
* @param jobId The ident of the job
* @param completionBlock The completion block
* @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)createOrUpdateNote:(JDNote *_Nonnull)note
                                    jobId:(NSString *_Nonnull)jobId
                          completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                            NSError *_Nullable error))completionBlock;

/**
* Deletes a note with the given ID.
 * @param noteId The id of the note
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)deleteNoteWithId:(NSString *_Nonnull)noteId
                        completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                          NSError *_Nullable error))completionBlock;

#pragma mark Deprecated

/**
* Creates a note with the given data.
 * @param text The text of the note
 * @param userAccountName The name of the user account
 * @param jobId The id of the job
 * @param organizationId The id of the organization
 * @param completionBlock The completion block
 * @return A {@link JDRequest} object which contains the tasks this request is performing
*/
+ (JDRequest *_Nonnull)postNoteWithText:(NSString *_Nonnull)text
                        userAccountName:(NSString *_Nonnull)userAccountName
                                  jobId:(NSString *_Nonnull)jobId
                         organizationId:(NSString *_Nonnull)organizationId
                        completionBlock:(void (^_Nonnull)(NSDictionary *_Nullable response,
                                                          NSError *_Nullable error))completionBlock
    DEPRECATED_ATTRIBUTE;

@end
