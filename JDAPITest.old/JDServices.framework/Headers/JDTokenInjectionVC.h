//
//  JDTokenInjectionVC.h
//  JDServices
//
//  Created by Bott Sebastian on 2016-11-30
//
//  Unpublished Work (c) 2016 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

/**
 * @brief Delegate to track the token injection success.
 */
@protocol JDTokenInjectionVCDelegate <NSObject>
@required
/**
 * Tells the delegate that the authentication with token and secret was successful.
 */
- (void)tokenInjectionVCDidAuthenticate;
@end

/**
 * @brief Authentication with an existing OAuth token and secret to bypass the login view.
 * @author Bott Sebastian
 */
@interface JDTokenInjectionVC : UIViewController

/**
 * The delegate.
 */
@property(nonatomic, weak, nullable) id<JDTokenInjectionVCDelegate> delegate;

@property(nonatomic, weak, nullable) IBOutlet UITextField *oauthTokenTextField;
@property(nonatomic, weak, nullable) IBOutlet UITextField *tokenSecretTextField;
@property(nonatomic, weak, nullable) IBOutlet UIButton *authenticateButton;

@end
