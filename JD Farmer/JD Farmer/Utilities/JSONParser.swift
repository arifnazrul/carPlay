/**
  - **Name**:         JsonParser.swift
  - Description: Function which reads a JSON File and it serializes as a NSDictionary
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      08.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/

import Foundation

/**
    It parses a JSON Input file into NSDictionary Object.
 
    - Parameters:
        - path: The path of the file
    - Returns: A NSDictionary Object containing JSON Data
        
 */
func parseJSON(path: String) -> NSDictionary
{
    return try! JSONSerialization.jsonObject(
        with: Data(contentsOf: URL(fileURLWithPath: path)),
        options: JSONSerialization.ReadingOptions.mutableContainers) as! NSDictionary
    
}
