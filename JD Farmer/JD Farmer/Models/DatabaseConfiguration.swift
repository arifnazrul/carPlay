//
//  DatabaseConfiguration.swift
//  JD Farmer
//
//  Created by capstone on 08.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation

class DatabaseConfiguration {
    private var data: NSDictionary
    
    init(path: String)
    {
        self.data = parseJSON(path: path)

        createUsers(usersArray: data.value(forKey: "User") as! NSArray)
        createOrganizations(organizationsArray: data.value(forKey: "Organization") as! NSArray)
        createUserOrganizations(userOrganizationsArray: data.value(forKey: "UserOrganization") as! NSArray)
        createFields(fieldsArray: data.value(forKey: "Field") as! NSArray)
        createVisits(visitsArray: data.value(forKey: "Visit") as! NSArray)
        createNotifications(notificationsArray: data.value(forKey: "Notification") as! NSArray)
        createNote(noteArray: data.value(forKey: "Note") as! NSArray)
    }
    
    private func createUsers(usersArray: NSArray)
    {
        var i = 0
        
        while i < usersArray.count {
            let user = User()
            user.ID_User = (usersArray.object(at: i) as AnyObject).value(forKey: "ID_User") as! String
            user.username = (usersArray.object(at: i) as AnyObject).value(forKey: "username") as? String
            user.password = (usersArray.object(at: i) as AnyObject).value(forKey: "password") as? String
            
            i += 1
            
            print(user)
        }
        
    }
    
    private func createOrganizations(organizationsArray: NSArray)
    {
        var i = 0
        
        while i < organizationsArray.count {
            
            let organization = Organization()
            organization.ID_Organization = (organizationsArray.object(at: i) as AnyObject).value(forKey: "ID_Organization") as! String
            organization.name = (organizationsArray.object(at: i) as AnyObject).value(forKey: "name") as? String
            organization.desc = (organizationsArray.object(at: i) as AnyObject).value(forKey: "desc") as? String
            
            i += 1
            
            print(organization)
        }
    }
    
    private func createUserOrganizations(userOrganizationsArray: NSArray)
    {
        var i = 0
        
        while i < userOrganizationsArray.count {
            
            let userOrganization = UserOrganization()
            userOrganization.ID_UserOrganization = (userOrganizationsArray.object(at: i) as AnyObject).value(forKey: "ID_UserOrganization") as! String
            userOrganization.Organization_ID = (userOrganizationsArray.object(at: i) as AnyObject).value(forKey: "Organization_ID") as? String
            userOrganization.User_ID = (userOrganizationsArray.object(at: i) as AnyObject).value(forKey: "User_ID") as? String
            
            i += 1
            
            print(userOrganization)
        }
    }
    
    private func createFields(fieldsArray: NSArray)
    {
        var i = 0
        
        while i < fieldsArray.count {
            
            let field = Field()
            field.ID_Field = (fieldsArray.object(at: i) as AnyObject).value(forKey: "ID_Field") as! String
            field.name = (fieldsArray.object(at: i) as AnyObject).value(forKey: "name") as? String
            field.Organization_ID = (fieldsArray.object(at: i) as AnyObject).value(forKey: "Organization_ID") as? String
            field.coordinates = (fieldsArray.object(at: i) as AnyObject).value(forKey: "coordinates") as? String

            i += 1
            
            print(field)
        }
    }
    
    private func createVisits(visitsArray: NSArray)
    {
        var i = 0
        
        while i < visitsArray.count {
            
            let visit = Visit()
            visit.ID_Visit = (visitsArray.object(at: i) as AnyObject).value(forKey: "ID_Visit") as! String
            visit.Field_ID = (visitsArray.object(at: i) as AnyObject).value(forKey: "Field_ID") as? String
            ///TODO: the date is null, investigate
            visit.lastVisit = (visitsArray.object(at: i) as AnyObject).value(forKey: "lastVisit") as? Date
            visit.User_ID = (visitsArray.object(at: i) as AnyObject).value(forKey: "User_ID") as? String

            i += 1
            
                print(visit)
        }
    }
    
    private func createNotifications(notificationsArray: NSArray)
    {
        var i = 0
        
        while i < notificationsArray.count {
            
            let notification = Notification()
            notification.ID_Notification = (notificationsArray.object(at: i) as AnyObject).value(forKey: "ID_Notification") as! String
            notification.content = (notificationsArray.object(at: i) as AnyObject).value(forKey: "content") as? String
            ///TODO: the date is null, investigate
            notification.dateCreated = (notificationsArray.object(at: i) as AnyObject).value(forKey: "dateCreated") as? Date
            notification.Field_ID = (notificationsArray.object(at: i) as AnyObject).value(forKey: "Field_ID") as? String
            notification.severity = (notificationsArray.object(at: i) as AnyObject).value(forKey: "severity") as? String

            i += 1
            
            print(notification)
        }
    }
    
    private func createNote(noteArray: NSArray)
    {
        var i = 0
        
        while i < noteArray.count {
            
            let note = Note()
            note.ID_Note = (noteArray.object(at: i) as AnyObject).value(forKey: "ID_Note") as! String
            note.content = (noteArray.object(at: i) as AnyObject).value(forKey: "content") as? String
            ///TODO: the date is null, investigate
            note.date = (noteArray.object(at: i) as AnyObject).value(forKey: "date") as? Date
            note.Field_ID = (noteArray.object(at: i) as AnyObject).value(forKey: "Field_ID") as? String

            i += 1
            
            print(note)
        }
    }

}
