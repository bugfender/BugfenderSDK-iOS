Bugfender SDK for iOS [![Docs](https://img.shields.io/badge/docs-%E2%9C%93-blue.svg)](https://bugfender.github.io/BugfenderSDK-iOS/)
===================

Bugfender is a cloud service to collect mobile application logs. Developers can control log sending programmatically and manually for each device. Logs are available at the [Bugfender dashboard](https://dashboard.bugfender.com/). You'll need an account.

Supported iOS versions:
 * BugfenderSDK 2.0 works for iOS 12.0 and newer.
 * For iOS 11.0 support you can use BugfenderSDK 1.12.
 * For iOS 10 support you can use BugfenderSDK 1.10.6.
 * For iOS 8 support you can use BugfenderSDK 1.8.

# Using Bugfender
Once you have the framework in your project, using it is as easy as using `BFLog()` instead of `NSLog()` or `bfprint()` instead `print()`.

## Swift

If your application uses SwiftUI and doesn't have an AppDelegate, you might need to create one like this:

```Swift
@main
struct YourAppNameApp: App {

    @UIApplicationDelegateAdaptor(AppDelegate.self) var appDelegate

    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}

class AppDelegate: NSObject, UIApplicationDelegate {
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey : Any]? = nil) -> Bool {
        Bugfender.activateLogger("YOUR_APP_KEY")
        Bugfender.enableUIEventLogging() // optional, log user interactions automatically
        Bugfender.enableCrashReporting() // optional, log crashes automatically
        bfprint("Hello world!") // use bfprint() as you would use 
        return true
    }
}
```
Then you may use `BFLog` as you would normally use `NSLog` or `print`.

You may also want to specify a logging level by using the following helper functions:

- `Bugfender.print(...)`: Default log.
- `Bugfender.warning(...)`: Warning log.
- `Bugfender.error(...)`: Error log.

## Objective-C

Make Bugfender available project-wide by adding the following line to the `.pch` file:

```objective-c
#import <BugfenderSDK/BugfenderSDK.h>
```

Get an API key from the [Bugfender console](https://app.bugfender.com/). In your `AppDelegate` call [activateLogger](http://cocoadocs.org/docsets/BugfenderSDK/0.3.9/Classes/Bugfender.html#//api/name/activateLogger:) when the application starts, like this:

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    ...
    // Activate the remote logger with an App Key.
    [Bugfender activateLogger:@"YOUR_APP_KEY"];
    [Bugfender enableNSLogLogging]; // optional, capture logs printed to console automatically
    [Bugfender enableUIEventLogging]; // optional, log user interactions automatically
    [Bugfender enableCrashReporting]; // optional, log crashes automatically
    BFLog("Hello world!") // use BFLog as you would use NSLog
    ...
}
```

You may use `BFLog` as you would normally use `NSLog`.

You may also want to specify a logging level by using the following macros:

- `BFLogFatal(...)`: Fatal log.
- `BFLogErr(...)`: Error log.
- `BFLogWarn(...)`: Warning log.
- `BFLogInfo(...)`: Info log.
- `BFLog(...)`: Default (debug) log.
- `BFLogTrace(...)`: Trace log.

# Documentation
For information on how to use our SDK, you can check the [documentation](https://docs.bugfender.com/docs/category/ios/) to configure your project.
