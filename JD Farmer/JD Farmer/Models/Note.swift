//
//  Notes.swift
//  JD Farmer
//
//  Created by capstone on 07.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import RealmSwift

class  Note: Object {
    
    ///Primary key
    @objc dynamic var ID_Note: UUID?
    ///Foreign key of the Field
    @objc dynamic var Field_ID: UUID?
    ///Content of the note
    @objc dynamic var content: String?
    ///Date of the creation
    @objc dynamic var date: Date?
    
}
