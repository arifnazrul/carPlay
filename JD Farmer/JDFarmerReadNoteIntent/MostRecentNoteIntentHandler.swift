//
//  MostRecentNoteIntentHandler.swift
//  JDFarmerReadNoteIntent
//
//  Created by Ajdari, Arian on 18.10.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation

class MostRecentNoteIntentHandler: NSObject, MostRecentNoteIntentHandling {
    
    func confirm(intent: MostRecentNoteIntent, completion: @escaping (MostRecentNoteIntentResponse) -> Void) {
        let mostRecentNoteController = MostRecentNoteController()
        mostRecentNoteController.fetchMostRecentNote { (noteContent) in
            if noteContent != nil {
                completion(MostRecentNoteIntentResponse(code: .ready, userActivity: nil))
            } else {
                completion(MostRecentNoteIntentResponse(code: .failureNoNote, userActivity: nil))
            }
        }
    }
    
    func handle(intent: MostRecentNoteIntent, completion: @escaping (MostRecentNoteIntentResponse) -> Void) {
        let mostRecentNoteController = MostRecentNoteController()
        mostRecentNoteController.fetchMostRecentNote { (noteContent) in
            if let noteContent = noteContent {
                completion(MostRecentNoteIntentResponse.success(mostRecentNote: noteContent))
            }
        }
    }
}
