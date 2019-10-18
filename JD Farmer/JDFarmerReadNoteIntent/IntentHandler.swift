//
//  IntentHandler.swift
//  JDFarmerReadNoteIntent
//
//  Created by Ajdari, Arian on 18.10.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Intents

class IntentHandler: INExtension {
    
    override func handler(for intent: INIntent) -> Any {
        // This is the default implementation.  If you want different objects to handle different intents,
        // you can override this and return the handler you want for that particular intent.
        guard intent is MostRecentNoteIntent else {
            fatalError("Unhandled intent type: \(intent)")
        }
        return MostRecentNoteIntentHandler()
    }
    
}
