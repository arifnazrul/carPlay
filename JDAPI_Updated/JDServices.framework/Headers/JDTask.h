//
//  JDTask.h
//  JDServices
//
//  Created by Bott Sebastian on 2017-12-05
//
//  Unpublished Work (c) 2017 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"
#import "JDServicesConstants.h"
#import <Foundation/Foundation.h>

/**
 * @brief Task for a {@link JDJob}.
 */
@interface JDTask : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *guid;
@property(nonatomic, assign) BOOL active;

@end
