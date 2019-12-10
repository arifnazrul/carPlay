//
//  MachineAlertsIntentHandler.swift
//  MachineAlerts
//
//  Created by capstone on 10.12.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import Intents


class MachineAlertsIntentHandler: NSObject, MachineAlertsIntentHandling {
    func handle(intent: MachineAlertsIntent, completion: @escaping (MachineAlertsIntentResponse) -> Void) {
        if intent.fieldName == .tomato {
            completion(MachineAlertsIntentResponse.success(updates: "Since your last visit on the 5th of December the tractor T41 broke."))
        }else {
            completion(MachineAlertsIntentResponse.success(updates: "Since your last visit on the 10th of December there was a huge stone reported in the middle of the field."))
        }
    }
    
    func resolveFieldName(for intent: MachineAlertsIntent, with completion: @escaping (Enum4ResolutionResult) -> Void) {
        if intent.fieldName == .unknown {
            completion(Enum4ResolutionResult.needsValue())
        } else {
            completion(Enum4ResolutionResult.success(with: intent.fieldName))
        }
    }
    
    
}
