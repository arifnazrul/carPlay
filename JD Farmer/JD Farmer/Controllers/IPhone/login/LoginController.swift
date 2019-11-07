//
//  loginController.swift
//  JD Farmer
//
//  Created by Mohammed Arif on 07.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//


import UIKit

class LoginController: UIViewController {
    @IBOutlet weak var labelSignIn: UILabel!
    
    var mainView: UIView?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if mainView == nil {
            mainView = Bundle.main.loadNibNamed("Login", owner: self, options: nil)?.first as? UIView
                       
                       mainView?.frame = view.bounds
                       if let mainViewUnwrapped = mainView {
                           self.view.addSubview(mainViewUnwrapped)
                       }

        }
               // Do any additional setup after loading the view.
//        UIApplication.shared.statusBarView?.backgroundColor = UIColor.red
        
        let jdGreen = UIColor(red: 54/255, green: 124/255, blue: 43/255, alpha: 1.0)

        // change the status bar color more difficult way
        /*if #available(iOS 13.0, *) {
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
    }
    
    @IBAction func signInButton(_ sender: UIButton) {
        
    }
}
