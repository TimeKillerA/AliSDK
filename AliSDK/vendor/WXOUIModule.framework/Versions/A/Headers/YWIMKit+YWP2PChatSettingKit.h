//
//  YWIMKit+YWP2PChatSettingKit.h
//  WXOpenIMUIKit
//
//  Created by huanglei on 16/7/11.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import "YWIMKit.h"
#import "YWP2PChatSettingKitDelegate.h"


@interface YWIMKit (YWP2PChatSettingKit)

@property (nonatomic, readwrite, weak) id<YWP2PChatSettingKitDelegate> P2PChatSettingKitDelegate;

@end
