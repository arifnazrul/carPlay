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
    
    var lat = 49.431581
    var long = 7.752951
    var offsetLat = 0.000
    var offsetLong = 0.000
    
    
    var interval = 0
    var tick = 0
    var growth = 3
    
   
    @IBOutlet weak var MapView: MKMapView!
    
    
    var overlays: [MKOverlay]!
    var radius : Double!
    
   
    
   
    let locationManager = CLLocationManager()
   
    let places = Place.getPlaces()
    let fraunhoferPlaces = PlacesFraunhofer.getPlaces()
    
  
    
    override func viewDidLoad() {
        super.viewDidLoad()
        MapView.delegate = self
        radius = 10
        checkLocationServices()
        addAnnotations()
        addPolyline()
        addPolygon()
        
        
        overlays = MapView.overlays
        
    
    }
    
    func addAnnotations() {
        
            MapView?.delegate = self
            MapView?.addAnnotations(places)

            let overlays = [MKCircle(center: CLLocationCoordinate2D(latitude: lat, longitude: long), radius: radius)]
            MapView?.addOverlays(overlays)
            
           
     
            
        }
    func addPolyline() {
        
        for a in fraunhoferPlaces {
                var locations = a.map { $0.coordinate }
                
                
                let polyline = MKPolyline(coordinates: &locations, count: locations.count)
                
                MapView?.addOverlay(polyline)
        }
        
        
    }
    
    func addPolygon() {
        
        for a in fraunhoferPlaces {
            var locations = a.map { $0.coordinate }
                   let polygon = MKPolygon(coordinates: &locations, count: locations.count)
                   MapView?.addOverlay(polygon)
                   
               }
       
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
            
            
            
            let center = CLLocationCoordinate2D(latitude: lat + offsetLat , longitude: long + offsetLong)
            let region = MKCoordinateRegion(center: center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
            self.MapView.setRegion(region, animated: true)
            
            let annotation = MKPointAnnotation()
            annotation.coordinate = locationValue
            self.MapView.addAnnotation(annotation)
            
        
            
            
            //print("latitude = \(lat)  longitude= \(long)")
        }
    }
    
    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        if annotation is MKUserLocation {
            return nil
        }
            
        else {
            let annotationView = mapView.dequeueReusableAnnotationView(withIdentifier: "annotationView") ?? MKAnnotationView()
            annotationView.image = UIImage(named: "place icon")
            annotationView.rightCalloutAccessoryView = UIButton(type: .detailDisclosure)
            annotationView.canShowCallout = true
            return annotationView
        }
    }
    
    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        if overlay is MKCircle {
            let renderer = MKCircleRenderer(overlay: overlay)
            renderer.fillColor = UIColor.red
            renderer.strokeColor = UIColor.red
            renderer.lineWidth = 2
            return renderer
        
        } else if overlay is MKPolyline {
            let renderer = MKPolylineRenderer(overlay: overlay)
            renderer.strokeColor = UIColor.orange
            renderer.lineWidth = 3
            return renderer
        
        } else if overlay is MKPolygon {
            let renderer = MKPolygonRenderer(polygon: overlay as! MKPolygon)
            renderer.fillColor = UIColor.black.withAlphaComponent(0.5)
            renderer.strokeColor = UIColor.orange
            renderer.lineWidth = 2
            return renderer
        }
        
        return MKOverlayRenderer()
    }
    
    func mapView(_ mapView: MKMapView, annotationView view: MKAnnotationView, calloutAccessoryControlTapped control: UIControl) {
        guard let annotation = view.annotation as? Place, let title = annotation.title else { return }
        
        let alertController = UIAlertController(title: "Welcome to \(title)", message: "You've selected \(title)", preferredStyle: .alert)
        let cancelAction = UIAlertAction(title: "OK", style: .cancel, handler: nil)
        alertController.addAction(cancelAction)
        present(alertController, animated: true, completion: nil)
    }
}
