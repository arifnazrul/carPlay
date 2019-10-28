//
//  ViewController.swift
//  InternetConnectivity
//
//  Created by capstone on 23.10.19.
//  Copyright © 2019 Capstone. All rights reserved.
//

import UIKit
import Network

class ViewController: UIViewController {
  
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let monitor = NWPathMonitor()
        
        monitor.pathUpdateHandler = { path in
            if path.status == .satisfied
            {
                print("CONNECTED!")
        
                if path.isExpensive
                {
                    print("Expensive Connection: Cellular or Hotspot")
                }
                else
                {
                    print("Non-Expensive Connection")
                }
                
            }
            
            else
            {
                print("NOT CONNECTED!")
            }
            
         }
        
        let queue = DispatchQueue(label: "Monitor")
        monitor.start(queue: queue)
    }
}

