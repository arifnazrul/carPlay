/**
  - **Name**:         User.swift
  - Description: This file contains User Model for Realm
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      07.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import Foundation
import RealmSwift

class User: Object {
    
    ///Primary key
    @objc dynamic var ID_User = UUID().uuidString
    ///Username
    @objc dynamic var username: String?
    ///Password
    ///TODO - Implement some encription, BCrypt
    @objc dynamic var password: String?
    
    override static func primaryKey() -> String? {
        return "ID_User"
    }
    
}
