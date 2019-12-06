/**
 * \file JDOAuthLoginDelegate.h
 *
 *  Copyright (c) Deere & Company as an unpublished work
 *  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
 *  DEERE & COMPANY.  ALL USE, DISCLOSURE, AND/OR
 *  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 *  DEERE & COMPANY IS PROHIBITED.
 */

#import <Foundation/Foundation.h>

/**
 *  \brief Delegate to track the oauth plugin progress
 */
@protocol JDOAuthLoginDelegate <NSObject>

@optional
/**
 *  \brief Gets called when the oauth login view controller has been dismissed
 *
 *  @param error nil in case of a successful login, !=nil otherwise
 */
- (void)loginFinishedWithError:(NSError *)error;

/**
 *  \brief Gets called when the login button is pressed
 */
- (void)loginProcessHasStarted;

/**
 *  \brief Gets called when the login page starts loading.
 */
- (void)loginPageStartedLoading;

/**
 *  \brief Gets called when the login page ends loading.
 */
- (void)loginPageFinishedLoading;

/**
 *  \brief Gets called when the login page fails loading.
 *
 *  @param error nil in case of cancelled operation
 */
- (void)loginPageFailedLoadingWithError:(NSError *)error;

/**
 *  \brief Gets called when the create account button is pressed
 */
- (void)loginDidPressCreateAccount;

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