//
//  JDFirmwareRequests.h
//  JDServices
//
//  Created by Andy Sheehan on 2015-10-26
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDFirmwareInfo.h"

/**
 * @brief API requests for {@link JDFirmwareInfo}.
 */

@interface JDFirmwareRequests : NSObject

/**
 * Fetches the currently available firmware info.
 * @param completionBlock The completion block
 */
+ (void)fetchFirmwareInfoForProduct:(NSNumber *_Nonnull)product
                withCompletionBlock:
                    (void (^_Nonnull)(JDFirmwareInfo *_Nullable info, NSError *_Nullable error))completionBlock;

/**
 * Downloads a specific firmware image.
 * @param baseUrl The base URL
 * @param resource The Resource
 * @param tokenID The token ID
 * @param secretKey The secret key
 * @param destination The destination
 */
+ (BOOL)downloadFirmwareImage:(NSString *_Nonnull)baseUrl
                     resource:(NSString *_Nonnull)resource
                      tokenID:(NSString *_Nonnull)tokenID
                 sharedSecret:(NSString *_Nonnull)secretKey
                  destination:(NSString *_Nonnull)destination;

@end
