//
//  ChildController.swift
//  JDAPITest
//
//  Created by Biswas, Priom on 03.12.19.
//  Copyright © 2019 Capstone. All rights reserved.
//

import Foundation
import UIKit

class ChildController: UIViewController {

    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let lbl = UILabel(frame: CGRect(x: 10, y: 50, width: 230, height: 21))
        lbl.textAlignment = .center //For center alignment
    
        lbl.text = "Connect to carplay"
        lbl.textColor = .black
        lbl.backgroundColor = .white//If required
        lbl.font = UIFont.systemFont(ofSize: 17)
        
        //To display multiple lines in label
        lbl.numberOfLines = 0 //If you want to display only 2 lines replace 0(Zero) with 2.
        lbl.lineBreakMode = .byWordWrapping //Word Wrap
        // OR
        lbl.lineBreakMode = .byCharWrapping //Charactor Wrap

        lbl.sizeToFit()//If required
        self.view.addSubview(lbl)
        
       var orgs:[JDOrganization] = []
        var flds: [JDField] = []
       var errs: Error
       var resp: JDResponse
       JDOrganizationRequests.fetchOrganizations(embedOptions: JDOrganizationEmbedOptions.addresses) { (orgs, errs, resp) in
           if (orgs != nil) {
            for var y in (orgs ?? nil)! {
                //if (y != nil) {
                print("org: " + (y.organizationId ?? "x1234"))
                print((y.name ?? "MYNAME") + " " + (y.addresses?[0].country ?? "KGZ"))
                //}
            }
            
            JDFieldRequests.fetchFields(forOrganizationId: "449464", embedClientsAndFarms: true) { (flds, errs) in
                if (flds != nil) {
                    for var f in (flds ?? nil)! {
                        print ("Here is the field: " + (f.name ?? "FILEDS") + " id: " + (f.uniqueId ?? "myfidlid"))
                    }
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
