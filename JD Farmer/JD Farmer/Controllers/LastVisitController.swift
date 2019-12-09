/**
  - **Name**:         LastVisitController.swift
  - Description: This class contains logic behind LastVisit Intent
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      19.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import Foundation

class LastVisitController {
    
    /**
       - Parameters: void
       - Description: It gets data from JohnDeere API giving updates about what happened between two visits on the field (Default is last)
       - Returns: String containing information
    */
    func fetchUpdates(completion: @escaping (String) -> Void) {
        
        /// - Todo: Pull data from API
        
        let updates = "Since your last visit on the 7th of July, crocodiles ate 60% of the strawberries on the Strawberry Field. Seeding of the Strawberry seeds was conducted from the 10th till 13th of October on 60% of the Strawberry field that was invaded by the crocodiles."
        
        completion(updates)
    }
}
