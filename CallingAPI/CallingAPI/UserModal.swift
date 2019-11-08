//
//  UserModal.swift
//  CallingAPI
//
//  Created by SHUBHAM AGARWAL on 20/10/18.
//  Copyright © 2018 SHUBHAM AGARWAL. All rights reserved.
//

import Foundation

struct Users: Codable {
    
    let userBody: String?
    let id: Int?
    
    enum CodingKeys: String, CodingKey {
        case userBody = "body"
        case id
    }
}
