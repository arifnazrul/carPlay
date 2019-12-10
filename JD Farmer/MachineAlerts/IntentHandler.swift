//
//  IntentHandler.swift
//  MachineAlerts
//
//  Created by capstone on 10.12.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Intents

class IntentHandler: INExtension {
    
    override func handler(for intent: INIntent) -> Any {
         guard intent is MachineAlertsIntent else {
                   fatalError("Unhandled intent type: \(intent)")
               }
               
        return MachineAlertsIntentHandler()
    }
    
}
