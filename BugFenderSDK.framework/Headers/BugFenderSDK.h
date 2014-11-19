//
//  BugFenderSDK.h
//  BugFenderSDK
//  Copyright (c) 2014 Mobile Jazz SL. All rights reserved.
//

#import <Foundation/Foundation.h>

#define BFLibraryVersionNumber_0_1  0.1

/**
 * Current BugFender version number.
 * @discussion This value can be compared with the defined macros BFLibraryVersionNumber_X_Y.
 **/
FOUNDATION_EXPORT double const BFLibraryVersionNumber;

/**
 * Exception thrown when calling any BFLog method without having activated previously the BugFender.
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

#define BFLog2(level, tag, args, ...) ({\
    __BFLog(__LINE__,\
            [NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__],\
            [NSString stringWithFormat:@"%s",__FILE__],\
            level,\
            tag,\
            args,\
            ##__VA_ARGS__);\
    NSLog(args, ##__VA_ARGS__);\
})

#else

#define BFLog2(level, tag, args, ...) ({\
    __BFLog(__LINE__,\
            [NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__],\
            [NSString stringWithFormat:@"%s",__FILE__],\
            level,\
            tag,\
            args,\
            ##__VA_ARGS__);\
})

#endif

/**
 * Default remote logger interface for logging.
 * @param lineNumber The line number of the log.
 * @param method The method where the log has happened.
 * @param file The file where the log has happened.
 * @param level
 * @param tag
 * @param format
 * @discussion Do not use this method direclty. Instead, use the BFLog or BFLog2 macros.
 **/
FOUNDATION_EXPORT void __BFLog(NSInteger lineNumber, NSString *method, NSString *file, BFLogLevel level, NSString *tag, NSString *format, ...);

/**
 * Main RemoteLogger interface.
 **/
@interface BugFender : NSObject

/**
 * Activates the remote logger for an specific app.
 * @param appToken The app token of the remote logger.
 * @discussion This method needs to be called before any BFLog call, otherwise the `BFInvalidMethodCallException` exception will be thrown.
 **/
+ (void)activateLogger:(NSString*)appToken;

/**
 * Maximum space availalbe to store local logs. This value is represented in bytes. Default value is 5242880 (1024*1024*5 = 1MB).
 * @discussion If maximumLocalStroageSize is 0 (zero), then there is no limit and everything will be stored locally.
 **/
+ (NSUInteger)maximumLocalStroageSize;

/**
 * Set the maximum space availalbe to store local logs. This value is represented in bytes.
 * @discussion If maximumLocalStroageSize is 0 (zero), then there is no limit and everything will be stored locally.
 **/
+ (void)setMaximumLocalStroageSize:(NSUInteger)maximumLocalStroageSize;

/**
 * Returns the device identifier used to identify the curretn device in the Remote Logger environment.
 * @return
 **/
+ (NSString*)deviceIdentifier;

@end
