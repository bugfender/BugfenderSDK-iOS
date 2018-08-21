//
//  BugfenderSDK.h
//  BugfenderSDK
//  Copyright (c) 2014 Bugfender SL. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

#define BFLibraryVersionNumber_0_1_0  0
#define BFLibraryVersionNumber_0_2_0  1
#define BFLibraryVersionNumber_0_2_1  2
#define BFLibraryVersionNumber_0_3_0  3
#define BFLibraryVersionNumber_0_3_1  4
#define BFLibraryVersionNumber_0_3_2  5
#define BFLibraryVersionNumber_0_3_3  6
#define BFLibraryVersionNumber_0_3_4  7
#define BFLibraryVersionNumber_0_3_5  8
#define BFLibraryVersionNumber_0_3_6  9
#define BFLibraryVersionNumber_0_3_7  10
#define BFLibraryVersionNumber_0_3_8  11
#define BFLibraryVersionNumber_0_3_9  12
#define BFLibraryVersionNumber_0_3_10  13
#define BFLibraryVersionNumber_0_3_11  14
#define BFLibraryVersionNumber_0_3_12  15
#define BFLibraryVersionNumber_0_3_13  16
#define BFLibraryVersionNumber_0_3_14  17
#define BFLibraryVersionNumber_0_3_15  18
#define BFLibraryVersionNumber_0_3_16  19
#define BFLibraryVersionNumber_0_3_17  20
#define BFLibraryVersionNumber_0_3_18  21
#define BFLibraryVersionNumber_0_3_19  22
#define BFLibraryVersionNumber_0_3_20  23
#define BFLibraryVersionNumber_0_3_21  24
#define BFLibraryVersionNumber_0_3_22  25
#define BFLibraryVersionNumber_0_3_23  26
#define BFLibraryVersionNumber_0_3_24  27
#define BFLibraryVersionNumber_0_3_25  28
#define BFLibraryVersionNumber_0_3_26  29
#define BFLibraryVersionNumber_0_3_27  30
#define BFLibraryVersionNumber_1_4_0  31
#define BFLibraryVersionNumber_1_4_1  32
#define BFLibraryVersionNumber_1_4_2  33
#define BFLibraryVersionNumber_1_4_3  34
#define BFLibraryVersionNumber_1_4_4  34 // Mistake: We released the version without incrementing the number.
#define BFLibraryVersionNumber_1_4_5  36
#define BFLibraryVersionNumber_1_4_6  37
#define BFLibraryVersionNumber_1_4_7  38
#define BFLibraryVersionNumber_1_4_8  39
#define BFLibraryVersionNumber_1_4_9  40
#define BFLibraryVersionNumber_1_4_10 41
#define BFLibraryVersionNumber_1_5_0  42
#define BFLibraryVersionNumber_1_5_1  43
#define BFLibraryVersionNumber_1_5_2  44
#define BFLibraryVersionNumber_1_5_3  45
#define BFLibraryVersionNumber_1_5_4  46
#define BFLibraryVersionNumber_1_5_5  47
#define BFLibraryVersionNumber_1_5_6  48

/**
 * Current Bugfender version number.
 * @discussion This value can be compared with the defined macros BFLibraryVersionNumber_X_Y_Z.
 **/
FOUNDATION_EXPORT double const BFLibraryVersionNumber;

/** Defines the level of a log */
typedef NS_ENUM(NSUInteger, BFLogLevel)
{
    /** Default/info log level */
    BFLogLevelDefault       = 0,
    /** Warning log level */
    BFLogLevelWarning       = 1,
    /** Error log level */
    BFLogLevelError         = 2,
};

#define BFLog(args, ...)     BFLog2(BFLogLevelDefault, nil, args, ##__VA_ARGS__)
#define BFLogWarn(args, ...) BFLog2(BFLogLevelWarning, nil, args, ##__VA_ARGS__)
#define BFLogErr(args, ...)  BFLog2(BFLogLevelError, nil, args, ##__VA_ARGS__)

