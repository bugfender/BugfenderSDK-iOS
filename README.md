Bugfender SDK for iOS [![Build Status](https://travis-ci.org/bugfender/BugfenderSDK-iOS-swift-sample.svg)](https://travis-ci.org/bugfender/BugfenderSDK-iOS-swift-sample) [![Available in CocoaPods](https://img.shields.io/cocoapods/v/BugfenderSDK.svg)](https://cocoapods.org/pods/BugfenderSDK) [![CocoaDocs](https://img.shields.io/badge/docs-%E2%9C%93-blue.svg)](http://cocoadocs.org/docsets/BugfenderSDK/) 
===================

Bugfender is a cloud service to collect mobile application logs. Developers can control log sending programmatically and manually for each device. Logs are available at the [Bugfender console](https://app.bugfender.com/). You'll need a free account.

BugfenderSDK works for iOS 6.0 and better.

# Getting started

## 1. Install the SDK

If using CocoaPods:

```ruby
pod 'BugfenderSDK', '~> 0.3'
```

If you prefer to install the SDK manually, drag `BugfenderSDK.framework` into your project and [add -ObjC to your linker flags](https://developer.apple.com/library/mac/qa/qa1490/_index.html). Make sure you are linking `SystemConfiguration.framework` and `MobileCoreServices.framework` as well in Build Phases > Link Binary With Libraries.

Make Bugfender available project-wide by adding the following line to the `.pch` file:

```objective-c
#import <BugfenderSDK/BugfenderSDK.h>
```

Get an API key from the [Bugfender console](https://app.bugfender.com/). In your `AppDelegate` call [activateLogger](http://cocoadocs.org/docsets/BugfenderSDK/0.3.5/Classes/Bugfender.html#//api/name/activateLogger:) when the application starts, like this:

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    ...
    // Activate the remote logger with an App Key.
    [Bugfender enableAllWithToken:@"YOUR_API_KEY"];
    ...
}
```

## 2. Send logs

That's it! You don't have to do anything. Anything you write to `NSLog` will be received by Bugfender, plus user interactions will be logged automatically.

You may also want to specify a logging level by using the following macros:

- `BFLog(...)`: Default log.
- `BFLogWarn(...)`: Warning log.
- `BFLogErr(...)`: Error log.

# Advanced features

In some special circumstances you may want to send logs, regardless of the enabled state of the device in the Bugfender console, for example in a custom exception handler. Use `forceSendOnce` to force sending the logs once, and use `setForceEnabled:` to force it for some period of time.

You can get the Bugfender device identifier to show in your UI or send to your server:

```objective-c
NSString *bugFenderDeviceIdentifier = [Bugfender deviceIdentifier];
```

To help your users find the device identifier, one easy way to do it is adding it to the app's user defaults, so it shows up in the app's section inside the device Settings.

```objective-c
// Displaying the device identifier in the app's settings.
[[NSUserDefaults standardUserDefaults] setObject:[Bugfender deviceIdentifier] forKey:@"bugfenderDeviceIDKey"];
[[NSUserDefaults standardUserDefaults] synchronize];
```

Bugfender keeps up to 5 MB worth of log data in the device. This way Bugfender can work offline, and you can get some log data from the past when enabling a device. You can change that limit with `setMaximumLocalStorageSize`.

```objective-c
// Setting maximum cache size to 1 Mb
[Bugfender setMaximumLocalStorageSize:1024*1024];
```

## Advanced logging

When compiling in DEBUG, Bugfender will also print messages to the console. Bugfender won't output anything on the console in release mode.

Besides the logging level you can manually specify a tag o set of tags (string separated by comas) and a log level by using the following method:

- `BFLog2(level, tag, ...)`: Where log level is one of the enums shown above, tag is an string containing tags separated by coma, and then the log itself.

Use like this:

```objective-c
- (void)foo
{
    // Default log
    BFLog(@"Foo method started at time: %@", [[NSDate date] description]);
    
    // Warning log
    BFLogWarn(@"This is a warning with error code: %ld", 23);
    
    // Error log
    BFLogErr(@"This is an error with error code: %ld", 42);
    
    // Custom log, specifiying level, tags, and the text
    BFLog2(BFLogLevelWarning, @"networking, error", @"This is a warning with some tags. Error code: %ld", (long)23);
}
```

# Swift

Bugfender works well with Swift. Just follow the previous instructions, plus add the following line to your Bridging Header:

```objective-c
#import <BugfenderSDK/BugfenderSDK.h>
```

Use `Bugfender.LogLineNumber` method to log, or write a helper function similar to `println`:

```swift
func BFLog(message: String, filename: String = __FILE__, line: Int = __LINE__, funcname: String = __FUNCTION__) {
    Bugfender.logLineNumber(line, method: funcname, file: filename.lastPathComponent, level: BFLogLevel.Default, tag: nil, message: message)
    #if DEBUG
        NSLog("[\(filename.lastPathComponent):\(line)] \(funcname) - %@", message)
    #endif
}
```

Use like this:
```swift
func sliderChanged(slider: UISlider) {
    BFLog("Slider Value: \(slider.value)");
}
```

Check out the full documentation at [CocoaDocs](http://cocoadocs.org/docsets/BugfenderSDK/).
