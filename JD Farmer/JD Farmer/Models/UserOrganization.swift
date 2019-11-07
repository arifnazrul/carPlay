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
    @objc dynamic var ID_UserOrganization: UUID?
    ///Foreign key to User
    @objc dynamic var User_ID: UUID?
    ///Foreign key to Organization
    @objc dynamic var Organization_ID: UUID?
    
}
