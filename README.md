# Carplay iOS
This branch is to handle the GeoLocation feature of the CarPlay application. It aims to cover the following functionalities:

Basic Map Functionality
1. Load the map - [x]
2. Show user's current location on the map - [x]
3. Update user's location on the map as his car moves - [x]
4. recenter the map on the user if the map is moved - [x]
5. Customized boundries of the farmer's fields marked on the map - [ ]
6. Navigate the user to the customized field boundry - [ ]
7. Area contained within field boundry to be colored if: - [ ]
        a. Red: user has unread critical notifications regarding that field
        b. Blue: 
        c. Yellow: 
        8. Set up flags within a customized field boundry to show notes created for that field, numbered as per the number of notes. - [ ]
9. the notes functionality (external to this functionality) be connected to this so user can create geo-tagged notes. - [ ]



Implementation Details:

**View** :
* main.storyboard is the map view with just the Map Kit View object set up. Constraints are applied within the safe area.

**Controller**: 
* View controller is, **as of now** the only controller of the application. It handles the following:
1. rendering the map
2. locating the user
3. updating user location
4. rendering the field boundries overlay

**Model**:
This is where the .plist file is fetched and read to extract the coordinates info to set up boundries or any sort of overlays. 

**Overlay**:

* FieldOverlay
This **as of now** only has an initializer function. It is a custom class that implements the MKOverlay protocol, which has two required properties: coordinate and boundingMapRect. These properties define where the overlay resides on the map and the overlay’s size.

* FieldOverlayView
Not used yet. 

**Coordinate Data**
A **dummy coordinates' file** with .pliost extension that has the coordinate values for fraunhofer's building. only the corner points are provided. 
