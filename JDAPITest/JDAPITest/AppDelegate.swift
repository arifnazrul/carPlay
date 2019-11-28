//
//  AppDelegate.swift
//  JDAPITest
//
//  Created by capstone on 18.11.19.
//  Copyright © 2019 Capstone. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {


    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
      /*let timeline = JDLoginViewController()
      let navigation = UINavigationController(rootViewController: timeline)

      let frame = UIScreen.main.bounds
      window = UIWindow(frame: frame)

      window!.rootViewController = navigation
      window!.makeKeyAndVisible()
        
      return true*/
        
      /*let mainStoryboard:UIStoryboard = UIStoryboard(name: "Main", bundle: nil)
      let homePage = mainStoryboard.instantiateViewController(withIdentifier: "loginViewCtrl") as! JDLoginViewController
      self.window?.rootViewController = homePage*/
        
      /*let fir = JDLoginViewController()
      self.window?.rootViewController = UINavigationController(rootViewController: fir)*/
        
        
        // Normal implementation
        //let myConsumerKey:String = "johndeere-rOs5TBJA6sC8BZgIbHJHycNwRJ4YtmxboePjabzr"
        //let mySecretKey:String = "99048dfc0694d284ad1ce11be6c3d1e6bacc382720e18ddb12e48899eda11280"
        //JDServicesSetup.setupConsumerKey(myConsumerKey, andSecretKey: mySecretKey)
        //JDServicesSetup.setActiveEnvironment(JDEnvironment.STORE)
        
        
        // Sandbox implementation (if the app created on developer.deere.com is provided with sanbox url, in that case above implementation wouldn't work)
        let sandboxConfig = JDEnvironmentConfiguration.init()
        sandboxConfig.baseURL = "https://sandboxapi.deere.com:443/platform/"
        sandboxConfig.consentToUseDataURI = "https://sandboxapi.deere.com:443/platform/consentToUseOfData/"
        sandboxConfig.consumerKey = "johndeere-rOs5TBJA6sC8BZgIbHJHycNwRJ4YtmxboePjabzr"
        sandboxConfig.secretKey = "99048dfc0694d284ad1ce11be6c3d1e6bacc382720e18ddb12e48899eda11280"
        
        JDServicesSetup.setupSandboxEnvironment(with: sandboxConfig)
        
        let loginViewController = JDLoginViewController()
        loginViewController.title = "Login"

        let frame = UIScreen.main.bounds
        window = UIWindow(frame: frame)

        window!.rootViewController = loginViewController
        window!.makeKeyAndVisible()
        
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

