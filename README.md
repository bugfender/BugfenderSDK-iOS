Bugfender SDK for iOS
===================

Bugfender is a service that enables devices to log to remote servers when needed. Developers can control from the server side which devices must send logs and which devices must not send logs to Bugfender server. Later, you will be able to read all the received logs for each specific device. Also, Bugfender will store extra information as the date of the log, the file where the log happened, the number of line or the name of the method.

In this repository you will find Bugfender SDK for iOS 6.0 or greater.

#Installing Bugfender

## Using Cocoa Pods
The easiest way to install Bugfender SDK for iOS in your project is using CocoaPods. Add the following line to your `Podfile` or create one:
```ruby
pod 'BugfenderSDK', :git => 'https://github.com/bugfender/BugfenderSDK-iOS.git', :tag => '0.3.3'
```
Then run `pod install`.

The repository is not yet available in CocoaPods main repository as is under development. 

## Manually
If you prefer to install manually the SDK, you need to download the file `BugfenderSDK.framework` and add the framework to your project. That simple.

# Using the Bugfender SDK

## Configuring Bugfender

### 1. Setting the App Key
First, import the `BugfenderSDK.h` file somewhere (you can add it to your `pch` file to have the functions available in the whole projct) in your project. If using Swift, add the following line to your Bridging Header:

```objective-c
#import <BugfenderSDK/BugfenderSDK.h>
```

Then in the **AppDelegate** method `application:didFinishLaunchingWithOptions:` you need to set the AppKey and you are done:

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Activate the remote logger with an App Key.
    [Bugfender activateLogger:@"YOUR_API_KEY"];
    
    return YES;
}
```
```swift
func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
    // Activate the remote logger with an App Key.
	Bugfender.activateLogger("YOUR_API_KEY")

	return true
}
```
Now you can start logging using `BFLog` function.

### 2. Retriving the device identifier
You can get the device identifier used by the Bugfender used to recognize the device itself in the Bugfender admin website. Typically, you could show this identifier in the Settings bundle or your custom settings screen for example.

```objective-c
// Get the device identifier
NSString *bugFenderDeviceIdentifier = [Bugfender deviceIdentifier];
```

To help your users find the device identifier, one easy way to do it is adding it to the app's user defaults, so it shows up in the app's section inside the device Settings.

```objective-c
// Displaying the device identifier in the app's settings.
[[NSUserDefaults standardUserDefaults] setObject:[Bugfender deviceIdentifier] forKey:@"bugfenderDeviceIDKey"];
[[NSUserDefaults standardUserDefaults] synchronize];
```

### 3. Setting maximum local storage
Bugfender will store locally all logs and send them when possible to the server. Therefore, you can control how much space Bugfender can use from your device cache. The default value is 5242880 bytes (5MB).

```objective-c
// Setting maximum cache size to 1 Mb
[Bugfender setMaximumLocalStorageSize:1024*1024];

// Setting maximum cache size to infinite
[Bugfender setMaximumLocalStorageSize:0];
    
// Reading the current maximum cache size
NSUInteger maximumLocalStorageSize = [Bugfender maximumLocalStroageSize];
```

## Writing Logs

### Objective-C
To write logs, you must replace `NSLog`with one of the following methods:

- `BFLog(...)`: Default log.
- `BFLogWarn(...)`: Warning log.
- `BFLogErr(...)`: Error log.

As shown above, there are 3 kind of log levels: `BFLogLevelDefault`, `BFLogLevelWarning`, `BFLogLevelError`.

When compiling in DEBUG, Bugfender will redirect the logs to the NSLog, displaying your messages in the console. However, when not compiling on DEBUG (RELEASE, for example), Bugfender won't output anything on the console.

Additionally, you can manually specify a tag o set of tags (string separated by comas) and a log level by using the following method:

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

### Swift
In Swift you can use `Bugfender.LogLineNumber` method or write a helper function similar to `println`:

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

