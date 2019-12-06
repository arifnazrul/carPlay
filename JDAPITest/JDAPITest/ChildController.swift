//
//  ChildController.swift
//  JDAPITest
//
//  Created by Biswas, Priom on 03.12.19.
//  Copyright © 2019 Capstone. All rights reserved.
//

import Foundation

class ChildController: UIViewController {

    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        print("TESTT")
        
       var orgs:[JDOrganization] = []
       var errs: Error
       var resp: JDResponse
       JDOrganizationRequests.fetchOrganizations(embedOptions: JDOrganizationEmbedOptions.addresses) { (orgs, errs, resp) in
           if (orgs != nil) {
            for var y in (orgs ?? nil)! {
                if (y != nil) {
                    print((y.name ?? "MYNAME") + " " + (y.addresses?[0].country ?? "KGZ"))
                }
            }
            
           } else if (errs != nil) {
               print(errs!.localizedDescription)
           }
       }

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
   
}
