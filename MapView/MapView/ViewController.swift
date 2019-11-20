//
//  ViewController.swift
//  Maps
//
//  Created by Anwari, Mahrukh on 06.11.19.
//  Copyright © 2019 Anwari, Mahrukh. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class ViewController: UIViewController
{
    // the Outlet for the map kit view object
    @IBOutlet weak var MapView: MKMapView!
    let locationManager = CLLocationManager()
    // variable for the compass button
    var compassButton: MKCompassButton!
    // creating an object of the model: field class
    var field = Field(filename: "FraunhoferCoordinates")
   

    override func viewDidLoad() {
        super.viewDidLoad()
        setCompass()
        checkLocationServices()
    }
    
    // disable the mapview's own built in compass and use the MKCompassButton instead. setting visibility to always visible and orienting the compass
    func setCompass() {
        self.MapView.showsCompass = false
        self.compassButton = MKCompassButton(mapView: MapView)
        self.compassButton.compassVisibility = .visible
        MapView.addSubview(self.compassButton)
        self.compassButton.translatesAutoresizingMaskIntoConstraints = false
        compassButton.trailingAnchor.constraint(equalTo: self.MapView.trailingAnchor, constant: -12).isActive = true
        compassButton.topAnchor.constraint(equalTo: self.MapView.topAnchor, constant: 12).isActive = true
    }
    
   // Check if user has the Location Service enabled on his phone
    func checkLocationServices(){
        if CLLocationManager.locationServicesEnabled(){
            setupLocationManager()
            checkLocationAuthorization()
        }
        else{
            // show alert letting userknow thez have to turn this on
            print("Your Location Services are Off")
        }
    }

    // setup location manager
    func setupLocationManager(){
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestWhenInUseAuthorization()
    }
    
    // check the authorization statuses
    func checkLocationAuthorization(){
        
        switch CLLocationManager.authorizationStatus() {
        //only when the app is Open
        case .authorizedWhenInUse:
          locationManager.startUpdatingLocation()
          MapView.showsUserLocation = true
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
            MapView.showsUserLocation = true
            locationManager.startUpdatingLocation()
            break
        default:
            locationManager.stopUpdatingLocation()
            MapView.showsUserLocation = false
        }
    }
    
    // Creating a FieldOverlay object initialized with the field model object created above. Adding the object to the MapView Overlays.
    func addOverlay(){
        let overlay = FieldOverlay(field: field)
        MapView.addOverlay(overlay)
        
    }
    
    // To add the customized boundries to the MapView.Provided boundries are fetched from the field model class data.
    func addBounary(){
        MapView.addOverlay(MKPolygon(coordinates: field.boundary, count: field.boundary.count))
    }
    

}

extension ViewController: CLLocationManagerDelegate{
    // setting up the span (the depth of the view), region and centered location of the map
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        
        let locationValue: CLLocationCoordinate2D = manager.location!.coordinate
        
        if let location = locations.last{
            let center = CLLocationCoordinate2D(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
            let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
            self.MapView.setRegion(region, animated: true)
            
            let annotation = MKPointAnnotation()
            annotation.coordinate = locationValue
            self.MapView.addAnnotation(annotation)
            
            print("latitude = \(locationValue.latitude)  longitude= \(locationValue.longitude)")
        }
    }
}
    // Do something every time user changes authorization
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        // do something here too
    }
    
// MkMapViewDelegate to interact with the map
    extension ViewController: MKMapViewDelegate{
        func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
            // using the MKPolygon class to create the field boundries.
            if overlay is MKPolygon {
                let polygonView = MKPolygonRenderer(overlay: overlay)
                polygonView.strokeColor = UIColor.black
                return polygonView
                
            }
            return MKOverlayRenderer()
            
        }
        
}


