//
//  CarPlayViewController.swift
//  JD Driver
//
//  Created by Ajdari, Arian on 21.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import UIKit
import CarPlay
import MapKit
import CoreLocation




class CarPlayViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {
    
    var mainView: UIView?
    
    var lat = 49.431655
    var long = 7.752886

    
   
    @IBOutlet weak var MapView: MKMapView!
    
   
    
   
    let locationManager = CLLocationManager()
   
    
  
    
    override func viewDidLoad() {
        super.viewDidLoad()
        MapView.delegate = self
        checkLocationServices()
    }
    
  
    
    func checkLocationServices() {
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
    
    
   

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        
        let locationValue: CLLocationCoordinate2D = manager.location!.coordinate
        
        if let location = locations.last{
            let center = CLLocationCoordinate2D(latitude: lat , longitude: long)
            let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
            self.MapView.setRegion(region, animated: true)
            
            let annotation = MKPointAnnotation()
            annotation.coordinate = locationValue
            self.MapView.addAnnotation(annotation)
            
            
            print("latitude = \(lat)  longitude= \(long)")
        }
    }
 
}
