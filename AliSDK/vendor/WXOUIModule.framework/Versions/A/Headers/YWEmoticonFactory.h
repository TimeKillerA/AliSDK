//
//  EmoticonFactory.h
//  Messenger
//
//  Created by zhiguan.ll on 11-12-7.
//  Copyright (c) 2011年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IYWEmoticon.h"

@class GifImage;

@interface YWEmoticon : NSObject<IYWEmoticon>

@property (nonatomic, copy) NSString *emoticon;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, copy) NSString *comments;

@end

@interface YWEmoticonFactory : NSObject
+ (YWEmoticonFactory *)sharedInstance;
- (NSArray*)shareEmoticonsInfoWithType:(YWEmoticonType)type;
- (NSArray*)shareEmoticonsSymbolsWithType:(YWEmoticonType)type;
- (NSMutableDictionary *)shareEmoticonImagesWithType:(YWEmoticonType)type;
+ (YWEmoticon *)getEmoticonInfoByEmoticon:(NSString *)emoticon WithType:(YWEmoticonType)type;
+ (UIImage *)getEmoticonImage:(NSString *)emoticonFileName WithType:(YWEmoticonType)type; // emoticonFileName不带扩展名
+ (GifImage*)getAnimateEmoticonImage:(NSString *)emoticonFileName; // emoticonFileName不带扩展名，只支持EmoticonTypeGifAnimateImage类型

+ (void) matchEmoticons:(NSString *)content result:(NSMutableDictionary *)resDic;

//重置表情(切换环境时调用)
- (void) resetEmoticons;

/**
 *  匹配表情符号的正则表达式
 */
@property (nonatomic, retain) NSRegularExpression *sharedEmoticonSymbolsRegex;

@end
