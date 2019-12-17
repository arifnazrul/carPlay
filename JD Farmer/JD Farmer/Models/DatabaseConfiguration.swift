/**
  - **Name**:         DatabaseConfiguration.swift
  - Description: This file contains methods which parse .json file with database relations and convert them into objects which can be written into Realm
 
  - Author:    Ajdari, Arian [arianajdari94@gmail.com]
  - Date:      08.11.19
  - Copyright: 2019 JD Driver. All rights reserved ©
*/


import Foundation
import RealmSwift

class DatabaseConfiguration {
    private var data: NSDictionary
    
    /**
       DatabaseConfiguration ctor method. It parses a .json file and it returns each relation as NSArray
    
       - Parameters:
           - path: The path of the file
       - Returns: void
    */
    init(path: String)
    {
        self.data = parseJSON(path: path)

        let users             = createUsers(usersArray: data.value(forKey: "User") as! NSArray)
        let organizations     = createOrganizations(organizationsArray: data.value(forKey: "Organization") as! NSArray)
        let userOrganizations = createUserOrganizations(userOrganizationsArray: data.value(forKey: "UserOrganization") as! NSArray)
        let fields            = createFields(fieldsArray: data.value(forKey: "Field") as! NSArray)
        let visits            = createVisits(visitsArray: data.value(forKey: "Visit") as! NSArray)
        let notifications     = createNotifications(notificationsArray: data.value(forKey: "Notification") as! NSArray)
        let notes             = createNote(noteArray: data.value(forKey: "Note") as! NSArray)
        
        let realmPath = Bundle.main.url(forResource: "test", withExtension: "realm")
        print(realmPath)
        let config = Realm.Configuration(fileURL: realmPath)
        let realm = try! Realm(configuration: config)
        
       try! realm.write {
            realm.deleteAll()
            realm.add(users)
            realm.add(organizations)
            realm.add(userOrganizations)
            realm.add(fields)
            realm.add(visits)
            realm.add(notifications)
            realm.add(notes)
        }
        
    }
    
    /**
       This method iterates through every User and it places them into a Array
    
       - Parameters:
           - userArray: Contains all users
       - Returns: User array that can be written into Realm
    */
    private func createUsers(usersArray: NSArray) -> [User] {
        
        var i = 0
        var users = [User]()
        
        while i < usersArray.count {
            let user = User()
            user.ID_User = (usersArray.object(at: i) as AnyObject).value(forKey: "ID_User") as! String
            user.username = (usersArray.object(at: i) as AnyObject).value(forKey: "username") as? String
            user.password = (usersArray.object(at: i) as AnyObject).value(forKey: "password") as? String
            
            i += 1
            
            users.append(user)
        }
        return users
    }
    
    /**
       This method iterates through every Organization and it places them into a Array
    
       - Parameters:
           - organizationsArray: Contains all organizations
       - Returns: Organization array that can be written into Realm
    */
    private func createOrganizations(organizationsArray: NSArray) -> [Organization]
    {
        var i = 0
        var organizations = [Organization]()
        while i < organizationsArray.count {
            
            let organization = Organization()
            organization.ID_Organization = (organizationsArray.object(at: i) as AnyObject).value(forKey: "ID_Organization") as! String
            organization.name = (organizationsArray.object(at: i) as AnyObject).value(forKey: "name") as? String
            organization.desc = (organizationsArray.object(at: i) as AnyObject).value(forKey: "desc") as? String
            
            i += 1
            
            organizations.append(organization)
        }
        
        return organizations
    }
    
    /**
       This method iterates through every UserOrganization and it places them into a Array
    
       - Parameters:
           - userOrganizationArray: Contains all userOrganizations
       - Returns: User array that can be written into Realm
    */
    private func createUserOrganizations(userOrganizationsArray: NSArray) -> [UserOrganization]    {
        var i = 0
        var userOrganizations = [UserOrganization]()
        while i < userOrganizationsArray.count {
            
            let userOrganization = UserOrganization()
            userOrganization.ID_UserOrganization = (userOrganizationsArray.object(at: i) as AnyObject).value(forKey: "ID_UserOrganization") as! String
            userOrganization.Organization_ID = (userOrganizationsArray.object(at: i) as AnyObject).value(forKey: "Organization_ID") as? String
            userOrganization.User_ID = (userOrganizationsArray.object(at: i) as AnyObject).value(forKey: "User_ID") as? String
            
            i += 1
            
            userOrganizations.append(userOrganization)
        }
        
        return userOrganizations
    }
    
