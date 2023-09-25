//
//  NSLogInterceptor.h
//  BugfenderSDK
//
//  Created by Fran Montiel on 24/1/23.
//  Copyright © 2023 Beenario GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BFInterceptedLog.h"

/**
 * Intercept a log entry from NSLog/OSLog and allow to modify it or to block it.
 */
@protocol BFLogInterceptor <NSObject>

/**
 * Intercept a log entry from NSLog/OSLog and allow to modify it or to block it.
 * @param interceptedLog log intercepted
 * @return The log entry to be logged. If nil is returned the log entry won't be logged.
 */
- (BFInterceptedLog *)intercept:(BFInterceptedLog *)interceptedLog;

@end
