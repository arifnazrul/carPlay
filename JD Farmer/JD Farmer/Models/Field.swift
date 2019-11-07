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
    @objc dynamic var ID_Field: UUID?
    ///Foreign key of the Organization
    @objc dynamic var Organization_ID: UUID?
    ///Name
    @objc dynamic var name: String?
    ///Coordinates of the field
//    TODO: Figure out the best way to save the field coordinates
    @objc dynamic var coordinates: String?
    
    
}
