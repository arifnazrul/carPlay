//
//  JDLocalizedText.h
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

/**
 * @brief Text with localization for {@link JDWorkAnswer} and {@link JDWorkQuestion}
 * @author Bott Sebastian
 */
@interface JDLocalizedText : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSString *ident;
@property(nonatomic, strong, nullable) NSString *text;
@property(nonatomic, strong, nullable) NSString *language;

@end
