//
//  JDPossibleAnswer.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-04-22
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import "JDLocalizedText.h"

/**
 * @brief Possible answer for a {@link JDWorkQuestion}
 * @author Bott Sebastian
 */
@interface JDPossibleAnswer : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSString *ident;
@property(nonatomic, strong, nullable) NSArray<JDLocalizedText *> *answerTexts;

@end
