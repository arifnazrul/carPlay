//
//  ViewController.swift
//  PizzaReverse
//
//  Created by Ajdari, Arian on 17.10.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import UIKit
import Intents

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        INPreferences.requestSiriAuthorization {
            (status) in
        }
        INVocabulary.shared().setVocabularyStrings(["push up", "sit up", "pull up"], of: .workoutActivityName)
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

