//
//  FlagView.swift
//  JD Driver
//
//  Created by Anwari, Mahrukh on 27.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import MapKit

class FlagView: MKAnnotationView {
  override var annotation: MKAnnotation? {
    willSet {
      // 1
      guard let flag = newValue as? Flags else { return }
      
      canShowCallout = true
      calloutOffset = CGPoint(x: -5, y: 5)
      rightCalloutAccessoryView = UIButton(type: .detailDisclosure)
        
        if let imageName = flag.imageName
        {
            image = UIImage(named: imageName)
            
        } else {
            image = nil
            
        }
        
    }
    
    }
    
}
