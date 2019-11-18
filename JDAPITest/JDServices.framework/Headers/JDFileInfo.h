//
//  JDFileInfo.h
//  JDServices
//
//  Created by Sampath Kunta on 2014-09-08
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>
#import "JDAPIBaseObject.h"

typedef NS_ENUM (NSUInteger, JDFileType) {
    JDFileTypeSetup = 0,
    JDFileTypePrescription,
    JDFileTypeInvalid,
    JDFileTypeUnknown,
    JDFileTypeDoc,
    JDFileTypeJDBackup,
    JDFileTypeHIC,
    JDFileTypeTimerLink,
    JDFileTypeExport,
    JDFileTypePermission,
    JDFileTypeWhatsNewTimermatic
};
extern NSString *_Nonnull const JDFileType_toString[];

typedef NS_ENUM (NSUInteger, JDFileShareType) {
    JDFileShareTypeOwned,
    JDFileShareTypeManual
};
extern NSString *_Nonnull const JDFileShareType_toString[];

typedef NS_ENUM (NSUInteger, JDFileStatus) {
    JDFileStatusUploadPending,
    JDFileStatusReady,
    JDFileStatusInProgress
};
extern NSString *_Nonnull const JDFileStatus_toString[];
extern NSString *_Nonnull const JDFileStatus_toServerResponseString[];

/**
 * @brief File information.
 */
@interface JDFileInfo : JDAPIBaseObject<NSCopying>

@property(nonatomic, copy, nullable) NSString *ident;
@property(nonatomic, copy, nullable) NSString *name;
@property(nonatomic, copy, nullable) NSString *type;
@property(nonatomic, assign) JDFileType fileType;
@property(nonatomic, strong, nullable) NSDate *createdTime;
@property(nonatomic, strong, nullable) NSDate *modifiedTime;
@property(nonatomic, assign) unsigned long long nativeSize;
@property(nonatomic, copy, nullable) NSString *source;
@property(nonatomic, assign) BOOL transferPending;
@property(nonatomic, assign) JDFileShareType visibleViaShare;
@property(nonatomic, assign) BOOL shared;
@property(nonatomic, assign) JDFileStatus status;
@property(nonatomic, assign) BOOL archived;
@property(nonatomic, assign) BOOL new;
@property(nonatomic, copy, nullable) NSString *fileURLString;

@property(nonatomic, copy, nullable) NSString *fileId DEPRECATED_ATTRIBUTE;
@property(nonatomic, assign) BOOL isNewFile DEPRECATED_ATTRIBUTE;
@property(nonatomic, copy, nullable) NSString *fileName DEPRECATED_ATTRIBUTE;

@end
