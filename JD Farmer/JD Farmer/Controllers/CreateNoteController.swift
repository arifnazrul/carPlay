/**
  - **Name**:         CreateNoteController.swift
  - Description: This class contains logic behind CreateNote Intent
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      19.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import Foundation

class CreateNoteController {
    
    /**
       - Parameters:
           - intent: Intent of the type CreateNoteIntent containing all user input through Siri interaction
       - Description: Stores the note locally and in JohnDeere
       - Returns: Boolean indicating success or failure
    */
    func createNote(intent : CreateNoteIntent) -> Bool {
        /// - Todo: Save the Note locally
        /// - Todo: Save the Note in JohnDeere
        return true
    }
}