    /**
       This method iterates through every Field and it places them into a Array
    
       - Parameters:
           - fieldArray: Contains all fields
       - Returns: Field array that can be written into Realm
    */
    private func createFields(fieldsArray: NSArray) -> [Field]    {
        var i = 0
        var fields = [Field]()
        while i < fieldsArray.count {
            
            let field = Field()
            field.ID_Field = (fieldsArray.object(at: i) as AnyObject).value(forKey: "ID_Field") as! String
            field.name = (fieldsArray.object(at: i) as AnyObject).value(forKey: "name") as? String
            field.Organization_ID = (fieldsArray.object(at: i) as AnyObject).value(forKey: "Organization_ID") as? String
            field.coordinates = (fieldsArray.object(at: i) as AnyObject).value(forKey: "coordinates") as? String

            i += 1
            
            fields.append(field)
        }
        
        return fields
    }
    
    /**
       This method iterates through every Visit and it places them into a Array
    
       - Parameters:
           - visitArray: Contains all visits
       - Returns: Visit array that can be written into Realm
    */
    private func createVisits(visitsArray: NSArray) -> [Visit]    {
        var i = 0
        var visits = [Visit]()
        while i < visitsArray.count {
            
            let visit = Visit()
            visit.ID_Visit = (visitsArray.object(at: i) as AnyObject).value(forKey: "ID_Visit") as! String
            visit.Field_ID = (visitsArray.object(at: i) as AnyObject).value(forKey: "Field_ID") as? String
            visit.lastVisit = stringToDate(date: (visitsArray.object(at: i) as AnyObject).value(forKey: "lastVisit") as! String)
            visit.User_ID = (visitsArray.object(at: i) as AnyObject).value(forKey: "User_ID") as? String

            i += 1
            
            visits.append(visit)
        }
        
        return visits
    }
    
    /**
       This method iterates through every Notification and it places them into a Array
    
       - Parameters:
           - notificationArray: Contains all notifications
       - Returns: Notification array that can be written into Realm
    */
    private func createNotifications(notificationsArray: NSArray) -> [Notification]    {
        var i = 0
        var notifications = [Notification]()
        while i < notificationsArray.count {
            
            let notification = Notification()
            notification.ID_Notification = (notificationsArray.object(at: i) as AnyObject).value(forKey: "ID_Notification") as! String
            notification.content = (notificationsArray.object(at: i) as AnyObject).value(forKey: "content") as? String
            ///TODO: the date is null, investigate
            notification.dateCreated = stringToDate(date: (notificationsArray.object(at: i) as AnyObject).value(forKey: "dateCreated") as! String)
           
            notification.Field_ID = (notificationsArray.object(at: i) as AnyObject).value(forKey: "Field_ID") as? String
            notification.severity = (notificationsArray.object(at: i) as AnyObject).value(forKey: "severity") as? String

            i += 1
            
            notifications.append(notification)
        }
        
        return notifications
    }
    
    /**
       This method iterates through every Note and it places them into a Array
    
       - Parameters:
           - noteArray: Contains all notes
       - Returns: Note array that can be written into Realm
    */
    private func createNote(noteArray: NSArray) -> [Note]
    {
        var i = 0
        var notes = [Note]()
        while i < noteArray.count {
            
            let note = Note()
            note.ID_Note = (noteArray.object(at: i) as AnyObject).value(forKey: "ID_Note") as! String
            note.content = (noteArray.object(at: i) as AnyObject).value(forKey: "content") as? String
            note.date = stringToDate(date: (noteArray.object(at: i) as AnyObject).value(forKey: "date") as! String)
            note.Field_ID = (noteArray.object(at: i) as AnyObject).value(forKey: "Field_ID") as? String

            i += 1
           
            notes.append(note)
            
           
           
        }
        
        return notes
    }
    
    /**
       This method converts a string date to a Date
    
       - Parameters:
           - date: String containing the date
       - Returns: Date
    */
    private func stringToDate(date: String) -> Date {
        let dateFormater = DateFormatter()
       
        dateFormater.dateFormat = "yyyy-MM-dd'T'H:m:ss.SSSZ"
        dateFormater.locale = Locale(identifier: "en_US_POSIX")
        
        return dateFormater.date(from: date)!
    }

}
