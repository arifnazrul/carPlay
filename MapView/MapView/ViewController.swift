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
    @IBOutlet weak var MapView: MKMapView!
    let locationManager = CLLocationManager()
    var compassButton: MKCompassButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setCompass()
        checkLocationServices()
    }
    
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

}

extension ViewController: CLLocationManagerDelegate{
    
    // Do something every time user updates location
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
    
    // Do something every time user changes authorization
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        // do something here too
    }
    
    
}
