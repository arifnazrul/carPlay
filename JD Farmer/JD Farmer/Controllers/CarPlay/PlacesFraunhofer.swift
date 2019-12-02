//
//  PlacesFraunhofer.swift
//  JD Driver
//
//  Created by Ajdari, Arian on 02.12.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import MapKit

@objc class PlacesFraunhofer: NSObject {
    var title: String?
    var subtitle: String?
    var coordinate: CLLocationCoordinate2D
    
    init(title: String?, subtitle: String?, coordinate: CLLocationCoordinate2D) {
        self.title = title
        self.subtitle = subtitle
        self.coordinate = coordinate
    }
    
    static func getPlaces() -> [[PlacesFraunhofer]] {
        guard let path = Bundle.main.path(forResource: "FraunhoferCoordinates", ofType: "plist"), let array = NSArray(contentsOfFile: path) else { return [] }
        
       
        
        var allPlaces = [[PlacesFraunhofer]]()
        
        
        for item in array {
            
            let boundaries = item as? NSArray
            
            var places = [PlacesFraunhofer]()
            
            for boundary in boundaries!{
                
                let coordinates = boundary as? NSArray
                
                let title = "Fraunhofer"
                let subtitle = "Fraunhofer Subtitle"
                let latitude = Double(coordinates?[0] as! String)
                let longitude = Double(coordinates?[1] as! String)
              
                
                let place = PlacesFraunhofer(title: title, subtitle: subtitle, coordinate: CLLocationCoordinate2DMake(latitude! , longitude!))
                places.append(place)
                
                
            }
            
            allPlaces.append(places)
            
            
        }
        
        return allPlaces as [[PlacesFraunhofer]]
    }
}

extension PlacesFraunhofer: MKAnnotation { }
