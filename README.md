Bugfender SDK for iOS [![Build Status](https://travis-ci.org/bugfender/BugfenderSDK-iOS.svg?branch=master)](https://travis-ci.org/bugfender/BugfenderSDK-iOS) [![Available in CocoaPods](https://img.shields.io/cocoapods/v/BugfenderSDK.svg)](https://cocoapods.org/pods/BugfenderSDK) [![Docs](https://img.shields.io/badge/docs-%E2%9C%93-blue.svg)](https://bugfender.github.io/BugfenderSDK-iOS/)
===================

Bugfender is a cloud service to collect mobile application logs. Developers can control log sending programmatically and manually for each device. Logs are available at the [Bugfender console](https://app.bugfender.com/). You'll need an account.

BugfenderSDK works for iOS 8.0 and better.

# Installing the SDK
First of all you will need to add the framework to your project.

## Using CocoaPods

1. Create a Podfile if you don't have one: `pod init`
1. Add Bugfender to your Podfile:
   * Swift or mixed projects:
   ```
   pod 'BugfenderSDK', '~> 1.6'
   ```
   * Objective-C projects: 
   ```
   pod 'BugfenderSDK/ObjC', '~> 1.6' // Doesn't require the Swift runtime
   ``` 
1. Save the file and run: `pod install`. This creates an `.xcworkspace` file for your app. Use this file for all future development on your application.

## Using Carthage

1. Add to your Cartfile:
   ```
   binary "https://raw.githubusercontent.com/bugfender/BugfenderSDK-iOS/master/BugfenderSDK.json" ~>1.6
   ```
1. Save the file and run `carthage update`
1. Import `Carthage/Build/iOS/BugfenderSDK.framework` to your `Linked Frameworks and Libraries` (or drag-n-drop the file to your project). Important: do **not** import as Embedded Framework.
1. Import `SystemConfiguration.framework`, `Security.framework`, `MobileCoreServices.framework`, `CoreGraphics.framework` and `libc++.tbd` as well.
1. _(If using Swift)_ Import [Bugfender.swift](https://raw.githubusercontent.com/bugfender/BugfenderSDK-iOS/master/swift-manual/Bugfender.swift) helper file to your project.

## Manual

If you prefer to install the SDK manually:

1. Go to your **Project** > **Your Target** > **General** > **Linked Frameworks and Libraries** and drag `BugfenderSDK.framework` there.
1. Make sure you have `SystemConfiguration.framework`, `Security.framework`, `MobileCoreServices.framework`, `CoreGraphics.framework` and `libc++.tbd` there as well.
1. _(If using Swift)_ Import [Bugfender.swift](https://raw.githubusercontent.com/bugfender/BugfenderSDK-iOS/master/swift-manual/Bugfender.swift) helper file to your project.

# Using Bugfender
Once you have the framework in your project, here is how to use it.

## Swift

In your AppDelegate class:

```Swift
import BugfenderSDK
```

And add the following to `application(_:didFinishLaunchingWithOptions:)`:

```Swift
Bugfender.activateLogger("YOUR_APP_KEY")
Bugfender.enableUIEventLogging() // optional, log user interactions automatically
Bugfender.enableCrashReporting() // optional, log crashes automatically
bfprint("Hello world!") // use bfprint() as you would use print()
```

Then you may use `BFLog` as you would normally use `NSLog`.

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
    [Bugfender enableUIEventLogging]; // optional, log user interactions automatically
    [Bugfender enableCrashReporting]; // optional, log crashes automatically
    BFLog("Hello world!") // use BFLog as you would use NSLog
    ...
}
```

Then you may use `BFLog` as you would normally use `NSLog`.

You may also want to specify a logging level by using the following macros:

- `BFLog(...)`: Default log.
- `BFLogWarn(...)`: Warning log.
- `BFLogErr(...)`: Error log.

# Advanced features

## Sending issues

Bugfender allows you to send issues to the server. An issue is similar to a session but they are showed in the `issues` section and you can send issues any time from the app, even if the device is not enabled in the system. Issues are useful to keep track of important errors that you can detect in your code.

For sending an issue you can use the following function:

```objective-c
+(void)sendIssueWithTitle:(NSString*)title text:(NSString*)text;
```

*The `text` parameter has Markdown notation support on the server, so you can add some style to the text being sent.*

Here you have an example on how to send an issue using Markdown for the text:

```objective-c
[Bugfender sendIssueWithTitle:@"App Error" text:@"We have found an **Error**, we need to check it"];
```

## Having your app decide when to send logs

In some special circumstances you may want to send logs, regardless of the enabled state of the device in the Bugfender console, for example in a custom exception handler. Use `forceSendOnce` to force sending the logs once, and use `setForceEnabled:` to force it for some period of time.

## Device associated data
You can associate information to a device as if it were a dictionary:

```objective-c
[Bugfender setDeviceString:@"john.smith@example.com" forKey:@"user email"];
```

You can find more information in our blog post [Associated device information](https://bugfender.com/blog/associated-device-information/).

## Device  identifier

Bugfender automatically generates an identifier for the application install in a device. You can retrieve it to show in your UI or send to your server:

```objective-c
NSString *bugfenderDeviceIdentifier = [Bugfender deviceIdentifier];
```

To help your users find the device identifier, one easy way to do it is adding it to the app's user defaults, so it shows up in the app's section inside the device Settings.

```objective-c
// Displaying the device identifier in the app's settings.
[[NSUserDefaults standardUserDefaults] setObject:[Bugfender deviceIdentifier] forKey:@"bugfenderDeviceIDKey"];
[[NSUserDefaults standardUserDefaults] synchronize];
```

## Log buffer size

Bugfender keeps up to 5 MB worth of log data in the device. This way Bugfender can work offline, and you can get some log data from the past when enabling a device. You can change that limit with `setMaximumLocalStorageSize`.

```objective-c
// Setting maximum cache size to 1 Mb
[Bugfender setMaximumLocalStorageSize:1024*1024];
```

## Get Device Link

Sometimes you want to integrate Bugfender with a third party tool, for this the SDK provides a method that returns the URL for the current device, so you can send it to the third party tool to easily go to the logs of the device from the other tool.


```objective-c
+ (NSURL *)deviceIdentifierUrl;
```

## Get Session Link

Sometimes you want to integrate Bugfender with a third party tool, for this the SDK provides a method that returns the URL for the sesssion, so you can send it to the third party tool to easily go to the logs of the current session from the other tool.


```objective-c
+ (NSURL *)sessionIdentifierUrl;
```



# Collecting User feedback 

Getting feedback from the final users is one of the most important things for an app developer. Good user feedback allows you detect errors in your app and helps you to understand better your product. 

Starting from version 1.6, Bugfender provides a new feature to easily collect app feedback from final users. It takes only two minutes and a few lines of code to integrate. You can think about the User Feedback as an special kind of Issue, every time your users submit their feedback you will get a new issue in Bugfender. 

![](https://raw.githubusercontent.com/bugfender/BugfenderSDK-iOS/master/Docs/User-feedbac-default.png)

The easiest way to implement Bugfender User Feedback is using the customizable User Feedback View Controller. It provides a convenient view controller with two text fields, one short for the subject and another bigger for the feedback. Both text fields grow autommatically. 

## Using default UI 

Using the convenient UI provided by Bugfender requires only creating a new View Controller and presenting it modally. All you need is to call the following method and complete the required parameters with the title and placeholders for your UI.

```
// Instantiate new User Feedback 
BFUserFeedbackNavigationController *nvc = [Bugfender userFeedbackViewControllerWithTitle:@"Navigation bar title"
                                              hint:@"Give some instructions to your users"
                                subjectPlaceholder:@"Placeholder for subject textfield"
                                messagePlaceholder:@"Placeholder for message textfield"
                                   sendButtonTitle:@"Send"
                                 cancelButtonTitle:@"Cancel"
                                        completion:^(BOOL feedbackSent, NSURL *feedbackUrl) {
                                            if (feedbackSent) {
                                                // Say thanks!
                                                // feedbackUrl is a direct link to the dashboard
                                                // Use it to create automations or send it to your server 
                                            } else {
                                                // User decided to not send feedback
                                            }
                                        }];

// Present modally 
[self presentViewController:nvc animated:YES completion:nil];
```

Additionally, if you require more customization you can configure the view controller prior to presenting it. 

*Please note BFUserFeedbackNavigationController is a subclass of navigation controller. You need to access the view controller using the public property feedbackViewController.*

```
// Access the root view controller.  
BFUserFeedbackViewController *feedbackViewController = nvc.feedbackViewController;

// Change the background colors
feedbackViewController.mainBackgroundColor = [UIColor lightGrayColor];
feedbackViewController.secondaryBackgroundColor = [UIColor whiteColor];

// Change the font of the hint text 
feedbackViewController.hintFont = [UIFont fontWithName:@"Avenir" size:14];
```
![](https://raw.githubusercontent.com/bugfender/BugfenderSDK-iOS/master/Docs/User-feedback-custom.png)

For a complete list of customizable attributes you can inspect "BFUserFeedbackViewController.h" or [read the docs](http://bugfender.github.io/BugfenderSDK-iOS/).

## Using a custom UI

If you need further customization than provided by BFUserFeedbackViewController you can implement your own UI. All you have to do is collect your user feedback as you wish and send it to Bugfender using `sendUserFeedback`:

```
NSURL *feedbackUrl = [Bugfender sendUserFeedbackWithSubject:@"Title of the feedback" message:@"message of the feedback"];
```
The returned URL is a direct link to the Bugfender's dashboard. Use it to create automations or to keep a reference in your servers,
