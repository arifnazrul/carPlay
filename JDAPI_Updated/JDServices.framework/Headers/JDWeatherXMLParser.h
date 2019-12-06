//
//  JDWeatherXMLParser.h
//  JDServices
//
//  Created by Sebastian Bott on 2015-04-27
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <CoreLocation/CoreLocation.h>

@class JDWeather;

/**
 * @brief Parser for the DTN weather request.
 */
@interface JDWeatherXMLParser : NSObject <NSXMLParserDelegate>

/**
 * The coordinate for the weather as WGS84.
 */
@property(nonatomic) CLLocationCoordinate2D coordinate;

/**
* Parses the DTN weather response xml from the xmlParsers.
* @param response The XML Parser
*/
- (void)startParsingWithXmlParser:(NSXMLParser *_Nonnull)xmlParser
                       completion:
                           (void (^_Nonnull)(JDWeather *_Nullable weather, NSError *_Nullable error))completionBlock;

/**
* Tells the delegate that the parsing was successful.
* @param uiWeather The parsed weather object
*/
- (void)startParsingWithResponseString:(NSString *_Nullable)responseString
                            completion:(void (^_Nonnull)(JDWeather *_Nullable weather,
                                                         NSError *_Nullable error))completionBlock;

@end
