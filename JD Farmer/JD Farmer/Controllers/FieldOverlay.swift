//
//  FieldOverlay.swift
//  JD Driver
//
//  Created by Ajdari, Arian on 21.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import MapKit

class FieldOverlay: NSObject, MKOverlay {
  var coordinate: CLLocationCoordinate2D
  var boundingMapRect: MKMapRect
    
 //Initializes the class variables with the properties of the passed Field Class object
    init(field: FieldController) {
        boundingMapRect = field.overlayBoundingMapRect
        coordinate = field.midCoordinate
        
    }
}
