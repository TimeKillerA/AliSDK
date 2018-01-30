//
//  YWP2PChatSettingViewController.h
//  Messenger
//
//  Created by muhua.hzh on 12-10-17.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YWIMKit;
@class YWP2PConversation;


typedef NS_ENUM(NSUInteger, YWP2PChatInfoHeadType) {
    YWP2PChatInfoHeadTypeAdd,
    YWP2PChatInfoHeadTypeSummary
};

@class YWP2PChatSettingViewController;

/// 添加按钮被按下的回调
typedef void(^YWP2PChatSettingDidPressAddBlock)(YWP2PChatSettingViewController *aController);

@interface YWP2PChatSettingViewController : UIViewController<UITableViewDelegate, UITableViewDataSource>

- (id)initWithP2PConversation:(YWP2PConversation *)aConversation kit:(YWIMKit *)aKit;

@property (nonatomic, strong, readonly) YWP2PConversation *conversation;
@property (nonatomic, weak, readonly) YWIMKit *kitRef;

@property (nonatomic, copy) YWP2PChatSettingDidPressAddBlock didPressAddBlock;
/// 添加按钮被按下的回调
- (void)setDidPressAddBlock:(YWP2PChatSettingDidPressAddBlock)didPressAddBlock;

#pragma mark - for inherit

@property (nonatomic, strong) UITableView* tableView;

@end

