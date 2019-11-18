//
//  JDLogUtils.h
//  JDServices
//
//  Created by Bott Sebastian on 2015-09-21
//
//  Unpublished Work (c) 2015 Deere & Company.
//  All Worldwide Rights Reserved.
//  THIS MATERIAL IS THE PROPERTY OF DEERE & COMPANY.
//  ALL USE, ALTERATIONS, DISCLOSURE, DISSEMINATION
//  AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED
//  BY DEERE & COMPANY IS PROHIBITED.
//
//

#ifndef JDLOG_MUTE
// clang-format off
#define JDLogDebug(fmt, ...) [JDLogUtils logDebugWithMessage:[NSString stringWithFormat:@"%s line %d $ " fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] andLogToConsole:YES]
#define JDLogInfo(fmt, ...)  [JDLogUtils logInfoWithMessage:[NSString stringWithFormat:@"%s line %d $ " fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] andLogToConsole:YES]
#define JDLogWarn(fmt, ...)  [JDLogUtils logWarnWithMessage:[NSString stringWithFormat:@"%s line %d $ " fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] andLogToConsole:YES]
#define JDLogError(fmt, ...) [JDLogUtils logErrorWithMessage:[NSString stringWithFormat:@"%s line %d $ " fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__] andLogToConsole:YES]
// clang-format on
#else
#define JDLogDebug(...) /* */
#define JDLogInfo(...)  /* */
#define JDLogWarn(...)  /* */
#define JDLogError(...) /* */
#endif

/**
 * The log level.
 */
typedef NS_ENUM(NSInteger, JDLogLevel) {
    JDLogLevelMute = -1,
    JDLogLevelError = 0,
    JDLogLevelWarn = 1,
    JDLogLevelInfo = 2,
    JDLogLevelDebug = 3
};

/**
 * The log session.
 */
typedef NS_ENUM(NSUInteger, JDLogSession) { JDLogSessionCurrent = 0, JDLogSessionLast };

/**
 * The log path.
 */
typedef NS_ENUM(NSUInteger, JDDebugLogPath) { JDDebugLogPathCache = 0, JDDebugLogPathDocuments };


/**
 * @brief File logger with log levels.
 */
@interface JDLogUtils : NSObject

#pragma mark Initialization

/**
 * Sets the log level.
 * @param logLevel The log level
 */
+ (void)setLogLevel:(enum JDLogLevel)logLevel;

/**
 * Sets the log path.
 * @param logPath The path for the log files
 */
+ (void)setLogPath:(NSString *_Nonnull)logPath;

/**
 * Returns the log path.
 * @return The path to the log files
 */
+ (NSString *_Nonnull)logPath;

/**
 * Sets the state of HTTP payload logging. A separate file will be created.
 * @param httpLogEnabled <code>YES</code> enables the HTTP logging, <code>NO</code> turns it off
 */
+ (void)setHTTPLogEnabled:(BOOL)httpLogEnabled;

/**
 * Returns the state of the HTTP payload logging.
 * @return <code>YES</code> if HTTP logging is enabled, otherwise <code>NO</code>
 */
+ (BOOL)HTTPLogEnabled;

#pragma mark Logging

/**
 * Logs a specific message.
 * @param message The message
 * @param shouldLogToConsole If <code>YES</code> the message will be logged with NSLog
 */
+ (void)logDebugWithMessage:(NSString *_Nullable)message andLogToConsole:(BOOL)shouldLogToConsole;

/**
 * Logs a specific message.
 * @param message The message
 * @param shouldLogToConsole If <code>YES</code> the message will be logged with NSLog
 */
+ (void)logInfoWithMessage:(NSString *_Nullable)message andLogToConsole:(BOOL)shouldLogToConsole;

/**
 * Logs a specific message.
 * @param message The message
 */
+ (void)logWarnWithMessage:(NSString *_Nullable)message andLogToConsole:(BOOL)shouldLogToConsole;

/**
 * Logs a specific message.
 * @param message The message
 * @param shouldLogToConsole If <code>YES</code> the message will be logged with NSLog
 */
+ (void)logErrorWithMessage:(NSString *_Nullable)message andLogToConsole:(BOOL)shouldLogToConsole;

/**
 * Logs a specific message.
 * @param message The message.
 * @param fileName The file name.
 * @param shouldLogToConsole If <code>YES</code> the message will be logged with NSLog
 */
+ (void)logMessage:(NSString *_Nullable)message
    toFileWithName:(NSString *_Nonnull)fileName
   andLogToConsole:(BOOL)shouldLogToConsole;

/**
 * Logs a specific request message.
 *
 * @param message The message.
 * @param shouldLogToConsole If <code>YES</code>, the message will be logged with NSLog.
 */
+ (void)logRequestMessage:(NSString *_Nullable)message andLogToConsole:(BOOL)shouldLogToConsole;

#pragma mark Files

/**
 * Resets the log of the current session and preserves
 * the log of the last session.
 */
+ (void)resetLogFile;

/**
 * Resets the log of the current session and preserves
 * the log of the last session.
 */
+ (void)deleteLogFileWithName:(NSString *_Nonnull)fileName;

/**
 * Removes all files from the current log path.
 */
+ (void)clearAllFilesFromCurrentLogDirectory;

/**
 * Returns the log file as string.
 * @param logSession The log session
 * @return The log file as string
 */
+ (NSString *_Nullable)logFileStringForSession:(enum JDLogSession)logSession;

/**
 * Returns the log file as string.
 * @param fileName The log file name
 * @return The log file as string
 */
+ (NSString *_Nullable)logFileStringForFileName:(NSString *_Nonnull)fileName;

#pragma mark Deprecated

/**
* @deprecated
*/
+ (NSData *_Nullable)getLogFileDataForSession:(enum JDLogSession)logSession;

@end
