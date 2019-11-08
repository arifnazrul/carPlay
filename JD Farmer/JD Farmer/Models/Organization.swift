//
//  Organization.swift
//  JD Farmer
//
//  Created by capstone on 07.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import RealmSwift

class Organization: Object {
    
    ///Primary key
    @objc dynamic var ID_Organization = UUID().uuidString
    ///Name of the organization
    @objc dynamic var name: String?
    ///Description
    @objc dynamic var desc: String?
    
    override static func primaryKey() -> String? {
        return "ID_Organization"
    }
    
}
