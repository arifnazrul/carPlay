//
//  LastVisitIntentHandler.swift
//  JD Farmer
//
//  Created by Ajdari, Arian on 19.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import Intents
import UIKit

class LastVisitIntentHandler: NSObject, LastVisitIntentHandling {
    
    
    
    
    func resolveFieldName(for intent: LastVisitIntent, with completion: @escaping (Enum3ResolutionResult) -> Void) {
        if intent.fieldName == .unknown {
            completion(Enum3ResolutionResult.needsValue())
        } else {
            completion(Enum3ResolutionResult.success(with: intent.fieldName))
        }
    }
    
    func handle(intent: LastVisitIntent, completion: @escaping (LastVisitIntentResponse) -> Void) {
        
        //let lastVisitController = LastVisitController()
        
        /*lastVisitController.fetchUpdates { (updates) in
            if !updates.isEmpty {
                completion(LastVisitIntentResponse.success(updates: updates))
            } else if updates != nil {
                completion(LastVisitIntentResponse(code: .noUpdates, userActivity: nil))
            }
        }*/
        
        if intent.fieldName == .potato{
            completion(LastVisitIntentResponse.success(updates: "You have one reminder. The reminder is: Call the agronomist"))
        } else if intent.fieldName == .strawberry{
            completion(LastVisitIntentResponse.gettingNotes(gettingNotes: "Call the agronomist after 21th of December. There are no more reminders."))
        } else {
            completion(LastVisitIntentResponse.success(updates: "The first update: Since your last visit on the 10th of December the seeding of the sugar beet has started on the 11th of December. The second update: Since your last visit on the 7th of July, crocodiles ate 60% of the sugar beets on the Sugar Beet Field!"))
           
        }
        
       //var a = CarPlayViewController()
        
    }
    
   

}
