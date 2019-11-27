//
//  JDUnitOfMeasureType.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-06-16
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

typedef NS_ENUM(NSUInteger, JDUnitOfMeasureType) {
    JDUnitOfMeasureTypeMetric = 0,
    JDUnitOfMeasureTypeEnglish,
    JDUnitOfMeasureTypeMixed,
    JDUnitOfMeasureTypeUnknown
};

/**
 * @brief The UnitOfMeasure system.
 * @author Bott Sebastian
 */
@interface JDUnitOfMeasureSystem : NSObject

/**
 * Returns the string for a {@link JDUnitOfMeasureType}.
 * @return The UnitOfMeasure system key
 */
+ (NSString *)stringFromUnitOfMeasureType:(JDUnitOfMeasureType)unitOfMeasureType;

@end
