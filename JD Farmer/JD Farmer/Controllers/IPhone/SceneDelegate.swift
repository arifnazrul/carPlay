//
//  SceneDelegate.swift
//  JD Farmer
//
//  Created by Ajdari, Arian on 28.10.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import UIKit
import SwiftUI
import RealmSwift
import Intents
import os.log

class SceneDelegate: UIResponder, UIWindowSceneDelegate {

    var window: UIWindow?
    


    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        // Use this method to optionally configure and attach the UIWindow `window` to the provided UIWindowScene `scene`.
        // If using a storyboard, the `window` property will automatically be initialized and attached to the scene.
        // This delegate does not imply the connecting scene or session are new (see `application:configurationForConnectingSceneSession` instead).

        // Create the SwiftUI view that provides the window contents.
        let contentView = ContentView()
        
        /**
                    Initialiting the Realm and adding instances of a User
                            print method prints the path to the .realm file
         */
        
        //let realmPath = Bundle.main.url(forResource: "default", withExtension: "realm")
      //  let config = Realm.Configuration(inMemoryIdentifier: realmPath)
       // let realm = try! Realm(configuration: config)
       //print(realmPath)
        DatabaseConfiguration.init(path: Bundle.main.path(forResource: "InitialDummyDatacopy", ofType: "json")!)
        
        //let user = realm.object(ofType: User.self, forPrimaryKey: "1")
        //print(user?.username)
        
        
        donateInteraction()
        donateInteractionCreateNote()
        donateInteractionMachineAlerts()
        
        
        // Use a UIHostingController as window root view controller.
        if let windowScene = scene as? UIWindowScene {
            let window = UIWindow(windowScene: windowScene)
            window.rootViewController = UIHostingController(rootView: contentView)
            self.window = window
            window.makeKeyAndVisible()
        }
    }
    
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
        // Called as the scene is being released by the system.
        // This occurs shortly after the scene enters the background, or when its session is discarded.
        // Release any resources associated with this scene that can be re-created the next time the scene connects.
        // The scene may re-connect later, as its session was not neccessarily discarded (see `application:didDiscardSceneSessions` instead).
    }

    func sceneDidBecomeActive(_ scene: UIScene) {
        // Called when the scene has moved from an inactive state to an active state.
        // Use this method to restart any tasks that were paused (or not yet started) when the scene was inactive.
    }

    func sceneWillResignActive(_ scene: UIScene) {
        // Called when the scene will move from an active state to an inactive state.
        // This may occur due to temporary interruptions (ex. an incoming phone call).
    }

    func sceneWillEnterForeground(_ scene: UIScene) {
        // Called as the scene transitions from the background to the foreground.
        // Use this method to undo the changes made on entering the background.
    }

    func sceneDidEnterBackground(_ scene: UIScene) {
        // Called as the scene transitions from the foreground to the background.
        // Use this method to save data, release shared resources, and store enough scene-specific state information
        // to restore the scene back to its current state.
        
        ///TODO: copy database file from library to project version
    }


}

