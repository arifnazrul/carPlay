//
//  JDProperties.h
//  JDServices
//
//  Created by Dewein Rico on 2016-09-27
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
 * @brief Porperties of a {@link JDMachineGeoLocation}
 */
@interface JDProperties : JDAPIBaseObject

@property(nonatomic, strong, nullable) NSDate *eventTimestamp;
@property(nonatomic, strong, nullable) NSDate *createTimestamp;

@end
