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
        print("test")
    }
    
    func loginViewControllerDelegateDidFinishLoginWithError(_ error: Error) {
        print("test")
    }
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
   
}
