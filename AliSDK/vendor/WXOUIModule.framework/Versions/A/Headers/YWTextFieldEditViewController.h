//
//  YWTextFieldEditViewController.h
//  Messenger
//
//  Created by Jai Chen on 15/11/11.
//
//

#import <UIKit/UIKit.h>

@interface YWTextFieldEditViewController : UITableViewController <UITextFieldDelegate>

@property (weak, nonatomic) UITextField *textField;

@property (copy, nonatomic) NSString *placeholder;
@property (copy, nonatomic) NSString *contentText;
@property (assign, nonatomic) NSUInteger contentTextMaxLength;

- (void)setDoneButtonItemTitle:(NSString *)itemTitle
                       handler:(void (^)(NSString *text, id sender, YWTextFieldEditViewController *controller))handler;

@property (copy, nonatomic) void (^doneButtonItemHandler)(NSString *text, id sender, YWTextFieldEditViewController *controller);


@property (assign, nonatomic) BOOL shouldShowCountLabel;
@property (assign, nonatomic) BOOL shouldShowBottomDoneButton;
@property (weak, nonatomic) UIButton *bottomDoneButton;

@end