#define BFLog2(logLevel, tagName, fmt, ...) \
[Bugfender logWithLineNumber:__LINE__ method:[NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__] file:[[NSString stringWithFormat:@"%s",__FILE__] lastPathComponent] level:logLevel tag:tagName message:fmt == nil ? @"" : [NSString stringWithFormat:fmt, ##__VA_ARGS__]]

/**
 * Main Bugfender interface.
 **/
@interface Bugfender : NSObject

/** ******************************************************************** **
 * @name Configuration
 ** ******************************************************************** **/

/**
 * Sets the URL of the API
 * @discussion Usage of this function is not necessary in the general use case. Please use exclusively when
 * directed from technical support. This method must be called before activateLogger.
 * @param url URL of the API to use
 */
+ (void)setApiURL:(NSURL*)url;

/**
 * Activates the Bugfender for a specific app.
 * @param appKey The app key of the Bugfender application, get it in bugfender.com
 * @throws `NSInvalidArgumentException` if Bugfender has already been initialized with a different app key.
 * @discussion This method needs to be called before any `BFLog` call, otherwise they will be ignored.
 **/
+ (void)activateLogger:(NSString*)appKey;

/**
 * Returns the app key.
 * @returns The app key, or nil if Bugfender has not been initialized.
 **/
+ (nullable NSString*)appKey;

/**
 * Maximum space availalbe to store local logs. This value is represented in bytes. Default value is 5242880 (1024*1024*5 = 5MB).
 * @discussion If maximumLocalStorageSize is 0 (zero), then there is no limit and everything will be stored locally.
 **/
+ (NSUInteger)maximumLocalStorageSize;

/**
 * Set the maximum space availalbe to store local logs. This value is represented in bytes. There's a limit of 50 MB.
 * @param maximumLocalStorageSize Maximum space availalbe to store local logs, in bytes.
 **/
+ (void)setMaximumLocalStorageSize:(NSUInteger)maximumLocalStorageSize;

/**
 * Returns the device identifier used to identify the current device in the Bugfender website.
 * @discussion This string can not be changed, but can be shown to the user or sent to your server, in order to
 * keep a relationship between a Bugfender device and a user or some other important event in your application.
 * 
 * The device identifier is constant while the application is installed in the device.
 * @return A string identifying the device.
 **/
+ (NSString*)deviceIdentifier;

/**
 *
 * The session identifier is constant while the application is running.
 * @return A string identifying the current session.
 */
+ (NSString *)sessionIdentifier;

/**
 * Synchronizes all logs with the server all the time, regardless if this device is enabled or not.
 * @discussion This method is useful when the logs should be sent to the server
 * regardless if the device is enabled in the Bugfender Console.
 *
 * Logs are synchronized continuously while forceEnabled is active.
 *
 * This command can be called anytime, and will take effect the next time the device is online.
 * @param enabled Whether logs should be sent regardless of the Bugfender Console settings.
 */
+(void) setForceEnabled:(BOOL)enabled;

/**
 * Gets the status of forceEnabled.
 * @discussion See setForceEnabled:.
 */
+(BOOL) forceEnabled;

/**
 * Prints messages to console for debugging purposes.
 * @param enabled Whether printing to console is enabled or not. By default it is enabled.
 */
+(void) setPrintToConsole:(BOOL)enabled;

/**
 * Gets the status of printToConsole. printToConsole prints messages to console. By default it is enabled.
 */
+(BOOL) printToConsole;

#if TARGET_OS_IOS
/**
 * Logs all actions performed and screen changes in the application, such as button touches, swipes and gestures.
 */
+(void)enableUIEventLogging;
#endif

/**
 * Enable crash reporting tool functionality.
 */
+(void)enableCrashReporting;

/** ******************************************************************** **
 * @name Device details
 ** ******************************************************************** **/

/**
 * Sets a device detail with boolean type.
 * @discussion Similarly to an NSDictionary, where you can set key-value pairs
 * related to a Bugfender device.
 * @param b A boolean value.
 * @param key Key.
 */
+(void)setDeviceBOOL:(BOOL)b forKey:(NSString*)key;
/**
 * Sets a device detail with string type.
 * @discussion Similarly to an NSDictionary, where you can set key-value pairs
 * related to a Bugfender device.
 * @param s A string value. The maximum length allowed is 192 bytes.
 * @param key Key.
 */
+(void)setDeviceString:(NSString*)s forKey:(NSString*)key;
/**
 * Sets a device detail with integer type.
 * @discussion Similarly to an NSDictionary, where you can set key-value pairs
 * related to a Bugfender device.
 * @param i An UInt64 value.
 * @param key Key.
 */
+(void)setDeviceInteger:(UInt64)i forKey:(NSString*)key;
/**
 * Sets a device detail with double type.
 * @discussion Similarly to an NSDictionary, where you can set key-value pairs
 * related to a Bugfender device.
 * @param d A double value.
 * @param key Key.
 */
+(void)setDeviceDouble:(double)d forKey:(NSString*)key;
/**
 * Removes a device detail.
 * @discussion Similarly to an NSDictionary, where you can remove an existent key-value pair
 * related to a Bugfender device by indicating its key.
 * @param key Key.
 */
+(void)removeDeviceKey:(NSString*)key;

/** ******************************************************************** **
 * @name Logging
 ** ******************************************************************** **/

/**
 * Bugfender extended interface for logging, which takes a simple string as log message.
 * @discussion This command can be called anytime, and will take effect the next time the device is online.
 * For efficiency, several log lines can be sent together to the server with some delay.
 * @param lineNumber The line number of the log.
 * @param method The method where the log has happened.
 * @param file The file where the log has happened.
 * @param level Log level.
 * @param tag Tag or tags to be applied to the log line.
 * @param message Message to be logged. The message will be logged verbatim, no interpretation will be performed.
 * @discussion Prefer to use the BFLog or BFLog2 macros in order to get file name and line number filled in automatically
 **/
+ (void) logWithLineNumber:(NSInteger)lineNumber method:(NSString*)method file:(NSString*)file level:(BFLogLevel)level tag:(nullable NSString*)tag message:(NSString*)message NS_SWIFT_NAME(log(lineNumber:method:file:level:tag:message:));

/** ******************************************************************** **
 * @name Commands
 ** ******************************************************************** **/

/**
 * Synchronizes all logs with the server once, regardless if this device is enabled or not.
 * @discussion This method is useful when an error condition is detected and the logs should be sent to
 * the server for analysis, regardless if the device is enabled in the Bugfender Console.
 *
 * Logs are synchronized only once. After that, the logs are again sent according to the enabled flag
 * in the Bugfender Console.
 * 
 * This command can be called anytime, and will take effect the next time the device is online.
 */
+ (void) forceSendOnce;

/**
 * Sends an issue
 * @discussion Sending an issue forces the logs of the current session being sent
 * to the server, and marks the session so that it is highlighted in the web console.
 * @param title Short description of the issue.
 * @param text Full details of the issue. Markdown format is accepted.
 * @return the issue identifier
 */
+ (NSString *)sendIssueWithTitle:(NSString *)title text:(NSString *)text;

@end
NS_ASSUME_NONNULL_END
