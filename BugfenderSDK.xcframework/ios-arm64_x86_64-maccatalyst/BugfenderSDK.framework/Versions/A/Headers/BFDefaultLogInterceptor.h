//
// Created by Fran Montiel on 24/1/23.
// Copyright (c) 2023 Beenario GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BFLogInterceptor.h"

/**
 * Default BFLogInterceptor that returns the same BFInterceptedLog that receives
 */
@interface BFDefaultLogInterceptor: NSObject<BFLogInterceptor>
@end
