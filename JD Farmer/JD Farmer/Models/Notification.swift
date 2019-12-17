/**
  - **Name**:         Notification.swift
  - Description: This file contains Notification Model for Realm
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      07.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import Foundation
import RealmSwift

class Notification: Object {
    
    ///Primary key
    @objc dynamic var ID_Notification = UUID().uuidString
    ///Foreign key of the Field
    @objc dynamic var Field_ID = Field.primaryKey()
    ///Content of the notification
    @objc dynamic var content: String?
    ///Severity
    //TODO: Create an ENUM with severity types
    @objc dynamic var severity: String?
    ///Date of the creation
    @objc dynamic var dateCreated: Date?
    
    override static func primaryKey() -> String? {
        return "ID_Notification"
    }
    
}
