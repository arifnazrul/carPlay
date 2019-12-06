//
//  JDEnabledToggles.h
//  JDServices
//
//  Created by Tobias Riesbeck on 2019-04-26
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@interface JDEnabledToggles : JDAPIBaseObject

@property(nonatomic, strong, nonnull) NSArray<NSString *> *names;

@end