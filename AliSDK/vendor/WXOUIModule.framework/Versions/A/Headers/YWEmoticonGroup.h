//
//  YWEmoticonGroup.h
//  WXOpenIMUIKit
//
//  Created by 慕桥(黄玉坤) on 15/6/8.
//  Copyright (c) 2015年 www.alibaba.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IYWEmoticon.h"

@interface YWEmoticonGroup : NSObject

/// 分组名称
@property (nonatomic, copy) NSString *name;

/// 分组图标
@property (nonatomic, strong) UIImage *icon;

/// 分组图标的 URL
@property (nonatomic, copy) NSString *iconURL;

// 表情列表
@property (nonatomic, strong) NSArray<id<IYWEmoticon>> *emotions;

/// 表情资源目录
@property (nonatomic, copy) NSString *resourceDicPath;
@end
