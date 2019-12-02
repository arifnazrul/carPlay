//
//  User_Organization.swift
//  JD Farmer
//
//  Created by capstone on 07.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import RealmSwift

class UserOrganization: Object {
    
    ///Primary key
    @objc dynamic var ID_UserOrganization = UUID().uuidString
    ///Foreign key to User
    @objc dynamic var User_ID = User.primaryKey()
    ///Foreign key to Organization
    @objc dynamic var Organization_ID = Organization.primaryKey()
    
    override static func primaryKey() -> String? {
        return "ID_UserOrganization"
    }
    
}
