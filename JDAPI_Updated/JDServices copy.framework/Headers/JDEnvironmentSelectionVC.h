//
//  JDEnvironmentSelectionVC.h
//  JDServices
//
//  Created by Patrick Haaser on 2015-09-02
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

/**
 * @brief Protocol for {@link JDEnvironment} selection.
 */
@protocol JDEnvironmentSelectionDelegate <NSObject>

- (void)environmentSelectionDidChangeEnvironment;

@end

/**
 * @brief View Controller to select the {@link JDEnvironment}.
 */
@interface JDEnvironmentSelectionVC : UIViewController

@property(nonatomic, weak, nullable) id<JDEnvironmentSelectionDelegate> delegate;

@end
