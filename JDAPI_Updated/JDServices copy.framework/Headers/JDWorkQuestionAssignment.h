//
//  JDWorkQuestionAssignment.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-11-18
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDWorkQuestion;

/**
 * @brief Work Question Assignment for a {@link JDWorkPlan}.
 */
@interface JDWorkQuestionAssignment : JDAPIBaseObject <JDAPIPostBody>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, assign) BOOL required;
@property(nonatomic, copy, nullable) NSString *operationType;
@property(nonatomic, strong, nullable) JDWorkQuestion *question;

// TODO: Clearify how to map from operationType to operation.

@end
