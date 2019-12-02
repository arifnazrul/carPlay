//
//  MyController.swift
//  JD Driver
//
//  Created by Ajdari, Arian on 22.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import UIKit
import CarPlay
import MapKit
import CoreLocation


class MyController: UIViewController,  MKMapViewDelegate, CLLocationManagerDelegate {
     var mainView: UIView?
    
    @IBOutlet weak var MapView: MKMapView!
    
    override func viewDidLoad() {
     
        super.viewDidLoad()
        
        let storyboard = UIStoryboard(name: "MyStoryboard", bundle: nil)
        let vc = storyboard.instantiateInitialViewController()
        self.navigationController!.pushViewController(vc!, animated: true)
    }
}
