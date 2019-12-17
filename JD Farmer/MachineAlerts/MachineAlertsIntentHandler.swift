/**
  - **Name**:         MachineAlertsIntentHandler.swift
  - Description: This file serves as a Handler for MachineAlerts Intent
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      19.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/
import Foundation
import Intents


class MachineAlertsIntentHandler: NSObject, MachineAlertsIntentHandling {
    /**
     This function handles the logic of the intent
    */
    func handle(intent: MachineAlertsIntent, completion: @escaping (MachineAlertsIntentResponse) -> Void) {
        if intent.fieldName == .potato {
            completion(MachineAlertsIntentResponse.success(updates: "Since your last visit on the 5th of December the tractor T41 broke."))
        }else if intent.fieldName == .barley {
            completion(MachineAlertsIntentResponse.success(updates: "Since your last visit on the 10th of December two flags were set. A huge stone was reported in the middle of the field and crocodiles ate 60% of the grapevines on the Grapevine Field!"))
        } else if intent.fieldName == .sugar_beet {
            completion(MachineAlertsIntentResponse.success(updates: "Since your last visit on 10th of December the seeding of the sugar beet has started on the 11th of December and 60% of the field is seeded."))
        }
    }
    
    /**
     This function resolves field name
    */
    func resolveFieldName(for intent: MachineAlertsIntent, with completion: @escaping (Enum4ResolutionResult) -> Void) {
        if intent.fieldName == .unknown {
            completion(Enum4ResolutionResult.needsValue())
        } else {
            completion(Enum4ResolutionResult.success(with: intent.fieldName))
        }
    }
    
    
}
