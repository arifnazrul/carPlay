//
//  JDReorderContainer.h
//  JDServices
//
//  Created by Fischer Arne on 2016-05-04
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

typedef NS_ENUM(NSInteger, JDReorderType) {
    JDReorderTypeMoveBeforeJob,
    JDReorderTypeMoveAfterJob,
    JDReorderTypeMoveToDay
};

/**
 * @brief A container to hold all information for a reorder request.
 */
@interface JDReorderContainer : NSObject

/**
 * The related object. It should be a job id for JDReorderTypeMoveBeforeJob and JDReorderTypeMoveAfterJob. For
 * JDReorderTypeMoveToDay it
 * should be a NSDate.
 */
@property(nonatomic, strong) _Nonnull id relatedObject;

/**
 * The list of jobs that should be moved.
 */
@property(nonatomic, strong) NSArray<NSString *> *_Nonnull jobsToMove;

/**
 * The reorder type. This defines how "relatedObject" and "jobsToMove" are related.
 */
@property(atomic, assign) JDReorderType reorderType;

/**
 * Create the post body for this container.
 */
- (NSArray<NSDictionary *> *_Nonnull)postBody;

@end
