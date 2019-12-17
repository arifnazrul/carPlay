/**
  - **Name**:         IntentHandler.swift
  - Description: This file is an Intent Handler
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      19.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import Intents

class IntentHandler: INExtension {
    
    /**
     This function handles the logic of the intent
    */
    override func handler(for intent: INIntent) -> Any {
         guard intent is MachineAlertsIntent else {
                   fatalError("Unhandled intent type: \(intent)")
               }
               
        return MachineAlertsIntentHandler()
    }
    
}
