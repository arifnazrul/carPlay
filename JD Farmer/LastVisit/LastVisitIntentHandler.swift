/**
  - **Name**:         LastVisitIntentHandler.swift
  - Description: This file serves as a Handler for LastVisit Intent
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      19.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/


import Foundation
import Intents
import UIKit

class LastVisitIntentHandler: NSObject, LastVisitIntentHandling {
    
    /**
     This function resolves field name
    */
    func resolveFieldName(for intent: LastVisitIntent, with completion: @escaping (Enum3ResolutionResult) -> Void) {
        if intent.fieldName == .unknown {
            completion(Enum3ResolutionResult.needsValue())
        } else {
            completion(Enum3ResolutionResult.success(with: intent.fieldName))
        }
    }
    
    /**
     This function handles the logic of the intent
    */
    func handle(intent: LastVisitIntent, completion: @escaping (LastVisitIntentResponse) -> Void) {
        
        if intent.fieldName == .potato{
            completion(LastVisitIntentResponse.success(updates: "You have one reminder. The reminder is: Call the agronomist"))
        } else if intent.fieldName == .strawberry{
            completion(LastVisitIntentResponse.gettingNotes(gettingNotes: "Call the agronomist. There are no more reminders."))
        } else {
            completion(LastVisitIntentResponse.success(updates: "The first update: Since your last visit on the 10th of December the seeding of the sugar beet has started on the 11th of December. The second update: Since your last visit on the 7th of July, crocodiles ate 60% of the sugar beets on the Sugar Beet Field!"))
           
        }
        
    }
    
   

}
