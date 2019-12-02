//
//  Flags.swift
//  JD Driver
//
//  Created by Anwari, Mahrukh on 27.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import MapKit

class Flags: NSObject, MKAnnotation {
  let title: String?
  let locationName: String
  let coordinate: CLLocationCoordinate2D
  
  init(title: String, locationName: String,coordinate: CLLocationCoordinate2D) {
    self.title = title
    self.locationName = locationName
    self.coordinate = coordinate
    
    super.init()
  }
  
  var subtitle: String? {
    return locationName
  }
    var imageName: String? {
      return "Flag"
    }
}
