//
//  IYWLogService.h
//  WXOpenIMSDK
//
//  Created by huanglei on 15/3/27.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  日志级别
 */
/// 用于Debug打包及问题调试
FOUNDATION_EXTERN NSInteger const YWLogLevelDebug;
/// 用于Release包
FOUNDATION_EXTERN NSInteger const YWLogLevelInfo;
/// 用于登录连接等流程信息输出，以及普通错误信息
FOUNDATION_EXTERN NSInteger const YWLogLevelWarning;
/// 用于登录连接等严重错误
FOUNDATION_EXTERN NSInteger const YWLogLevelError;
/// 用于禁止日志输出
FOUNDATION_EXTERN NSInteger const YWLogLevelDisable;


@protocol IYWLogService <NSObject>

/// 设置文件日志级别
@property (nonatomic, readwrite) NSInteger logLevel;

/// 设置是否开启控制台日志
@property (nonatomic, readwrite) BOOL enableXcodeConsole;


#pragma mark - add log

/**
 *  记录日志到IMSDK的日志文件
 */
- (void)logWithLevel:(NSInteger)aLevel tag:(NSString *)aTag format:(NSString *)aFormat, ...;

/**
 *  将要把日志写到文件的回调，你可以在这个里面将日志写到textView等控件，用于在界面上查看日志信息
 *  @param aLogInfo 日志信息
 *  @param aLevel 日志级别
 */
typedef void(^YWLogDidOutputBlock)(NSString *aLogInfo, NSInteger aLevel);
/**
 *  将要把日志写到文件的回调，你可以在这个里面将日志写到textView等控件，用于在界面上查看日志信息
 */
@property (nonatomic, copy, readonly) YWLogDidOutputBlock didOutputBlock;
- (void)setDidOutputBlock:(YWLogDidOutputBlock)didOutputBlock;


#pragma mark - 诊断

/**
 *  需要关闭调试界面时，在YWAPI初始化成功后调用
 */
@property (nonatomic, assign) BOOL needCloseDiag;

/**
 *  外部控制调试界面
 */
- (UIViewController *)diagController;
/**
 *  外部控制上传日志
 */
- (void)uploadLogWithCompletionBlock:(void(^)(NSString *aFileName))aCompletionBlock;






#pragma mark - deprecated

/**
 *  设置日志开关，默认开启。
 */
- (void)setLogEnabled:(BOOL)aEnabled __attribute__((deprecated("请直接使用设置日志级别的接口")));

/**
 *  日志是否开启，默认开启。
 */
- (BOOL)logEnabled __attribute__((deprecated("请直接使用设置日志级别的接口")));


@end
