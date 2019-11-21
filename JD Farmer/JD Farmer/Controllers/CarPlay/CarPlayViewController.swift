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
    
    @IBOutlet weak var MapView: MKMapView!
    
    @IBOutlet var tapVar: UITapGestureRecognizer!
    
    let locationManager = CLLocationManager()
    var compassButton: MKCompassButton!
    // creating an object of the model: field class
    var field = FieldController(filename: "FraunhoferCoordinates")
    
    @IBAction func tapEvent(_ sender: UITapGestureRecognizer) {
        print("I am in")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        MapView.delegate = self
        setCompass()
        checkLocationServices()
        
        //MapView.addGestureRecognizer(<#T##gestureRecognizer: UIGestureRecognizer##UIGestureRecognizer#>)
        
        /*let locations = [
                   CLLocationCoordinate2D(latitude: 49.431655, longitude: 7.752886),
                   CLLocationCoordinate2D(latitude: 49.431665, longitude: 7.752896),
                   CLLocationCoordinate2D(latitude: 49.431675, longitude: 7.752906),
        ]
        var polyline = MKGeodesicPolyline(coordinates: locations, count: locations.count)

        MapView.addOverlay(polyline)*/
    }
    
  
   
    
    override func viewWillAppear(_ animated: Bool) {
        let gestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(tapEvent))
        MapView.addGestureRecognizer(gestureRecognizer)
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
    
    // Creating a FieldOverlay object initialized with the field model object created above. Adding the object to the MapView Overlays.
    func addOverlay(){
        let overlay = FieldOverlay(field: field)
        MapView.addOverlay(overlay)
        
    }
    
    // To add the customized boundries to the MapView.Provided boundries are fetched from the field model class data.
    func addBounary(){
        MapView.addOverlay(MKPolygon(coordinates: field.boundary, count: field.boundary.count))
    }
    
    private func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) ->  MKPolylineRenderer {
        // using the MKPolygon class to create the field boundries.
        if overlay is MKPolyline {
            print("LINIJA DETEKTOVANA")
            let polygonView = MKPolylineRenderer(overlay: overlay)
            polygonView.strokeColor = UIColor.black.withAlphaComponent(0.5)
            polygonView.lineWidth = 5
            return polygonView
            
        }
        return MKPolylineRenderer()
        
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
            
            //lat += 0.001
           // long += 0.001
            
            print("latitude = \(lat)  longitude= \(long)")
        }
    }
}


var lat = 49.431655
var long = 7.752886


