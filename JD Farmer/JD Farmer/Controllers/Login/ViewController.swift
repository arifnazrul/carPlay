//
//  ViewController.swift
//  JD Farmer
//
//  Created by Ajdari, Arian on 17.10.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import UIKit
import Intents
import os.log

class ViewController: UIViewController {
    @IBOutlet weak var labelSignIn: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        //        UIApplication.shared.statusBarView?.backgroundColor = UIColor.red
        
        /*let jdGreen = UIColor(red: 54/255, green: 124/255, blue: 43/255, alpha: 1.0)
        
        // change the status bar color more difficult way
        if #available(iOS 13.0, *) {
            let app = UIApplication.shared
            let statusBarHeight: CGFloat = app.statusBarFrame.size.height
            
            let statusbarView = UIView()
            statusbarView.backgroundColor = jdGreen
            view.addSubview(statusbarView)
            
            statusbarView.translatesAutoresizingMaskIntoConstraints = false
            statusbarView.heightAnchor
                .constraint(equalToConstant: statusBarHeight).isActive = true
            statusbarView.widthAnchor
                .constraint(equalTo: view.widthAnchor, multiplier: 1.0).isActive = true
            statusbarView.topAnchor
                .constraint(equalTo: view.topAnchor).isActive = true
            statusbarView.centerXAnchor
                .constraint(equalTo: view.centerXAnchor).isActive = true
            
        } else {
            let statusBar = UIApplication.shared.value(forKeyPath: "statusBarWindow.statusBar") as? UIView
            statusBar?.backgroundColor = jdGreen
        }*/
        
        //code for the MostRecentNoteIntent
        donateInteraction()
    }
    
    func donateInteraction() {
        let intent = MostRecentNoteIntent()
        
        intent.suggestedInvocationPhrase = "The most recent"
        
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
    
    var btnSignInClickCount = 0;
    
    @IBAction func signInButton(_ sender: UIButton) {
        btnSignInClickCount += 1
        labelSignIn.text = String(btnSignInClickCount)
    }
}
