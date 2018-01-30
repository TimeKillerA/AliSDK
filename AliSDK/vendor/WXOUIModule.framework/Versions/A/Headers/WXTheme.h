//
//  WXTheme.h
//  WXOUIModule1
//
//  Created by Jai Chen on 14/12/29.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

#define WXThemeShared [WXTheme sharedInstance]

@interface WXTheme : NSObject

+ (WXTheme *)sharedInstance;
- (void)updateThemeWithUIKitBundle:(NSBundle *)bundle;

/**
 *  根据键获取颜色，如果主题配置中没有指定对应颜色，则直接返回 defaultColor
 *
 *  @param key          键
 *  @param defaultColor 主题没有指定颜色时所返回的颜色
 *
 */
- (UIColor *)colorForKey:(NSString *)key defaultColor:(UIColor *)defaultColor;
- (UIColor *)colorForKey:(NSString *)key;


/**
 *  根据键获取颜色，如果主题配置中没有指定对应颜色，则直接返回 defaultColor
 *
 *  @param key          键的数组，根据数据优先采用有效的建返回颜色
 *  @param defaultColor 主题没有指定颜色时所返回的颜色
 *
 */
- (UIColor *)colorForKeys:(NSArray<NSString *> *)keys defaultColor:(UIColor *)defaultColor;
- (UIColor *)colorForKeys:(NSArray<NSString *> *)keys;

/**
 *  按顺序返回首个有效的键
 *
 *  @param keys 颜色键的数组
 *
 *  @return 有效的键
 */
- (NSString *)validKeyInColorKeys:(NSArray<NSString *> *)keys;

/**
 *  通过16位颜色字符串生成颜色的辅助方法
 */
- (UIColor *)colorWithHexString:(NSString *)hexString;


/**
 *  根据图片名称返回图片
 *
 *  @param imageName 图片名称
 *
 *  @return 图片
 */
- (UIImage *)themeImageNamed:(NSString *)imageName;

- (UIImage *)themeImageNamed:(NSString *)imageName colorizedKey:(NSString *)colorizedKey;
- (UIImage *)themeImageNamed:(NSString *)imageName colorizedKey:(NSString *)colorKey defaultColor:(UIColor *)aDefaultColor;

- (UIImage *)themeImageNamed:(NSString *)name
                colorizedKey:(NSString *)colorizedKey
configureCapInsetsUsingBlock:(UIEdgeInsets (^)(UIImage *image))block;

- (UIImage *)themeImageNamed:(NSString *)name
                colorizedKey:(NSString *)colorizedKey
                defaultColor:(UIColor *)aDefaultColor
configureCapInsetsUsingBlock:(UIEdgeInsets (^)(UIImage *image))block;


- (void)addImageProviderBlock:(UIImage * (^)(NSString *imageName))block forKey:(NSString *)key;
- (void)removeImageProviderBlockForKey:(NSString *)key;

@end
