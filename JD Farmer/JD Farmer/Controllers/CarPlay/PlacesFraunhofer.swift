/**
  - **Name**:         PlacesFraunhofer.swift
  - Description: This File opens FraunhoferCoordinates.plist file and places neccessary information inside double array of type PlacesFraunhofer to be used somewhere else
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      02.12.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import Foundation
import MapKit

class PlacesFraunhofer: NSObject {
    
    /// Variable containing name of the field
    var title: String?
    
    /// Variable containing description of the field
    var subtitle: String?
    
    /// Variable containing coordinate
    var coordinate: CLLocationCoordinate2D
    
    /**
       - Parameters:
        - title: title of the field
        - subtitle: description of the field
        - coordinate: contains coordinate informations
       - Description: Constructor
       - Returns: void
    */
    init(title: String?, subtitle: String?, coordinate: CLLocationCoordinate2D) {
        self.title = title
        self.subtitle = subtitle
        self.coordinate = coordinate
    }
    
    /**
       - Parameters: void
       - Description: It generaters the double array containing field information
       - Returns: doubleArray of type PlacesFraunhofer
    */
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
