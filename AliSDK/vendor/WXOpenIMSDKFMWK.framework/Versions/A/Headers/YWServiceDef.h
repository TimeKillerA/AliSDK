//
//  YWServiceDef.h
//
//
//  Created by huanglei on 14/12/11.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

/**
 * 异步执行的统一回调
 * @param aError 结果错误类型，如果没有错误则为nil
 * @param aResult 存放结果数据，key由各业务协商定义
 */
typedef void(^YWCompletionBlock)(NSError *aError, NSDictionary *aResult);


/**
 *  异步发送消息完成的统一回调
 *
 *  @param aError  结果错误类型，如果没有错误则为nil
 *  @param messageID 完成消息发送的消息 ID
 */
typedef void(^YWMessageSendingCompletionBlock)(NSError *error, NSString *messageID);

/// error的userInfo中，使用这个key来传递错误描述
FOUNDATION_EXTERN NSString *const YWErrorUserInfoKeyDescription;

/**
 * 异步执行的进度回调
 * @param aProgress 进度值，0.f~1.0f
 * @param aUserInfo 额外传递的信息，key由各业务协商定义
 */
typedef void(^YWProgressBlock)(CGFloat aProgress, NSDictionary *aUserInfo);


/**
 * 异步执行的进度回调
 * @param aProgress 进度值，0.f~1.0f
 *  @param messageID 完成消息发送的消息 ID
 */
typedef void(^YWMessageSendingProgressBlock)(CGFloat progress, NSString *messageID);

/**
 *  Block优先级定义
 */
typedef NS_ENUM(NSUInteger, YWBlockPriority) {
    /// 开发者的回调
    YWBlockPriorityDeveloper = 1,
    /// 不同模块的回调
    YWBlockPriorityOtherModule,
    /// 本模块的回调
    YWBlockPriorityThisModule
};

@class YWIMCore;
/**
 *  IMKit必须遵循这个初始化协议
 */
@protocol YWIMKitLifeProtocol <NSObject>

- (id<YWIMKitLifeProtocol>)initWithIMCore:(YWIMCore *)aIMCore;

@end




@interface YWServiceDef : NSObject

@end
