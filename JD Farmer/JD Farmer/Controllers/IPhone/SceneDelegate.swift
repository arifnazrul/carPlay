/**
  - **Name**:         SceneDelegate.swift
  - Description: This file contains main methods which does shortcut donation and checks screen changes
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      28.10.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import UIKit
import SwiftUI
import RealmSwift
import Intents
import os.log

class SceneDelegate: UIResponder, UIWindowSceneDelegate {
    /// Window variable
    var window: UIWindow?
    


    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {

        /// Create the SwiftUI view that provides the window contents.
        let contentView = ContentView()
        
        /**
                    Initialiting the Realm and adding instances of a User
                            print method prints the path to the .realm file
         */
        
        DatabaseConfiguration.init(path: Bundle.main.path(forResource: "InitialDummyDatacopy", ofType: "json")!)
        
        donateInteraction()
        donateInteractionCreateNote()
        donateInteractionMachineAlerts()
        
        
        /// Use a UIHostingController as window root view controller.
        if let windowScene = scene as? UIWindowScene {
            let window = UIWindow(windowScene: windowScene)
            window.rootViewController = UIHostingController(rootView: contentView)
            self.window = window
            window.makeKeyAndVisible()
        }
    }
    
    /**
       - Description: This function  donates a shortcut to Shortcut App
       - Returns: void
    */
     func donateInteraction() {
       let intent = LastVisitIntent()
       
       intent.suggestedInvocationPhrase = "JD Driver give me updates"
       
       let interaction = INInteraction(intent: intent, response: nil)
       
       interaction.donate { (error) in
         if error != nil {
           if let error = error as NSError? {
             os_log("Interaction donation failed: %@", log: OSLog.default, type: .error, error)
           } else {
             os_log("Successfully donated interaction")
           }
         }
       }
     }
    
    /**
       - Description: This function  donates a shortcut to Shortcut App
       - Returns: void
    */
    func donateInteractionCreateNote() {
        let intent = CreateNoteIntent()
      
        intent.suggestedInvocationPhrase = "JD Driver take a note"
    
        let interaction = INInteraction(intent: intent, response: nil)
    
        interaction.donate { (error) in
            if error != nil {
                if let error = error as NSError? {
                    os_log("Interaction donation failed: %@", log: OSLog.default, type: .error, error)
          
                } else {
            os_log("Successfully donated interaction")
          }
        }
      }
    }
    
    /**
       - Description: This function  donates a shortcut to Shortcut App
       - Returns: void
    */
    func donateInteractionMachineAlerts() {
        let intent = MachineAlertsIntent()
        
        intent.suggestedInvocationPhrase = "JD Driver machine alerts"
        
        let interaction = INInteraction(intent: intent, response: nil)
        
        interaction.donate { (error) in
          if error != nil {
            if let error = error as NSError? {
              os_log("Interaction donation failed: %@", log: OSLog.default, type: .error, error)
            } else {
              os_log("Successfully donated interaction")
            }
          }
        }
    }
    
    
    func sceneDidDisconnect(_ scene: UIScene) {
        
    }

    func sceneDidBecomeActive(_ scene: UIScene) {
       
    }

    func sceneWillResignActive(_ scene: UIScene) {
       
    }

    func sceneWillEnterForeground(_ scene: UIScene) {
        
    }

    func sceneDidEnterBackground(_ scene: UIScene) {
        
    }

}
