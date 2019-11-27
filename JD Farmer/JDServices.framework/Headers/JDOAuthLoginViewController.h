/**
 * \file JDOAuthLoginViewController.h
 * \brief Header of the interface class to the internal OAuthLogin view controller.
 *
 *  Copyright (c) Deere & Company as an unpublished work
 *  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
 *  DEERE & COMPANY.  ALL USE, DISCLOSURE, AND/OR
 *  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 *  DEERE & COMPANY IS PROHIBITED.
 */

#import "JDOAuthLoginDelegate.h"
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

/**
 *  \class JDOAuthLoginViewController
 *  \brief Wrapper of the google oauth login view controller
 */
@interface JDOAuthLoginViewController : UIViewController <UIAlertViewDelegate, WKNavigationDelegate>

/**
 *  \brief Init with the option if the try out button should be shown
 *
 *  @return The oauth login view controller
 */
- (void)showOAuthLoginView;

- (BOOL)continueIfUserIsAlreadyAuthenticated;

/// WebView Delegate allows external projects to handle webView events in a manner consistent with that implementing app.
@property(nonatomic, weak) id<WKNavigationDelegate> webViewDelegate;

@property(nonatomic, weak) IBOutlet id<JDOAuthLoginDelegate> delegate;

@property(nonatomic, assign) BOOL hideNavigationBar;

@end


/** End of File Copyright ****************************************************
 *
 *  Copyright (c) Deere & Company as an unpublished work
 *  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
 *  DEERE & COMPANY.  ALL USE, DISCLOSURE, AND/OR
 *  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 *  DEERE & COMPANY IS PROHIBITED.
 *
 *****************************************************************************/
