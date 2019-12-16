/**
  - **Name**:         CarPlayViewController.swift
  - Description: This ViewController generates a base view containing a MKMapView Object. Positioning of the user,
                 offseting, re-centring and drawing overlays is done inside this ViewController.
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      21.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import UIKit
import MapKit
import CarPlay
import Foundation
import CoreLocation

class CarPlayViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {
    
    /// Outlet from CarPlayView.xib file pointing the map
    @IBOutlet weak var mapView: MKMapView!
    
    /// We get the instance of the view generated by UIViewController class, which we extend
    var mainView: UIView?
    
    /// These variables are used to pin-point users current location and make panning feature implementation possible
    var lat       : Double =  49.370204
    var long      : Double =  7.726008
    var offsetLat : Double =  0.000000
    var offsetLong: Double =  0.000000
    var tractorPositionLat: Double =   49.370799
    var tractorPositionLong: Double = 7.719316
    var flagPositionLat: Double = 49.377248
    var flagPositionLong: Double = 7.723031
    var flagPositionLat2: Double =  49.375017
    var flagPositionLong2: Double = 7.731103
    var notePositionLat: Double =  49.374717
    var notePositionLong: Double =  7.731103
    /// Radius of the circle showing the user's location
    /// - Todo: implement the logic of interval, tick and growth so circle grows and shrinks dynamically for better user experience
    var radius : Double! = 30
    var interval = 0
    var tick     = 0
    var growth   = 3
    var changeCounter: Int = 0
    
    /// Variable containing all overlays appearing on the MKMapView object
    var overlays: [MKOverlay]!
    
    var tractorOverlay: [MKAnnotation]!
    
    var removeTractor: Bool = false
    
    /// Variable containing user's location
    /// - Todo: Test with real device containing GPS capabilities to check for the precision of locating the user
    let locationManager = CLLocationManager()
   
    /// Contains all fields relevant to the user - including nearby field
    /// - Todo: Fetch data from API and sort the fields according to distance (ASC)
    let fields = PlacesFraunhofer.getPlaces()
    
    /// Contains all border colours
    let borders: [[CGFloat]] = [
        [245, 159, 61],
        [146, 202, 110],
        [74, 178, 216],
        [74, 178, 216],
        [203, 156, 115],
        [255, 178, 255]
    ]
    /// Contains all inside colours
    let inside: [[CGFloat]] = [
        [244, 193, 136],
        [183, 217, 160],
        [147, 205, 226],
        [147, 205, 226],
        [222, 194, 171],
        [254, 42, 254]
    ]
    
    /// Iterator helping select the correct colour
    var iterator: Int = 0
    
    /// Boolean which checks whether user changed position
    var changedPosition: Bool = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        mapView.delegate = self

        checkLocationServices()
        
        addPolyline()
        addPolygon()
        addAnnotations()
        addTractor()
        overlays = mapView.overlays
    }
    
    /**
       - Parameters: void
       - Description: It moves the user and updates the overlays
       - Returns: void
    */
    func moveUser() {
        if(changeCounter == 0) {
            mapView.removeOverlays(overlays)
            lat = 49.371829
            long = 7.726896
            changedPosition = true
            addPolyline()
            addPolygon()
            addAnnotations()
            addTractor()
            changeCounter += 1
            overlays = mapView.overlays
        }   else if(changeCounter == 1) {
            mapView.removeOverlays(overlays)
            lat = 49.372717
            long = 7.728726
            changedPosition = true
            addPolyline()
            addPolygon()
            addAnnotations()
            addTractor()
            changeCounter += 1
            overlays = mapView.overlays
        }else if(changeCounter == 2) {
            mapView.removeOverlays(overlays)
            lat = 49.374878
            long = 7.734471
            changedPosition = true
            addPolyline()
            addPolygon()
            addAnnotations()
            addTractor()
            changeCounter += 1
            overlays = mapView.overlays
        }else if(changeCounter == 3) {
            tractorOverlay = mapView.annotations
            mapView.removeAnnotations(tractorOverlay)
            mapView.removeOverlays(overlays)
            lat = 49.371863
            long = 7.732561
            changedPosition = true
            addPolyline()
            addPolygon()
            addAnnotations()
            addSecondAnnotations()
            changeCounter += 1
            overlays = mapView.overlays
        }
    }
    
    
    func addTractor()
    {
        let annotationTractor = MKPointAnnotation()
       
        annotationTractor.title = "traktor"
       annotationTractor.subtitle = "Tractor Annotation"
       annotationTractor.coordinate = CLLocationCoordinate2D(latitude: tractorPositionLat, longitude: tractorPositionLong)
       mapView?.addAnnotation(annotationTractor)
        
      
        
    }
    /**
       - Parameters: void
       - Description: Creates a circle with specified parameters pinpointing user's location
       - Returns: void
    */
    func addAnnotations() {
        mapView?.delegate = self
        
       
       
        
        let annotationFlag = MKPointAnnotation()
        annotationFlag.title = "zastava"
        annotationFlag.subtitle = "Flag Annotation"
        annotationFlag.coordinate = CLLocationCoordinate2D(latitude: flagPositionLat, longitude: flagPositionLong)
        mapView?.addAnnotation(annotationFlag)
        
        let annotationFlag2 = MKPointAnnotation()
        annotationFlag2.title = "zastava2"
        annotationFlag2.subtitle = "Flag Annotation"
        annotationFlag2.coordinate = CLLocationCoordinate2D(latitude: flagPositionLat2, longitude: flagPositionLong2)
        mapView?.addAnnotation(annotationFlag2)
        
        let overlays = [MKCircle(center: CLLocationCoordinate2D(latitude: lat, longitude: long), radius: radius)]
        mapView?.addOverlays(overlays)
        
    }
    
    func addSecondAnnotations(){
        let annotationNote = MKPointAnnotation()
        annotationNote.title = "beleska"
        annotationNote.subtitle = "Note Annotation"
        annotationNote.coordinate = CLLocationCoordinate2D(latitude: notePositionLat, longitude: notePositionLong)
        mapView?.addAnnotation(annotationNote)
    }
    
    /**
       - Parameters: void
       - Description: Creates a polyline with specified parameters pinpointing user's location
       - Returns: void
           
    */
    func addPolyline() {
        for field in fields {
            var coordinates = field.map { $0.coordinate }
            let polyline = MKPolyline(coordinates: &coordinates, count: coordinates.count)
            
            mapView?.addOverlay(polyline)
        }
    }
    
    /**
       - Parameters: void
       - Description: Creates a polygon  with specified parameters pinpointing user's location
       - Returns: void
    */
    func addPolygon() {
        for field in fields {
            var coordinates = field.map { $0.coordinate }
            let polygon = MKPolygon(coordinates: &coordinates, count: coordinates.count)
                   
            mapView?.addOverlay(polygon)
        }
    }
  
    /**
       - Parameters: void
       - Description: Checks user location services
       - Returns: void
    */
    func checkLocationServices() {
       if CLLocationManager.locationServicesEnabled(){
           setupLocationManager()
           checkLocationAuthorization()
       }
       else{
           /// show alert letting userknow thez have to turn this on
           print("Your Location Services are Off")
       }
    }
    
    /**
       - Parameters: void
       - Description: Sets up user location Manager by allocating the delegate methods, choosing accuracy and requesting permission
       - Returns: void
    */
    func setupLocationManager() {
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestWhenInUseAuthorization()
    }
    
    /**
       - Parameters: void
       - Description: Performs location Authorization
       - Returns: void
    */
    func checkLocationAuthorization() {
        switch CLLocationManager.authorizationStatus() {
            //only when the app is Open
            case .authorizedWhenInUse:
              locationManager.startUpdatingLocation()
              mapView.showsUserLocation = true
                break
            case .denied:
                // show alerts instructing how to turn on the permissions
                break
            case .notDetermined:
                locationManager.requestWhenInUseAuthorization()
                break
            case .restricted:
                //show alerts.
                break
            // when the app is open in the background
            case .authorizedAlways:
                mapView.showsUserLocation = true
                locationManager.startUpdatingLocation()
                break
            default:
                locationManager.stopUpdatingLocation()
                mapView.showsUserLocation = false
        }
    }
    
    /**
       - Parameters:
           - manager: A object of type CLLocationManager containing last available position
           - locations: A array containing user locations
       - Description: This function is called periodically and it is provided by CLLocationManagerDelegate
       - Returns: void
    */
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        
        let _: CLLocationCoordinate2D = manager.location!.coordinate
        
        if locations.last != nil{
            let center = CLLocationCoordinate2D(latitude: lat + offsetLat , longitude: long + offsetLong)
            let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0.017, longitudeDelta: 0.017))
            self.mapView.setRegion(region, animated: true)
            
            
            
        }
    }
    
    /**
       - Parameters:
           - mapView: mapView instance
           - overlay: Object containing data which will be overlayed on top of the Map
       - Description: This function  tells the renderer how to overlay data on top of the map
       - Returns: MKOverlayRenderer
    */
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        if overlay is MKCircle {
            print("CIRCLE")
            let renderer = MKCircleRenderer(overlay: overlay)
            renderer.fillColor = UIColor(red: 51/255, green: 133/255, blue: 253/255, alpha: 1.0)
            renderer.strokeColor = UIColor(red: 51/255, green: 133/255, blue: 253/255, alpha: 0.8)
            renderer.lineWidth = 2
            return renderer
        } else if overlay is MKPolyline {
            print("POLYLINE")
            let renderer = MKPolylineRenderer(overlay: overlay)
            renderer.strokeColor = UIColor(red: borders[0][0]/255 , green: borders[0][1]/255, blue: borders[0][2]/255, alpha: 1)
            renderer.lineWidth = 3
            return renderer
        } else if overlay is MKPolygon {
            print("POLYGON")
            let renderer = MKPolygonRenderer(polygon: overlay as! MKPolygon)
            renderer.strokeColor = UIColor(red: borders[iterator][0]/255 , green: borders[iterator][1]/255, blue: borders[iterator][2]/255, alpha: 1)
            renderer.fillColor = UIColor(red: inside[iterator][0]/255 , green: inside[iterator][1]/255, blue: inside[iterator][2]/255, alpha: 0.7)
            
           
           
           
            renderer.lineWidth = 2
            
            iterator += 1
            
            if(iterator == 6) {
              iterator = 0
            }
            return renderer
        }
        return MKOverlayRenderer()
    }
    
    /**
       - Parameters:
           - mapView: mapView instance
           - annotation: Object containing data which will be overlayed on top of the Map
       - Description: This function  tells the renderer how to overlay data on top of the map
       - Returns: MKAnnotationView
    */
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        
        if annotation is MKPointAnnotation {
            
            let annotationRenderer = MKAnnotationView()
            
            if(annotation.title == "traktor") {
                annotationRenderer.image = UIImage(named: "traktorce")
                annotationRenderer.center = CGPoint(x: tractorPositionLat, y: tractorPositionLong)
                return annotationRenderer
            } else if(annotation.title == "zastava") {
                annotationRenderer.image = UIImage(named: "flagMarker")
                annotationRenderer.center = CGPoint(x: flagPositionLat, y: flagPositionLong)
                return annotationRenderer
            } else if(annotation.title == "zastava2") {
                annotationRenderer.image = UIImage(named: "flagMarker")
                annotationRenderer.center = CGPoint(x: flagPositionLat2, y: flagPositionLong2)
                return annotationRenderer
            } else if(annotation.title == "beleska") {
                annotationRenderer.image = UIImage(named: "beleska")
                annotationRenderer.center = CGPoint(x: notePositionLat, y: notePositionLong)
                return annotationRenderer
            }
        }
        return MKAnnotationView()
    }
}
