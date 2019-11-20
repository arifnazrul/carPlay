//
//  FieldOverlay.swift
//  MapView
//
//  Created by Anwari, Mahrukh on 20.11.19.
//  Copyright © 2019 Anwari, Mahrukh. All rights reserved.
//

import UIKit
import MapKit

class FieldOverlay: NSObject, MKOverlay {
  var coordinate: CLLocationCoordinate2D
  var boundingMapRect: MKMapRect
    
 //Initializes the class variables with the properties of the passed Field Class object
    init(field: Field) {
        boundingMapRect = field.overlayBoundingMapRect
        coordinate = field.midCoordinate
        
    }
}
