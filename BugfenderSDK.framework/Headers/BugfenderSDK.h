//
//  BugfenderSDK.h
//  BugfenderSDK
//  Copyright (c) 2014 Bugfender SL. All rights reserved.
//

#import <Foundation/Foundation.h>

#define BFLibraryVersionNumber_0_1_0  0
#define BFLibraryVersionNumber_0_2_0  1
#define BFLibraryVersionNumber_0_2_1  2
#define BFLibraryVersionNumber_0_3_0  3
#define BFLibraryVersionNumber_0_3_1  4
#define BFLibraryVersionNumber_0_3_2  5
#define BFLibraryVersionNumber_0_3_3  6

/**
 * Current Bugfender version number.
 * @discussion This value can be compared with the defined macros BFLibraryVersionNumber_X_Y_Z.
 **/
FOUNDATION_EXPORT double const BFLibraryVersionNumber;

/**
 * Exception thrown when calling any BFLog method without having activated previously the `Bugfender` interface.
 **/
extern NSString * const BFInvalidMethodCallException;

typedef NS_ENUM(NSUInteger, BFLogLevel)
{
    BFLogLevelDefault       = 0,
    BFLogLevelWarning       = 1,
    BFLogLevelError         = 2,
};

#define BFLog(args, ...)     BFLog2(BFLogLevelDefault, nil, args, ##__VA_ARGS__)
#define BFLogWarn(args, ...) BFLog2(BFLogLevelWarning, nil, args, ##__VA_ARGS__)
#define BFLogErr(args, ...)  BFLog2(BFLogLevelError, nil, args, ##__VA_ARGS__)

#if (DEBUG)

#define BFLog2(logLevel, tagName, args, ...) ({\
[Bugfender logLineNumber:__LINE__ \
                  method:[NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__] \
                    file:[NSString stringWithFormat:@"%s",__FILE__] \
                   level:logLevel \
                     tag:tagName \
                  format:args, ##__VA_ARGS__];\
    NSLog(args, ##__VA_ARGS__);\
})

#else

#define BFLog2(logLevel, tagName, args, ...) ({\
[Bugfender logLineNumber:__LINE__ \
                  method:[NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__] \
                    file:[NSString stringWithFormat:@"%s",__FILE__] \
                   level:logLevel \
                     tag:tagName \
                  format:args, ##__VA_ARGS__];\
})

#endif

/**
 * Default Bugfender interface for logging.
 * @param lineNumber The line number of the log.
 * @param method The method where the log has happened.
 * @param file The file where the log has happened.
 * @param level
 * @param tag
 * @param format
 * @discussion Do not use this method direclty. Instead, use the BFLog or BFLog2 macros.
 * @deprecated Will be removed by September 6th, 2015.
 **/
FOUNDATION_EXPORT void __BFLog(NSInteger lineNumber, NSString *method, NSString *file, BFLogLevel level, NSString *tag, NSString *format, ...);

/**
 * Main Bugfender interface.
 **/
@interface Bugfender : NSObject

/**
 * Activates the Bugfender for an specific app.
 * @param appToken The app token of the Bugfender application
 * @discussion This method needs to be called before any BFLog call, otherwise the `BFInvalidMethodCallException` exception will be thrown.
 **/
+ (void)activateLogger:(NSString*)appToken;

/**
 * Maximum space availalbe to store local logs. This value is represented in bytes. Default value is 5242880 (1024*1024*5 = 5MB).
 * @discussion If maximumLocalStorageSize is 0 (zero), then there is no limit and everything will be stored locally.
 **/
+ (NSUInteger)maximumLocalStorageSize;

/**
 * Set the maximum space availalbe to store local logs. This value is represented in bytes.
 * @discussion If maximumLocalStorageSize is 0 (zero), then there is no limit and everything will be stored locally (use at your own risk!).
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
 * Bugfender interface for logging, which takes a string format with parameters as log message.
 * @discussion This command can be called anytime, and will take effect the next time the device is online.
 * For efficiency, several log lines can be sent together to the server with some delay.
 * @param lineNumber The line number of the log.
 * @param method The method where the log has happened.
 * @param file The file where the log has happened.
 * @param level Log level.
 * @param tag Tag or tags to be applied to the log line.
 * @param format Format string, equivalent to NSLog's first parameter. Format is followed by a variable list of arguments, equivalent to NSLog's parameters after the format string.
 * @discussion Prefer to use the BFLog or BFLog2 macros in order to get file name and line number filled in automatically
 **/
+ (void) logLineNumber:(NSInteger)lineNumber method:(NSString*)method file:(NSString*)file level:(BFLogLevel)level tag:(NSString*)tag format:(NSString*)format, ...;

/**
 * Bugfender interface for logging, which takes a varargs.
 * @discussion This command can be called anytime, and will take effect the next time the device is online.
 * For efficiency, several log lines can be sent together to the server with some delay.
 * @param lineNumber The line number of the log.
 * @param method The method where the log has happened.
 * @param file The file where the log has happened.
 * @param level Log level.
 * @param tag Tag or tags to be applied to the log line.
 * @param format Format string, equivalent to NSLog's first parameter.
 * @param args Arguments to the format string, equivalent to NSLog's parameters after the format string.
 * @discussion Prefer to use the BFLog or BFLog2 macros in order to get file name and line number filled in automatically
 **/
+ (void) logLineNumber:(NSInteger)lineNumber method:(NSString*)method file:(NSString*)file level:(BFLogLevel)level tag:(NSString*)tag format:(NSString*)format args:(va_list)args;

/**
 * Bugfender interface for logging, which takes a simple string as log message.
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
+ (void) logLineNumber:(NSInteger)lineNumber method:(NSString*)method file:(NSString*)file level:(BFLogLevel)level tag:(NSString*)tag message:(NSString*)message;


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
 * Logs all actions performed in the application, such as button touches, swipes and gestures.
 */
+(void)enableUIEventLogging;

@end
