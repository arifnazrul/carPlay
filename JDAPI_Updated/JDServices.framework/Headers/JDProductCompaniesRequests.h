//
//  JDProductCompaniesRequests.h
//  JDServices
//
//  Created by Tobias Riesbeck on 2019-08-02
//
//  Unpublished Work (c) 2019 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//

@class JDRequest;
@class JDProductCompaniesRequestContract;
@class JDResponse;
@class JDProductCompany;

@interface JDProductCompaniesRequests : NSObject

/**
 * Fetches a list of all product companies from the webservice with a specific request contract.
 * @param contract A {@link JDProductCompaniesRequestContract} containing the request specifications.
 * @param completionBlock The completion block.
 * @return A {@link JDRequest} object which contains the tasks this request is performing.
 */
+ (JDRequest *_Nonnull)fetchProductCompaniesWithContract:(JDProductCompaniesRequestContract *_Nonnull)contract
                             completionBlockWithResponse:(void (^_Nonnull)(NSArray<JDProductCompany *> *_Nullable,
                                                                           NSError *_Nullable,
                                                                           JDResponse *_Nullable))completionBlock;

@end