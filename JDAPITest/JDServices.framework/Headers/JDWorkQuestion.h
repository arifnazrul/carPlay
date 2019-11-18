//
//  JDWorkQuestion.h
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
#import "JDLocalizedText.h"
#import "JDPossibleAnswer.h"

extern NSString *_Nonnull const kJDWorkQuestionTypeBoolean;
extern NSString *_Nonnull const kJDWorkQuestionTypeObservation;
extern NSString *_Nonnull const kJDWorkQuestionTypeMeasurement;
extern NSString *_Nonnull const kJDWorkQuestionTypeFreeText;

/**
 * @brief Work Question for a {@link JDJob}.
 */
@interface JDWorkQuestion : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *questionType;
@property(nonatomic, copy, nullable) NSString *vrDomainId;
@property(nonatomic, copy, nullable) NSArray<JDLocalizedText *> *questionTexts;
@property(nonatomic, copy, nullable) NSArray<JDPossibleAnswer *> *possibleAnswers;
@property(nonatomic, copy, nullable) NSArray<NSString *> *operationTypes;

@end
