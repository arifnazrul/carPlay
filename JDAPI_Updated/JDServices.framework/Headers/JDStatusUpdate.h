//
//  JDStatusUpdate.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-12-16
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

/**
 * @brief Status Change for {@link JDJob}, {@link JDWorkAssignment} and {@link JDWorkRecord}.
 */

@interface JDStatusUpdate : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, strong, nullable) NSString *ident;
@property(nonatomic, strong, nullable) NSDate *recordedAt;
@property(nonatomic, strong, nullable) NSString *status;
@property(nonatomic, strong, nullable) NSString *source;
@property(nonatomic, strong, nullable) NSString *sourceGuid;

@end
