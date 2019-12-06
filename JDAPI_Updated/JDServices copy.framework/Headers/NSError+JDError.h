//
//  NSError+JDError.h
//  JDServices
//
//  Created by Sampath Kunta on 2014-09-03
//
//  Copyright (c) Deere & Company as an unpublished work
//  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
//  DEERE & COMPANY. ALL USE, DISCLOSURE, AND/OR
//  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
//  DEERE & COMPANY IS PROHIBITED.
//

#import <Foundation/Foundation.h>

/*
Status sub codes that we receive from MyJD services
statusSubCode.1=Organization has not yet chosen to allow data usage
statusSubCode.2=Organization has chosen not to allow data usage
statusSubCode.3=This organization did not agree to the end user agreement
statusSubCode.4=You are not authorized to access this organization.
statusSubCode.5=The requested file was not found
statusSubCode.6=The requested machine was not found
statusSubCode.7=Invalid URI
statusSubCode.8=You do not have access to the requested file
statusSubCode.9=You do not have access to the requested machine
statusSubCode.10=System cannot process an invalid file type
statusSubCode.11=Machine does not have a terminal with an active WDT subscription
statusSubCode.12=User does not have access to the WDT feature
statusSubCode.13=Resource is not available in file storage
statusSubCode.14=Invalid File URI
statusSubCode.15=Invalid Machine URI
statusSubCode.16=Invalid Organization Search
statusSubCode.19=Winning Account Cannot be more than 1
statusSubCode.20=URI is not valid
statusSubCode.21=Winning Account cannot be empty
statusSubCode.22=Losing Account cannot be empty
statusSubCode.23=Invalid user in Merge
statusSubCode.24=Dealer Accounts Cannot be Merged
*/

typedef NS_ENUM(NSUInteger, JDErrorCode) {
    JDErrorOrganizationDataUsageNotChosen = 1,
    JDErrorOrganizationDataUsageNotAllowed = 2,
    JDErrorOrganizationEndUserAgreementDeclined = 3,
    JDErrorNotAuthorizedToAccessOrganization = 4,
    JDErrorFileNotFound = 5,
    JDErrorMachineNotFound = 6,
    JDErrorInvalidURI = 7,
    JDErrorNotAuthorizedToAccessFile = 8,
    JDErrorNotAuthorizedToAccessMachine = 9,
    JDErrorSystemCannotProcessInvalidFileType = 10,
    JDErrorNoTerminalWithActiveWDTSubscription = 11,
    JDErrorNotAuthorizedToTheWDTFeature = 12,
    JDErrorResourceNotAvailableInFileStorage = 13,
    JDErrorInvalidFileURI = 14,
    JDErrorInvalidMachineURI = 15,
    JDErrorInvalidOrganizationSearch = 16,
    JDErrorWinningAccountNotMoreThanOne = 19,
    JDErrorURINotValid = 20,
    JDErrorEmptyWinningAccount = 21,
    JDErrorEmptyLoosingAccount = 22,
    JDErrorInvalidUserInMerge = 23,
    JDErrorDealerAccountCannotBeMerged = 24,
    JDErrorInvalidInputParameters = 25,

    JDErrorNoNetwork =
        1001, // NSURLErrorNotConnectedToInternet, NSURLErrorCallIsActive, NSURLErrorNetworkConnectionLost
    JDErrorUnauthorized_Login = 1002,
    JDErrorUnauthorized = 1003,
    JDErrorForbidden = 1004,
    JDErrorServiceUnavialable = 1005, // 503 HTTP status code -- MyJohnDeere is unable not available
    JDErrorLocalFileNotFound = 1006,  // Local file inside the application is not found
    JDErrorServerError = 1007,
    JDErrorAppNotAuthorized = 1020,
    JDErrorUnknownError = 2000
};

typedef NS_ENUM(NSUInteger, JDHTTPStatusCodes) {
    JDHTTPStatusCodeNotModified = 304,
    JDHTTPStatusCodeBadRequest = 400,
    JDHTTPStatusCodeUnauthorized = 401,
    JDHTTPStatusCodeForbidden = 403,
    JDHTTPStatusCodeFileNotFound = 404,
    JDHTTPStatusCodeNotAcceptable = 406,
    JDHTTPStatusCodeTooManyRequests = 429,
    JDHTTPStatusCodeInternalServerError = 500,
    JDHTTPStatusCodeServiceUnavailable = 503,
    JDHTTPStatusCodeGatewayTimeout = 504
};

extern NSString *_Nonnull const kJDErrorDomain;

@class AFHTTPRequestOperation;

/**
 * @brief MyJohnDeere Error object.
 */
@interface NSError (JDError)

+ (BOOL)jdIsErrorNoInternetError:(nonnull NSError *)error;

+ (nonnull NSError *)jdErrorUnknownErrorWithActualError:(nullable NSError *)error;

+ (nonnull NSError *)jdErrorWithStatusCode:(NSInteger)statusCode
                    responseObject:(nullable id)responseObject
                          andError:(nullable NSError *)error;


@end
