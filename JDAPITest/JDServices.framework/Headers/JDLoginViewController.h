//
//  JDLoginViewController.h
//  JDServices
//
//  Created by Hack Marco on 2014-11-03
//
//  Unpublished Work (c) 2014 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

#import "JDOAuthLoginViewController.h"

@class JDLoginViewController;
@protocol JDEnvironmentSelectionDelegate;
@class JDUser;

/**
 * @brief Delegate to track the login success.
 */
@protocol JDLoginViewControllerDelegate <NSObject>
@required
/**
 * Tells the delegate that the login view controller has logged in successfully.
 * @param sender The sender
 * @param user The logged in user
 */
- (void)loginViewControllerDelegateDidFinishLoginWithSuccess:(nullable JDLoginViewController *)sender
                                                     andUser:(nonnull JDUser *)user;

/**
 * Tells the delegate that the login view controller has not logged in.
 * @param error The error
 */
- (void)loginViewControllerDelegateDidFinishLoginWithError:(nonnull NSError *)error;

@optional

/**
 * Tells the delegate that the login process has started.
 */
- (void)loginViewControllerDelegateDidStartUserAuthentication;

/**
 * Tells the delegate that the login page has started loading.
 */
- (void)loginViewControllerDelegateDidStartLoadingLoginPage;

/**
 * Tells the delegate that the login page has loaded.
 */
- (void)loginViewControllerDelegateDidFinishLoadingLoginPage;

/**
 * Tells the delegate that the new account create has pressed.
 */
- (void)loginViewControllerDelegateDidPressCreateAccountButton;

@end

/**
 * @brief Login controller for MyJohnDeere with environment selection.
 */
@interface JDLoginViewController : UIViewController <JDOAuthLoginDelegate>

@property(nonatomic, assign) BOOL showEnvironmentSwitch;
@property(nonatomic, weak, nullable) id<JDLoginViewControllerDelegate> delegate;

/**
 * Reloads the login page.
 */
- (void)reloadWebPage;

@end
