//
//  JDNSURLSessionDownloadTaskManager.h
//  JDServices
//
//  Created by Gillispie Leah on 10/10/17.
//  Copyright © 2017 Deere & Company. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString *const JDNSURLProgressFractionCompletedObserverKey = @"fractionCompleted";
static double const JDNSURLTaskProgressTimeout = 60.0;
static NSString *const JDNSURLTaskStateObserverKey = @"state";

@interface JDNSURLSessionDownloadTaskManager : NSObject

@property(nonatomic) NSURLSessionDownloadTask *task;

- (instancetype)initWithTask:(NSURLSessionDownloadTask *)task progress:(NSProgress *)progress;

- (void)startTask;

- (void)cancelTask;

@end
