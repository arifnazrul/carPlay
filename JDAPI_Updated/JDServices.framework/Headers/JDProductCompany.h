//
//  JDProductCompany.h
//  JDServices
//
//  Created by Tobias Riesbeck on 2019-08-02
//
//  Unpublished Work (c) 2019 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@interface JDProductCompany : JDAPIBaseObject

/**
 * The name of the company.
 */
@property(nonatomic, strong, nonnull) NSString *companyName;

@end