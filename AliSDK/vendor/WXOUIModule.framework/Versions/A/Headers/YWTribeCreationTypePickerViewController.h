//
//  YWTribeCreationTypePickerViewController.h
//  WXOpenIMUIKit
//
//  Created by Jai Chen on 16/8/10.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WXOpenIMSDKFMWK/YWTribe.h>

@interface YWTribeCreationTypePickerViewController : UIViewController

@property (copy, nonatomic) void (^completion)(YWTribeType type);

- (void)showForViewController:(UIViewController *)viewController;
- (void)dismiss;

@end
