//
//  CarplayViewController.swift
//  PizzaReverse
//
//  Created by Marko Ilic on 10/17/19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import CarPlay
import UIKit

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
