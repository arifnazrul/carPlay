//
//  ChildController.swift
//  JDAPITest
//
//  Created by Biswas, Priom on 03.12.19.
//  Copyright © 2019 Capstone. All rights reserved.
//

import Foundation

class ChildController: UIViewController, JDLoginViewControllerDelegate {
    func loginViewControllerDelegateDidFinishLogin(withSuccess sender: JDLoginViewController?, andUser user: JDUser) {
        print("YUHUU")
        /*
        var orgs:[JDOrganization] = []
        var errs: Error
        var resp: JDResponse
        JDOrganizationRequests.fetchOrganizations(embedOptions: JDOrganizationEmbedOptions.addresses) {
            (orgs, errs, resp) in
            if (orgs != nil) {
                print (orgs)
            } else if (errs != nil) {
                print (errs!.localizedDescription)
            }
        }
         */
    }
    
    func loginViewControllerDelegateDidFinishLoginWithError(_ error: Error) {
        print("OHHHH")
    }
    

    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        print("TESTT")
        
       
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
   
}
