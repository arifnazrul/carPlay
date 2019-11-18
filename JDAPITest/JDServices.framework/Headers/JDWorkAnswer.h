//
//  JDWorkAnswer.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-12-01
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import "JDSimpleUnitValue.h"
#import "JDPossibleAnswer.h"

@class JDWorkQuestion;

/**
 * @brief Work Answer for {@link JDWorkQuestion}.
 */

@interface JDWorkAnswer : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *uom;
@property(nonatomic, copy, nullable) NSString *value;
@property(nonatomic, strong, nullable) JDWorkQuestion *workQuestion;
@property(nonatomic, strong, nullable) JDPossibleAnswer *possibleWorkAnswer;

- (NSDictionary *_Nonnull)createPostBodyWithJobId:(NSString *_Nullable)jobId
                                      workOrderId:(NSString *_Nullable)workOrderId
                                 workAssignmentId:(NSString *_Nonnull)workAssignmentId;

@end
