//
//  JDPrescription.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-06-14
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDAPIBaseObject.h"

@class JDFileInfo;

/**
 * @brief Prescription for {@link JDPrescriptionAssignment}.
 * @author Bott Sebastian
 */
@interface JDPrescription : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, strong, nullable) JDFileInfo *file;
@property(nonatomic, copy, nullable) NSDate *dateCreated;

@end
