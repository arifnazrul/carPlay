//
//  JDFileRequestInfo.h
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

/**
 * @brief File Request information.
 */
@interface JDFileRequestInfo : NSObject

@property(nonatomic, copy, nullable) NSString *nextPageURL;
@property(nonatomic, copy, nullable) NSString *prevPageURL;
@property(nonatomic, assign) int totalNumberOfFiles;
@property(nonatomic, copy, nullable) NSArray *files;

@end
