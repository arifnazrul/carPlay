//
//  CarPlayViewController.swift
//  JD Farmer
//
//  Created by Ajdari, Arian on 18.10.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import UIKit
import CarPlay

class CarplayViewController: UIViewController {
    
    var mainView: UIView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if mainView == nil {
            mainView = Bundle.main.loadNibNamed("CarPlayView", owner: self, options: nil)?.first as? UIView
            
            mainView?.frame = view.bounds
            if let mainViewUnwrapped = mainView {
                self.view.addSubview(mainViewUnwrapped)
            }
        }
    }
}
