//
//  BFInterceptedLog.h
//  BugfenderSDK
//
//  Created by Fran Montiel on 24/1/23.
//  Copyright © 2023 Mobile Jazz. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Intercepted log from NSLog/OSLog
 */
@interface BFInterceptedLog : NSObject

-(instancetype _Nonnull) initWithText: (NSString*_Nonnull) text level: (NSInteger)level date: (NSDate*_Nonnull) date;

@property (nonatomic, assign) NSInteger line;
@property (nonatomic, assign) NSInteger level;

@property (nonatomic, strong) NSDate * _Nonnull date;

@property (nonatomic, strong) NSString * _Nonnull tag;
@property (nonatomic, strong) NSString * _Nonnull method;
@property (nonatomic, strong) NSString * _Nonnull file;
@property (nonatomic, strong) NSString * _Nonnull text;

@end
