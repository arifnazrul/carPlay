//
//  JDIconStyle.h
//  JDServices
//
//  Created by Chahare Vinit on 10/05/19.
//  Copyright © 2019 Deere & Company. All rights reserved.
//

#import "JDAPIBaseObject.h"

@interface JDIconStyle : JDAPIBaseObject

@property(nonatomic, copy, nullable) NSString *primaryColor;
@property(nonatomic, copy, nullable) NSString *secondaryColor;
@property(nonatomic, copy, nullable) NSString *stripeColor;

@end
