# 1.5.0
- Added crash reporting
- Added information when deleting logs unsent to the server
- Added exponential back off if the server is not reachable

# 1.4.10
- Added method for setting API endpoint

# 1.4.9
- Fixed crash when sendIssues is called with nil parameters.
- Adding some other parameter validations.

# 1.4.8
- Fixed minor issues.

# 1.4.7
- Fixed minor issues.

# 1.4.6
- Added method to get the session identifier. 
- Now send issue method returns the issue identifier. 

# 1.4.5
- Fixed issue with the latest release.

# 1.4.4
- Improvements with the CPU consumption.

# 1.4.3
 - Stability update: fixed crash in very rare circumstances.
 - Improvements when the sdk is deleting the old logs because the max storage size is reached.   

# 1.4.2
 - Fixing CocoaPods when using static libraries in Objective-C
 - Now compatible with Swift 2.3, 3.0 and 3.1
 - Fixing appledoc, fixToConsole default setting wrongly documented
 - Fixing appledoc, some argument names were wrong
 - Printing an empty line on BFLog(nil);

# 1.4.0
 - Declared the framework as a Clang module, so that the framework can be used in Swift without bridging headers
 - Removed redundant and outdated method calls to make the SDK docs/API cleaner
 - Published helper file for Swift projects

# 0.3.27
 - Stability update: fixed crash in very rare circumstances.

# 0.3.26
 - Improved networking code, smaller and more efficient
 - Fixed conflict with AFNetworking library

# 0.3.25
 - enableNSLogLogging is now marked as deprecated, not working since iOS 10
 - Dropping support for iOS 7
 - Improvements on the networking code

# 0.3.24
 - Better formatting of the automated user interaction logging

# 0.3.23
 - Fixing missing some NSLogs at the beginning and end of the session, especially on iOS 10
 - Fixing documentation warnings raised by Xcode 8
 - Fixing duplicated logs from NSLog when DEBUG macro is defined when using BFLog

# 0.3.22
 - Fixing bug that sends empty sessions to the server
 - Fixing a bug that reports wrong app version information when the build number contains the dot character

# 0.3.21
 - Fixing wake lock to avoid applications dying faster in the background

# 0.3.20
 - Bug fix: date formatting in devices in Arabic
 - Improves: format for UI events

# 0.3.18
 - fixing nil dereference exceptions (rarely seen)

# 0.3.17
 - Fixes synchronization of device details set with setDevice*
 - Allows the change of the API endpoint via environment variable for Bugfender preproduction tests

# 0.3.16
 - Fixes #11, crash when using Bugfender with CocoaLumberjack and empty log message

# 0.3.15
 - Fixes timestamp estimation and some UIEvents without timestamp.
 - Better description for topmost view controller and UIEvents

# 0.3.14
 - Recompiled with Xcode 7, supports Bitcode

# 0.3.10
 - Fixed crash on iOS7 when NSLog logging is enabled
 - Added documentation about issues

# 0.3.9
 - Added issues
 - Option to send logs from the app
 
# 0.3.8
 - Added device detail key-value storage
 - Fixed a crash when device disk was full

# 0.3.7
 - Efficiency and stability improvements

# 0.3.6
 - Automated logging of NSLog
 - Automated UIEvent logging
 - Efficiency and stability improvements

