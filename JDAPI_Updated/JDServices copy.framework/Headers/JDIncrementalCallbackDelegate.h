//
//  JDIncrementalCallbackDelegate.h
//  JDServices
//
//  Created by Fischer Arne on 2016-07-05
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDAPIBaseObject;

/**
 * @brief Set a implementation of this delegate on a JDRequestConfiguration which is passed to a request to activate
 * incremental parsing. If incremental parsing is activated the completion block of the request will not contain any
 * data. For each root object parsed the method in this delegate will be called.
 */
@protocol JDIncrementalCallbackDelegate <NSObject>

/**
 * Finished parsing a object. This will be called for every root object parsed.
 * The underlying API will no longer reference the object after this call. This is so the objects are dereferenced
 * to save memory. The mechanism is used to parse very large amounts of data.
 * The Object will be of the expected type for the request (e.g. a JobRequest will pass a JDJob).
 */
- (void)didParseAPIObject:(id _Nonnull)object;

@end
