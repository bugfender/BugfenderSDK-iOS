//
//  RemoteLoggerSDK.h
//  RemoteLoggerSDK
//  Copyright (c) 2014 Mobile Jazz SL. All rights reserved.
//

#import <Foundation/Foundation.h>

#define RLLibraryVersionNumber_0_1  0.1

/**
 * Current RemoteLogger version number. 
 * @discussion This value can be compared with the defined macros RLLibraryVersionNumber_X_Y.
 **/
FOUNDATION_EXPORT double const RLLibraryVersionNumber;

/**
 * Exception thrown when calling any RLog method without having activated previously the RemoteLogger.
 **/
extern NSString * const RLInvalidMethodCallException;

typedef NS_ENUM(NSUInteger, RLLogLevel)
{
    RLLogLevelDefault       = 0,
    RLLogLevelWarning       = 1,
    RLLogLevelError         = 2,
};

#define RLog(args, ...)     RLog2(RLLogLevelDefault, nil, args, ##__VA_ARGS__)
#define RLogWarn(args, ...) RLog2(RLLogLevelWarning, nil, args, ##__VA_ARGS__)
#define RLogErr(args, ...)  RLog2(RLLogLevelError, nil, args, ##__VA_ARGS__)

#if (DEBUG)

#define RLog2(level, tag, args, ...) ({\
    __RLLog(__LINE__,\
            [NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__],\
            [NSString stringWithFormat:@"%s",__FILE__],\
            level,\
            tag,\
            args,\
            ##__VA_ARGS__);\
    NSLog(args, ##__VA_ARGS__);\
})

#else

#define RLog2(level, tag, args, ...) ({\
    __RLLog(__LINE__,\
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
 * @discussion Do not use this method direclty. Instead, use the RLog or RLog2 macros.
 **/
FOUNDATION_EXPORT void __RLLog(NSInteger lineNumber, NSString *method, NSString *file, RLLogLevel level, NSString *tag, NSString *format, ...);

/**
 * Main RemoteLogger interface.
 **/
@interface RemoteLogger : NSObject

/**
 * Activates the remote logger for an specific app.
 * @param appToken The app token of the remote logger.
 * @discussion This method needs to be called before any RLog call, otherwise the `RLInvalidMethodCallException` exception will be thrown.
 **/
+ (void)activateLogger:(NSString*)appToken;


/**
 * Returns the device identifier used to identify the curretn device in the Remote Logger environment.
 * @return
 **/
+ (NSString*)deviceIdentifier;

@end
