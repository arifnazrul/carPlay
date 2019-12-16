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
        if intent.fieldName == .potato {
            completion(MachineAlertsIntentResponse.success(updates: "Since your last visit on the 5th of December the tractor T41 broke."))
        }else if intent.fieldName == .barley {
            completion(MachineAlertsIntentResponse.success(updates: "Since your last visit on the 10th of December two flags were set. A huge stone was reported in the middle of the field and crocodiles ate 60% of the grapevines on the Grapevine Field!"))
        } else if intent.fieldName == .sugar_beet {
            completion(MachineAlertsIntentResponse.success(updates: "Since your last visit on 10th of December the seeding of the sugar beet has started on the 11th of December and 60% of the field is seeded."))
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
