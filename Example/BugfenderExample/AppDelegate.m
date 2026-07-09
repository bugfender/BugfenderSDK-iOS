//
//  AppDelegate.m
//  BugfenderExample
//
//  Created by gimix on 14/08/15.
//  Copyright (c) 2015 Bugfender. All rights reserved.
//

#import "AppDelegate.h"
#import <BugfenderSDK/BugfenderSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Configure Bugfender with all options enabled
    [Bugfender activateLogger:@"WyzM3mYU8SxmgsErYbdpZ5JvkhW8Nvmn"]; // Use your own token here in order to see results in your account
    [Bugfender enableUIEventLogging];
    [Bugfender enableCrashReporting];
    [Bugfender enableNSLogLogging];
    
    BFLog(@"Hello world! 🎉");
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {

}

- (void)applicationDidEnterBackground:(UIApplication *)application {

}

- (void)applicationWillEnterForeground:(UIApplication *)application {

}

- (void)applicationDidBecomeActive:(UIApplication *)application {

}

- (void)applicationWillTerminate:(UIApplication *)application {

}

@end
