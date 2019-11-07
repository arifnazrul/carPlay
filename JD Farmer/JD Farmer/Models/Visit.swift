//
//  Visit.swift
//  JD Farmer
//
//  Created by capstone on 07.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import RealmSwift

class Visit: Object {
    
    ///Primary key
    @objc dynamic var ID_Visit: UUID?
    ///Foreign key of the User
    @objc dynamic var User_ID: UUID?
    ///Foreign key of the Field
    @objc dynamic var Field_ID: UUID?
    ///Date of the last visit
    @objc dynamic var lastVisit: Date?
    
}
