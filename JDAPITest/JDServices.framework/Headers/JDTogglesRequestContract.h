//
//  JDTogglesRequestContract.h
//  JDServices
//
//  Created by Tobias Riesbeck on 2019-04-30
//
//  Unpublished Work (c) 2019 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDRequestContract.h"

@interface JDTogglesRequestContract : JDRequestContract

/**
 * User account name for the toggles.
 */
@property(nonatomic, strong, nullable) NSString *userName;

/**
 * ID of the Organization for the toggles.
 */
@property(nonatomic, strong, nullable) NSString *orgId;

@end