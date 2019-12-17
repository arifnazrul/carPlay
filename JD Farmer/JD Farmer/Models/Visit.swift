/**
  - **Name**:         Visit.swift
  - Description: This file contains Visit Model for Realm
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      07.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/


import Foundation
import RealmSwift

class Visit: Object {
    
    ///Primary key
    @objc dynamic var ID_Visit = UUID().uuidString
    ///Foreign key of the User
    @objc dynamic var User_ID = User.primaryKey()
    ///Foreign key of the Field
    @objc dynamic var Field_ID = Field.primaryKey()
    ///Date of the last visit
    @objc dynamic var lastVisit: Date?
    
    override static func primaryKey() -> String? {
        return "ID_Visit"
    }
}
