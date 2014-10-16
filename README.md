RemoteLoggerSDK for iOS
===================

RemoteLogger is a service that enables devices to log to remote servers. The main feature is that developers can control from the server side which devices must log and which devices must not log to the server.

In this repository you will find the RemoteLogger SDK to be used in iOS 6.0 or superior.

#Instalation

## Cocoa Pods
The easiest way to install RemoteLogger SDK for iOS is using CocoaPods.
```
pod 'RemoteLoggerSDK', :git => 'https://github.com/mobilejazz/RemoteLoggerSDK-iOS.git'
```
The repository is not yet available in CocoaPods main repository as it is still under development. 

## Manual
If you prefer to install manually the SDK, you need to download the files `libRemoteLoggerSDK.a` and `include/RemoteLoggerSDK/RemoteLoggerSDK.h` to your project and link the static library `libRemoteLoggerSDK.a` in your project configuration (*Project Settings > General > Linked Frameworks and Libraries*).

# Using the RemoteLogger SDK

## Configuring the RemoteLogger

First, in the **AppDelegate** method `application:didFinishLaunchingWithOptions:` you need to set the AppKey:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Activate the remote logger with an App Key.
    [RemoteLogger activateLogger:@"XCwWtq3uBX7hPLbe"];
   
    // Optionally, you can get the Device Idnetifier 
    NSString *remoteLoggerDeviceIdentifier = [RemoteLogger deviceIdentifier];
    
    return YES;
}
```

Optionally, you can get the device identifier used by the RemoteLogger in order to display it in the Settings bundle for example. This device identifeir wil be used to recognize the device in the RemoteLogger admin website.

## Writing Logs

To write logs, you must replace `NSLog`with one of the following methods:

- `RLog(...)`: Default log.
- `RLogWarn(...)`: Warning log.
- `RLogErr(...)`: Error log.

As shown above, there are 3 kind of log levels: `RLLogLevelDefault`, `RLLogLevelWarning`, `RLLogLevelError`.

Also, you can manually specify a tag o set of tags (string separated by comas) and a log level by using the following method:

- `RLog2(level, tag, ...)`: Where log level is one of the enums shown above, tag is an string containing tags separated by coma, and then the log itself.

### Example

```
- (void)foo
{
    RLog(@"Foo method started at time: %@", [[NSDate date] description]);
    
    RLogWarn(@"This is a warning with error code: %ld", 23);
    
    RLogError(@"This is an error with error code: %ld", 42);
    
    RLog2(RLLogLevelWarning, @"networking, error, TODO", @"This is a warning with some tags. Error code: %ld", (long)23);
}
```

## To know

By using the `RLog` methods remote logger will store locally all logs and then send them when possible to the server. Also, will add extra information as the date of the log, the file where the log happened, the number of line or the name of the method.
