//
//  IYWEmoticon.h
//  WXOpenIMUIKit
//
//  Created by Jai Chen on 16/6/28.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, YWEmoticonType) {
    /// 静态表情
    YWEmoticonTypeStaticImage = 0,
    
    /// Gif表情
    YWEmoticonTypeGifAnimateImage,
    
    /// 目前暂不支持以下类型
    /// 系统表情
    YWEmoticonTypeSymblEmoticon,
    /// 自定义表情
    YWEmoticonTyperUserCustom,
    
    YWEmoticonTypeCount
};

@protocol IYWEmoticon <NSObject>

@required

/**
 *  表情资源数据
 */
- (NSData *)resourceData;

/**
 *  表情缩略图
 */
- (UIImage *)thumbnail;

/**
 *  表情类型
 */
- (YWEmoticonType)emoticonType;

@optional

@end