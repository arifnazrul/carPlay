//
//  FieldController.swift
//  JD Driver
//
//  Created by Ajdari, Arian on 21.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import UIKit
import MapKit

class FieldController {
  var name: String?
  var boundary: [CLLocationCoordinate2D] = []
  
  var midCoordinate = CLLocationCoordinate2D()
  var overlayTopLeftCoordinate = CLLocationCoordinate2D()
  var overlayTopRightCoordinate = CLLocationCoordinate2D()
  var overlayBottomLeftCoordinate = CLLocationCoordinate2D()
  var overlayBottomRightCoordinate: CLLocationCoordinate2D {
    get {
      return CLLocationCoordinate2DMake(overlayBottomLeftCoordinate.latitude,
                                        overlayTopRightCoordinate.longitude)
    }
  }
  
  var overlayBoundingMapRect: MKMapRect {
    get {
        let topLeft = MKMapPoint.init(overlayTopLeftCoordinate)
        let topRight = MKMapPoint.init(overlayTopRightCoordinate)
        let bottomLeft = MKMapPoint.init(overlayBottomLeftCoordinate)
        
        return MKMapRect.init(x: topLeft.x,y: topLeft.y,width: fabs(topLeft.x - topRight.x),height: fabs(topLeft.y - bottomLeft.y))
        
    }
  }
  // extract the boundries from the plist and assign coordinate values to the class variables as per the extracted info
  init(filename: String) {
    // create a dictionary "properties" with string items array and extract the boundries in the boundaryPoints array of strings
    guard let properties = FieldController.plist(filename) as? [String : Any],
        let boundaryPoints = properties["boundary"] as? [String] else { return }
    
    // assign the values to the class variables
    midCoordinate = FieldController.parseCoord(dict: properties, fieldName: "midCoord")
    overlayTopLeftCoordinate = FieldController.parseCoord(dict: properties, fieldName: "overlayTopLeftCoord")
    overlayTopRightCoordinate = FieldController.parseCoord(dict: properties, fieldName: "overlayTopRightCoord")
    overlayBottomLeftCoordinate = FieldController.parseCoord(dict: properties, fieldName: "overlayBottomLeftCoord")
    
     // add comment about what this does
    let cgPoints = boundaryPoints.map { NSCoder.cgPoint(for:$0)}
    boundary = cgPoints.map { CLLocationCoordinate2DMake(CLLocationDegrees($0.x), CLLocationDegrees($0.y)) }
    }
    
//deserialize the property list
class func plist(_ plist: String) -> Any? {
  let filePath = Bundle.main.path(forResource: plist, ofType: "plist")!
  let data = FileManager.default.contents(atPath: filePath)!
  return try! PropertyListSerialization.propertyList(from: data, options: [], format: nil)
    
    }
   // Parse the coordinate location as per the provided dictionary
    static func parseCoord(dict: [String: Any], fieldName: String) -> CLLocationCoordinate2D {
      guard let coord = dict[fieldName] as? String else {
        return CLLocationCoordinate2D()
      }
      let point = NSCoder.cgPoint(for:coord)
      return CLLocationCoordinate2DMake(CLLocationDegrees(point.x), CLLocationDegrees(point.y))
    }
}
