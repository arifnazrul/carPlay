//
//  AppDelegate.swift
//  JD Farmer
//
//  Created by Ajdari, Arian on 28.10.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import UIKit
import CarPlay

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate,CPApplicationDelegate,  CPMapTemplateDelegate {
    
    var carWindow: CPWindow?
    var interfaceController: CPInterfaceController?
    var mapTemplate: CPMapTemplate?
    var cp: CarPlayViewController?
    
    var window: UIWindow?
    
    func application(_ application: UIApplication, didConnectCarInterfaceController interfaceController: CPInterfaceController, to window: CPWindow) {
        print("[CARPLAY] CONNECTED TO CARPLAY!")
        
        
        self.interfaceController = interfaceController
        self.carWindow = window
        
        
       print("[CARPLAY] CREATING CPMapTemplate...")

        
        let mapTemplate = createTemplate()
        mapTemplate.mapDelegate = self
        
        self.mapTemplate = mapTemplate
        
        print("[CARPLAY] SETTING ROOT OBJECT OF INTERFACECONTROLLER TO MAP TEMPLATE...")
        interfaceController.setRootTemplate(mapTemplate, animated: true)
        
        print("[CARPLAY] SETTING CustomNavigationViewController as root VC...")
        
        cp = CarPlayViewController()
        window.rootViewController = cp
        
      
        
     
        
        //let rootTemplate: CPMapTemplate = createTemplate()
       //self.interfaceController?.setRootTemplate(rootTemplate, animated: false)
        
    }
    
    func createTemplate() -> CPMapTemplate {
        // Create the default CPMapTemplate objcet (you may subclass this at your leasure)
        let mapTemplate = CPMapTemplate()
        
        // Create the different CPBarButtons
        
        let searchBarButton = createBarButton(.search)
        mapTemplate.leadingNavigationBarButtons = [searchBarButton]
        
        let panningBarButton = createBarButton(.panning)
        mapTemplate.trailingNavigationBarButtons = [panningBarButton]
        
        // Always show the NavigationBar
        //mapTemplate.automaticallyHidesNavigationBar = false
        
        return mapTemplate
    }
    
    func mapTemplateWillDismissPanningInterface(_ mapTemplate: CPMapTemplate) {
        mapTemplate.trailingNavigationBarButtons = [createBarButton(.panning)]
    }
    
    // MARK: - CPBarButton creation
    enum BarButtonType: String {
        case search = "Search"
        case panning = "Pan map"
        case dismiss = "Dismiss"
    }
    
    
    
    private func createBarButton(_ type: BarButtonType) -> CPBarButton {
        let barButton = CPBarButton(type: .text) { (button) in
            print("[CARPLAY] SEARCH MAP TEMPLATE \(button.title ?? "-") TAPPED")
            
            switch(type) {
            case .dismiss:
                // Dismiss the map panning interface
                self.mapTemplate?.dismissPanningInterface(animated: true)
            case .panning:
               
                
                
                
                
                self.mapTemplate?.showPanningInterface(animated: true)
                
                self.mapTemplate?.trailingNavigationBarButtons = [self.createBarButton(.dismiss)]
            default:
                break
            }
        }
        
        // Set title based on type
        barButton.title = type.rawValue
        
        return barButton
    }
    internal func mapTemplate(_ mapTemplate: CPMapTemplate, panEndedWith direction: CPMapTemplate.PanDirection) {
        switch direction {
        case .down:
            cp?.lat -= 0.003
            print("down")
        case .up:
           cp?.lat += 0.003
           print("up")
        case .left:
            cp?.long -= 0.003
            print("left")
        case .right:
           cp?.long += 0.003
           print("right")
        default:
            break
        }
    }
    
    
    
    func application(_ application: UIApplication, didDisconnectCarInterfaceController interfaceController: CPInterfaceController, from window: CPWindow) {
        
    }

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

