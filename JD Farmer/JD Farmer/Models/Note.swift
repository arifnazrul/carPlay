/**
  - **Name**:         Note.swift
  - Description: This file contains Note Model for Realm
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      07.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/


import Foundation
import RealmSwift

class  Note: Object {
    
    ///Primary key
    @objc dynamic var ID_Note = UUID().uuidString
    ///Foreign key of the Field
    @objc dynamic var Field_ID = Field.primaryKey()
    ///Content of the note
    @objc dynamic var content: String?
    ///Date of the creation
    @objc dynamic var date: Date?
    
    override static func primaryKey() -> String? {
        return "ID_Note"
    }
    
}
