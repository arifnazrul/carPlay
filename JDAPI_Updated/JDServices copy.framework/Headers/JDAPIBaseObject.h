//
//  JDAPIBaseObject.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-05-13
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

@import Foundation;

#import "JDJsonObject.h"
#import "JDObjectMappingUtils.h"
#import "JDServicesConstants.h"
#import "JDURL.h"

/**
 * @brief Protocol to prepare the JSON POST body.
 */
@protocol JDAPIPostBody <NSObject>
/**
 * Returns the POST body to create a new object.
 * @return The POST body dictionary
 */
- (NSDictionary *_Nonnull)createPostBody;
@end

/**
 * Manipulation states of an object.
 */
typedef NS_ENUM(NSUInteger, JDObjectState) {
    // clang-format off
    JDObjectStateAddedOrEdited = 0,
    JDObjectStateDeleted
    // clang-format on
};

/**
 * @brief Basic abstract entity for all JDServices API models which are unmarshalled by a JSON source.
 */
@interface JDAPIBaseObject : NSObject <JDJsonObject, NSCoding>

/**
 * The manipulation state of the object.
 */
@property(nonatomic, assign) JDObjectState objectState;

/**
 * The URI.
 */
@property(nonatomic, copy, nullable) NSString *uri;

/**
 * The links with relations to other objects.
 */
@property(nonatomic, copy, nullable) NSDictionary<NSString *, NSURL *> *links;

/**
 * The API object type (@type)
 */
@property(nonatomic, copy, nullable) NSString *objectType;

/**
 * Returns the ident of a path component in the link url. E.g. for the following link,
 * { "@type": "Link", "rel": "field", "uri": "http://url.com/platform/fields/abc1234" } the method would return abc1234
 * if invoked with "fields" as the path component and "field" as the link rel.
 * @param pathComponent The component of the ident you are interested in
 * @param linkRel The rel attribute value of the link you are looking for
 * @return Returns the ident or nil if the url doesn't contain the path component or the link rel is not present
 */
- (NSString *_Nullable)identForPathComponent:(NSString *_Nonnull)pathComponent inLink:(NSString *_Nonnull)linkRel;

/**
 * Returns the ident of a path component of the url. E.g. for url
 * http://url.com/platform/organizations/12345/jobs/6789/workassignments this method returns 12345 if you invoke it
 * organizations as pathComponent parameter.
 * @param pathComponent The component of the ident you are interested in
 * @param url The url containing the ident
 * @return Returns the ident or nil if the url doesn't contain the path component
 */
+ (NSString *_Nullable)identForPathComponent:(NSString *_Nonnull)pathComponent inURL:(NSString *_Nonnull)url;

@end
