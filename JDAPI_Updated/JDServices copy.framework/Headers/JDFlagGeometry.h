//
//  JDFlagGeometry.h
//  JDServices
//
//  Created by Wright Daniel W on 12/11/18.
//  Copyright © 2018 Deere & Company. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, JDFlagGeometryType) {
    JDFlagGeometryTypeUnknown = 0,
    JDFlagGeometryTypePoint = 1,
    JDFlagGeometryTypeLine = 2,
    JDFlagGeometryTypePolygon = 3
};

@interface JDFlagGeometry : NSObject

@property (nonatomic) JDFlagGeometryType type;
@property (nonatomic) NSArray *coordinates;

- (instancetype)initWithType:(JDFlagGeometryType)type coordinates:(NSArray *)coordinates;

@end
