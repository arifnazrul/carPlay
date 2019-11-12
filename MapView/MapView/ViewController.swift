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

class ViewController: UIViewController {
    
    @IBOutlet weak var MapView: MKMapView!
    let locationManager = CLLocationManager()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        checkLocationServices()
    }
    
    func setupLocationManager(){
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        self.locationManager.requestWhenInUseAuthorization()
    }
    
    // Check if user has the Location Service enabled on his phone
    func checkLocationServices(){
        if CLLocationManager.locationServicesEnabled(){
            // setup location Manager
            setupLocationManager()
            checkLocationAuthorization()
            locationManager.startUpdatingLocation()
            
        }
        else{
            // show alert letting userknow thez have to turn this on
            print("Your Location Services are Off")
        }
    }
    
    // check the authorization statuses
    func checkLocationAuthorization(){
        
        switch CLLocationManager.authorizationStatus() {
        //only when the app is Open
        case .authorizedWhenInUse:
            MapView.showsUserLocation = true
            break
        case .denied:
            // show alerts instructing how to turn on the permissions
            break
        case .notDetermined:
            locationManager.requestWhenInUseAuthorization()
        case .restricted:
            //show alerts.
            break
        // when the app is open in the background
        case .authorizedAlways:
            MapView.showsUserLocation = true
            break
        }
    }

}

extension ViewController: CLLocationManagerDelegate{
    
    // Do something every time user updates location
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let locationValue: CLLocationCoordinate2D = manager.location!.coordinate
        if let location = locations.first{
            let center = CLLocationCoordinate2D(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
            let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
            self.MapView.setRegion(region, animated: true)
            let annotation = MKPointAnnotation()
            annotation.coordinate = locationValue
            MapView.addAnnotation(annotation)
            print("locations = \(locations)")
        }
        
        
    }
    
    // Do something every time user changes authorization
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        // do something here too
    }
}
