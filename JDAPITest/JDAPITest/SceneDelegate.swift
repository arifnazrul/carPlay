//
//  SceneDelegate.swift
//  JDAPITest
//
//  Created by capstone on 18.11.19.
//  Copyright © 2019 Capstone. All rights reserved.
//

import UIKit

class SceneDelegate: UIResponder, UIWindowSceneDelegate{
    
    
    var window: UIWindow?
    var navigationController : UINavigationController?

    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {

        
        let sandboxConfig = JDEnvironmentConfiguration.init()
        sandboxConfig.baseURL = "https://sandboxapi.deere.com:443/platform/"
        sandboxConfig.consentToUseDataURI = "https://sandboxapi.deere.com:443/consentToUseOfData/"
        sandboxConfig.consumerKey = "johndeere-rOs5TBJA6sC8BZgIbHJHycNwRJ4YtmxboePjabzr"
        sandboxConfig.secretKey = "99048dfc0694d284ad1ce11be6c3d1e6bacc382720e18ddb12e48899eda11280"
        JDServicesSetup.setupSandboxEnvironment(with: sandboxConfig)
        
        let myConsumerKey = "johndeere-rOs5TBJA6sC8BZgIbHJHycNwRJ4YtmxboePjabzr"
        let mySecretKey = "99048dfc0694d284ad1ce11be6c3d1e6bacc382720e18ddb12e48899eda11280"
        //JDServicesSetup.setupEnvironment(JDEnvironment.STORE, withConsumerKey: myConsumerKey, andSecretKey: mySecretKey)
        
        let loginViewController = JDLoginViewController()
        loginViewController.title = "Login"
       
        let isLogInFlag:Bool = JDSecretManager.isLoggedIn()
         print(isLogInFlag)
        if isLogInFlag {
            
            if let windowScene = scene as? UIWindowScene {
                let childCtrl = ChildController()
                childCtrl.view.backgroundColor = UIColor.white
                

                let window = UIWindow(windowScene: windowScene)
                window.rootViewController = childCtrl
                self.window = window
                window.makeKeyAndVisible()
            }
        }
        else {
               if let windowScene = scene as? UIWindowScene {
                  let window = UIWindow(windowScene: windowScene)
                  window.rootViewController = loginViewController
                  self.window = window
                  window.makeKeyAndVisible()
             }
        }
        
        //let customViewController = UIViewController()
        //customViewController.view.backgroundColor = UIColor.red
        // Use a UIHostingController as window root view controller.
        
//        if let windowScene = scene as? UIWindowScene {
//            let window = UIWindow(windowScene: windowScene)
//            window.rootViewController = loginViewController
//            self.window = window
//            window.makeKeyAndVisible()
//        }
        
        
    
    }

    func sceneDidDisconnect(_ scene: UIScene) {
        // Called as the scene is being released by the system.
        // This occurs shortly after the scene enters the background, or when its session is discarded.
        // Release any resources associated with this scene that can be re-created the next time the scene connects.
        // The scene may re-connect later, as its session was not neccessarily discarded (see `application:didDiscardSceneSessions` instead).
    }

    func sceneDidBecomeActive(_ scene: UIScene) {
        //let myConsumerKey:String = "johndeere-rOs5TBJA6sC8BZgIbHJHycNwRJ4YtmxboePjabzr"
        //let mySecretKey:String = "99048dfc0694d284ad1ce11be6c3d1e6bacc382720e18ddb12e48899eda11280"
        //JDServicesSetup.setupConsumerKey(myConsumerKey, andSecretKey: mySecretKey)
        //JDServicesSetup.setActiveEnvironment(JDEnvironment.STORE)
        //JDServicesSetup.setupEnvironment(JDEnvironment.DEV, withConsumerKey: myConsumerKey, andSecretKey: mySecretKey)
        
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
    }


}

