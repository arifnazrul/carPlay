//
//  Field.swift
//  JD Farmer
//
//  Created by capstone on 07.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import RealmSwift

class Field: Object {
    
    ///Primary key
    @objc dynamic var ID_Field = UUID().uuidString
    ///Foreign key of the Organization
    @objc dynamic var Organization_ID = Organization.primaryKey()
    ///Name
    @objc dynamic var name: String?
    ///Coordinates of the field
//    TODO: Figure out the best way to save the field coordinates
    @objc dynamic var coordinates: String?
    
    override static func primaryKey() -> String? {
        return "ID_Field"
    }
    
}
