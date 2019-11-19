//
//  LastVisitIntentHandler.swift
//  JD Farmer
//
//  Created by Ajdari, Arian on 19.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import Intents

class LastVisitIntentHandler: NSObject, LastVisitIntentHandling {
    func handle(intent: LastVisitIntent, completion: @escaping (LastVisitIntentResponse) -> Void) {
        
        let lastVisitController = LastVisitController()
        
        lastVisitController.fetchUpdates { (updates) in
            if !updates.isEmpty {
                completion(LastVisitIntentResponse.success(updates: updates))
            } else if updates != nil {
                completion(LastVisitIntentResponse(code: .noUpdates, userActivity: nil))
            }
        }
    }
    
   

}
