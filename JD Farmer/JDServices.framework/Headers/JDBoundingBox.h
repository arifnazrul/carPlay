//
//  JDBoundingBox.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-07-09
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, JDBoundingBoxSpatialReference) {
    JDBoundingBoxSpatialReferenceWGS84,
    JDBoundingBoxSpatialReferenceMercator
};

/**
 * @brief Bounding box of a specific area used by {@link JDWeatherRequests}.
 */
@interface JDBoundingBox : NSObject

@property(nonatomic, assign) CGFloat minX;
@property(nonatomic, assign) CGFloat minY;
@property(nonatomic, assign) CGFloat maxX;
@property(nonatomic, assign) CGFloat maxY;
@property(nonatomic, assign) JDBoundingBoxSpatialReference spatialReference;

/**
 * Generates the formatted string used by the API.
 * @return The formatted string
 */
- (nonnull NSString *)apiFormattedString;


@end
