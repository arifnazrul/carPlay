//
//  JDJsonObject.h
//  JDServices
//
//  Created by Sebastian Bott on 2014-12-11
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>

/**
 * @brief Protocol for an object unmarshalled from a JSON source.
 */
@protocol JDJsonObject<NSObject>

/**
 * Initializes the object from a dictionary source.
 * @param dictionary The dictionary
 * @return A new instance of the object
 */
- (instancetype _Nonnull)initWithDictionary:(NSDictionary *_Nonnull)dictionary;

@end

