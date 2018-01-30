//
//  YWTribeListViewController.h
//  WXOpenIMUIKit
//
//  Created by Jai Chen on 16/8/16.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YWIMKit;
@class YWTribe;
@interface YWTribeListViewController : UITableViewController

@property (nonatomic, weak) YWIMKit *kitRef;

@property (nonatomic, copy) void (^didSelectRowBlock)(YWTribe *tribe);
@property (nonatomic, copy) void (^didTapAvatarBlock)(YWTribe *tribe);

@end
