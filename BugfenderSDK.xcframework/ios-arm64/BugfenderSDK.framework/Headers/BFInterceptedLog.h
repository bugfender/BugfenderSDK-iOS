//
//  BFInterceptedLog.h
//  BugfenderSDK
//
//  Created by Fran Montiel on 24/1/23.
//  Copyright © 2023 Beenario GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Intercepted log from NSLog/OSLog
 */
@interface BFInterceptedLog : NSObject

/**
 * Initializes an BFInterceptedLog with a timestamp, text, and log level.
 * @note You will usually not need to use this method.
 * @param text Text of the log.
 * @param level Level of the log. See BFLogLevel enum for possible values.
 * @param date Timestamp of the log.
 */
-(instancetype _Nonnull) initWithText: (NSString*_Nonnull) text level: (NSInteger)level date: (NSDate*_Nonnull) date;

/**
 * Line in the source file where the log was originated.
 */
@property (nonatomic, assign) NSInteger line;

/**
 * Level of the log. See BFLogLevel enum for possible values.
 */
@property (nonatomic, assign) NSInteger level;

/**
 * Timestamp of the log.
 */
@property (nonatomic, strong) NSDate * _Nonnull date;

/**
 * Tag (or category) of the log.
 */
@property (nonatomic, strong) NSString * _Nonnull tag;

/**
 * Method of the source file where the log was originated.
 */
@property (nonatomic, strong) NSString * _Nonnull method;

/**
 * Source file name where the log was originated.
 */
@property (nonatomic, strong) NSString * _Nonnull file;

/**
 * Text of the log.
 */
@property (nonatomic, strong) NSString * _Nonnull text;

@end
