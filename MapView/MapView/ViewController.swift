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
        self.locationManager.requestWhenInUseAuthorization()
        super.viewDidLoad()
        checkLocationServices()
    }
    
    func setupLocationManager(){
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
    }
    
    // Check if user has the Location Service enabled on his phone
    func checkLocationServices(){
        if CLLocationManager.locationServicesEnabled(){
            // setup location Manager
            setupLocationManager()
            locationManager.startUpdatingLocation()
            checkLocationAuthorization()
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
        if let location = locations.last{
        let center = CLLocationCoordinate2D(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
        let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
        self.MapView.setRegion(region, animated: true)
            
        }
        
    }
    
    // Do something every time user changes authorization
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        // do something here too
    }
}
