//
//  Notification.swift
//  JD Farmer
//
//  Created by capstone on 07.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import RealmSwift

class Notification: Object {
    
    ///Primary key
    @objc dynamic var ID_Notification: UUID?
    ///Foreign key of the Field
    @objc dynamic var Field_ID: UUID?
    ///Content of the notification
    @objc dynamic var content: String?
    ///Severity
    //TODO: Create an ENUM with severity types
    @objc dynamic var severity: String?
    ///Date of the creation
    @objc dynamic var dateCreated: Date?
    
}
