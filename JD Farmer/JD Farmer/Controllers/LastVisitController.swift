//
//  LastVisitController.swift
//  JD Farmer
//
//  Created by Ajdari, Arian on 19.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation



class LastVisitController
{
    
    func fetchUpdates(completion: @escaping (String) -> Void) {
        //var updates = "Crocodile ate your strawberries"
        //updates += "."
        
        let updates = "Since your last visit on the 7th of July, crocodiles ate 60% of the strawberries on the Strawberry Field. Seeding of the Strawberry seeds was conducted from the 10th till 13th of October on 60% of the Strawberry field that was invaded by the crocodiles."
        
        completion(updates)
        
    }
}
