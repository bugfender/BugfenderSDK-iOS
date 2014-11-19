Bug Fender SDK for iOS
===================

Bug Fender is a service that enables devices to log to remote servers when needed. Developers can control from the server side which devices must send logs and which devices must not send logs to Bug Fender server. Later, you will be able to read all the received logs for each specific device.

In this repository you will find Bug Fender SDK for iOS 6.0 or greater.

#Instalation

## Cocoa Pods
The easiest way to install Bug Fender SDK for iOS is using CocoaPods.
```
pod 'BugFenderSDK', :git => 'https://github.com/mobilejazz/BugFenderSDK-iOS.git'
```
The repository is not yet available in CocoaPods main repository as it is still under development. 

## Manual Instalation
If you prefer to install manually the SDK, you need to download the file `BugFenderSDK.framework` and add the framework to your project. That simple.

# Using the Bug Fender SDK

## Configuring Bug Fender

First, in the **AppDelegate** method `application:didFinishLaunchingWithOptions:` you need to set the AppKey:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Activate the remote logger with an App Key.
    [BugFender activateLogger:@"XCwWtq3uBX7hPLbe"];
   
    // Optionally, you can get the Device Idnetifier 
    NSString *remoteLoggerDeviceIdentifier = [BugFender deviceIdentifier];
    
    return YES;
}
```

Optionally, you can get the device identifier used by the Bug Fender in order to display it in the Settings bundle for example. This device identifeir wil be used to recognize the device in the Bug Fender admin website.

## Writing Logs

To write logs, you must replace `NSLog`with one of the following methods:

- `BFLog(...)`: Default log.
- `BFLogWarn(...)`: Warning log.
- `BFLogErr(...)`: Error log.

As shown above, there are 3 kind of log levels: `BFLogLevelDefault`, `BFLogLevelWarning`, `BFLogLevelError`.

Also, you can manually specify a tag o set of tags (string separated by comas) and a log level by using the following method:

- `BFLog2(level, tag, ...)`: Where log level is one of the enums shown above, tag is an string containing tags separated by coma, and then the log itself.

### Example

```
- (void)foo
{
    BFLog(@"Foo method started at time: %@", [[NSDate date] description]);
    
    BFLogWarn(@"This is a warning with error code: %ld", 23);
    
    BFLogError(@"This is an error with error code: %ld", 42);
    
    BFLog2(RLLogLevelWarning, @"networking, error, TODO", @"This is a warning with some tags. Error code: %ld", (long)23);
}
```

## To know

By using the `BFLog` methods Bug Fender will store locally all logs and then send them when possible to the server. Also, will add extra information as the date of the log, the file where the log happened, the number of line or the name of the method.
