/**
* \file JDSecretManager.h
* \brief Header file of the keychain interface. It offers a interface to access the keychain like a NSDictionary but
* just for strings.
*
*  Copyright (c) Deere & Company as an unpublished work
*  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
*  DEERE & COMPANY.  ALL USE, DISCLOSURE, AND/OR
*  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
*  DEERE & COMPANY IS PROHIBITED.
*/
#import <Foundation/Foundation.h>

extern NSString *_Nonnull const kKeychainAccessToken;
extern NSString *_Nonnull const kKeychainLastLoginUUIDToken;

/**
*  \brief The availability modes for a keychain item
*/
typedef NS_ENUM(NSInteger, JDSecretAvailabilityMode) {
    /**
    *  \brief The keychain item is accessible only if the device is unlocked
    */
    JDSecretAvailabilityModeWhenUnlockedThisDeviceOnly = 0,
    /**
    *  \brief The keychain item is accessible after the first unlock of the device
    */
    JDSecretAvailabilityModeAfterFirstUnlockThisDeviceOnly = 1,
    /**
    *  \brief The keychain item is always (in every device state) accessible
    */
    JDSecretAvailabilityModeAlwaysThisDeviceOnly = 2

};

/**
*  \brief The global sync state possibilities in the keychain
*/
typedef NS_ENUM(NSInteger, JDKeychainSyncState) {
    /**
    *  \brief No more data to sync
    */
    JDKeychainSyncStateEverythingInSync = 0,
    /**
    *  \brief The app contains data that has not been synchronized yet
    */
    JDKeychainSyncStateDataPendingForSync = 1
};

/**
* \class JDSecretManager
* \brief This class represents the interface to the internal iOS keychain.
*
* Its methods can be accessed in a static way. The keychain data is stored on the device only and can not be migrated to
* a new device. This class is ARC compatible.
*
* \note Currently only strings (key/value pairs) can be stored into the keychain via this interface.
*
* Example usage:
* \code
* BOOL result = [JDSecretManager purgeStringKeychainGroup:@"exampleGroup"];
* \endcode
*/
@interface JDSecretManager : NSObject

/**
 * This method initializes the apps bundle seed identifier.
 * It's recommended to call this method when the framework is initialized.
 *
 * @return YES when the initialization went well, NO otherwise.
 */
+ (BOOL)initializeBundleSeedIdentifier;

/**
*  \brief Delete all keys in the given keychain group
*
*  @param group The keychain group which contains the stored secrets
*
*  @return TRUE if all keys have been deleted successfully, FALSE otherwise
*/
+ (BOOL)purgeStringKeychainGroup:(nonnull NSString *)group;

/**
*  \brief Store or update a key in the keychain
*
*  The method checks first if a key already exists in the database. If it exists, it updates its value. Otherwise it
* will be created.
*
*  @param value        The value for the corresponding key
*  @param key          The key for the value
*  @param group        The group name for the key/value combination
*  @param availability The moment since it will be available
*
*  @return TRUE if the key has been added/updated successfully, FALSE otherwise
*/
+ (BOOL)storeStringInKeychain:(nonnull NSString *)value
                       andKey:(nonnull NSString *)key
                      inGroup:(nonnull NSString *)group
             withAvailability:(JDSecretAvailabilityMode)availability;

/**
*  \brief Delete a key from the keychain
*
*  @param key   The key for the value to delete
*  @param group The group name for the key/value combination
*
*  @return TRUE if the key has been deleted successfully, FALSE otherwise
*/
+ (BOOL)deleteStringWithKeyFromKeychain:(nonnull NSString *)key inGroup:(nonnull NSString *)group;

/**
*  \brief Returns a configured query dictionary for a specific identifier and group
*
*  This is needed to do an add/update/delete/lookup query on the keychain.
*  It is configured with:
*  - kSecClass == kSecClassGenericPassword
*  - kSecAttrAccount == identifier         (optional)
*  - kSecAttrAccessGroup == group          (optional; if target is not the iphone/ipad simulator)
*  - kSecAttrService == [JDSecretManager class] as string
*
*  @param identifier The "key" of the dictionary. Can be nil for search querys, it will then be ignored and not added to
* the dictionary.
*  @param group      The access group of the keychain. Will be ignored in simulator mode.
*
*  @return A configured query dictionary especially for strings in the keychain.
*/
+ (nonnull NSMutableDictionary *)stringQueryDictionaryForIdentifier:(nullable NSString *)identifier
                                                           andGroup:(nullable NSString *)group;

/**
*  \brief Validates if a given key/value pair is correct
*
*  @param value The value that should be checkt against the value stored in the keychain
*  @param key   The key of the value that should be checked
*  @param group The group name of the key/value combination
*
*  @return TRUE if the given key/value combination is valid, FALSE otherwise (or if the key doesn't exist)
*/
+ (BOOL)validateString:(nonnull NSString *)value withKey:(nonnull NSString *)key inGroup:(nonnull NSString *)group;

/**
*  \brief Retrieve a value for a given key from the keychain
*
*  @param key   The key to retrieve the value for
*  @param group The group name of the key/value combination
*
*  @return The value of the given key or nil in case the key has not been found in the keychain
*/
+ (nullable NSString *)stringFromKeychainByKey:(nonnull NSString *)key andGroup:(nonnull NSString *)group;

/**
*  \brief Set the global sync state of a app
*
*  @param appName The app name as a string
*  @param status  The sync status of the app
*/
+ (void)setSyncStatusforApp:(nonnull NSString *const)appName andSyncStatus:(JDKeychainSyncState)status;

/**
*  \brief Checks if every app has been fully synchronized with the backend
*
*  @return TRUE if every app has been fully synchronized with the backend, FALSE otherwise (or in error)
*/
+ (BOOL)isEveryAppInSync;

/**
*  \brief Checks if the user is logged in
*
*  @return TRUE if the user is logged in, FALSE otherwise
*/
+ (BOOL)isLoggedIn;

/**
*  \brief Removes the token from the keychain
*
*  @return TRUE remove successfully, FALSE otherwise
*/
+ (BOOL)removeLoginData;

@end

/** End of File Copyright ****************************************************
*
*  Copyright (c) Deere & Company as an unpublished work
*  THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF
*  DEERE & COMPANY.  ALL USE, DISCLOSURE, AND/OR
*  REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
*  DEERE & COMPANY IS PROHIBITED.
*
*****************************************************************************/