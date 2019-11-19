//
//  IntentHandler.swift
//  CreateNote
//
//  Created by Ajdari, Arian on 19.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Intents

class IntentHandler: INExtension {
    
    override func handler(for intent: INIntent) -> Any {
        guard intent is CreateNoteIntent else {
            fatalError("Unhandled intent type: \(intent)")
        }
        
       
        return CreateNoteIntentHandler()
    }
    
}
