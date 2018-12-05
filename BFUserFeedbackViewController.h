//
//  BFUserFeedbackViewController.h
//  BugfenderSDK
//
//  Created by Rubén Vázquez Otero on 16/10/2018.
//  Copyright © 2018 Mobile Jazz. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BFUserFeedbackViewController : UITableViewController {
    
}

#pragma mark - Background colors

/**
 The background of the view controller
 */
@property (nonatomic, strong) UIColor *mainBackgroundColor;

/**
 Background for textfields
 */
@property (nonatomic, strong) UIColor *secondaryBackgroundColor;

#pragma mark - Hint

/**
 The hint is the upper text in the view controller.
 Use the hint give instructions to your users or just to thank them for providing feedback
 */
@property (nonatomic, strong) NSString *hint;

@property (nonatomic, strong) UIFont *hintFont;

@property (nonatomic, strong) UIColor *hintFontColor;

#pragma mark - Subject

/**
 The subject of the feedback.
 Remember to provide a placeholder
 */
@property (nonatomic, strong) UIFont *subjectFont;

@property (nonatomic, strong) UIColor *subjectFontColor;

@property (nonatomic, strong) UIColor *subjectPlaceholderFontColor;

@property (nonatomic, strong) NSString *subjectPlaceholder;

#pragma mark - Message
/**
 The message of the feedback
 Remember to provide a placeholder 
 */
@property (nonatomic, strong) UIFont *messageFont;

@property (nonatomic, strong) UIColor *messageFontColor;

@property (nonatomic, strong) UIColor *messagePlaceholderFontColor;

@property (nonatomic, strong) NSString *messagePlaceholder;

#pragma mark - Actions

- (void)dismiss;

- (void)sendFeedback;

/**
 Pass a block if you want to be notified after feedback was sent (or not)
 */
@property (nonatomic, copy) void (^completionBlock)(BOOL feedbackSent);

@end

NS_ASSUME_NONNULL_END
