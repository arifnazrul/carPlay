//
//  MostRecentNoteController.swift
//  JD Farmer
//
//  Created by Ajdari, Arian on 18.10.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation

struct MostRecentNoteController{
    
    func fetchMostRecentNote(completion: @escaping (_ noteContent:String?) -> Void) {
        let noteContent = "water level on the field 17 is higher than optimal. Check with your agronomists."
        
        completion(noteContent)
    }
}
