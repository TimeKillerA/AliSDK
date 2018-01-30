//
//  YWConversationServiceDef.h
//  
//
//  Created by huanglei on 14/12/18.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YWServiceDef.h"
@class YWPerson;

#pragma mark -

/**
 *  收到新消息的回调
 *  @param aMessages 收到的新消息，数组中包含的对象都遵循 IYWMessage 协议，您可以直接访问 IYWMessage 中的方法
 */
typedef void(^YWConversationOnNewMessageBlock)(NSArray *aMessages);

/**
 *  收到新消息的回调
 *  @param aMessages 收到的新消息，数组中包含的对象都遵循 IYWMessage 协议，您可以直接访问 IYWMessage 中的方法
 *  @param aIsOffline 是否离线消息
 */
typedef void(^YWConversationOnNewMessageBlockV2)(NSArray *aMessages, BOOL aIsOffline);


#pragma mark - 消息控制及生命周期回调相关定义

/**消息控制字段定义**/
/**
 **示例**
 
 @{
     kYWMsgCtrlKeyPush:@{
         kYWMsgCtrlKeyPushKeyNeedPush:@(1),
         kYWMsgCtrlKeyPushKeyHowToPush:@{
             kYWMsgCtrlKeyPushKeyHowToPushKeyTitle:@"推送文案自定义",
             kYWMsgCtrlKeyPushKeyHowToPushKeySound:@"customsound.caf",
             kYWMsgCtrlKeyPushKeyHowToPushKeyData:@"推送透传数据",
         },
     },
     kYWMsgCtrlKeyClientLocal:@{
        kYWMsgCtrlKeyClientLocalKeyOnlySave:@(YES),
        kYWkMsgCtrlKeyClientLocalKeySelfAsReceiver:@(YES)
        }, /// 本地保存
 }
 
 *******
 */

/// 推送控制
/// 值一个字典，控制推送。该字典包含：kYWMsgCtrlKeyPushKeyNeedPush、kYWMsgCtrlKeyPushKeyHowToPush
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyPush;
/// 值为一个整数，控制是否推送：没有这个key为需要推送，@(1)为需要推送，@(0)为不需要推送
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyPushKeyNeedPush;
/// 值为一个字典，控制推送样式。该字典包含：kYWMsgCtrlKeyPushKeyHowToPushKeyTitle、kYWMsgCtrlKeyPushKeyHowToPushKeySound、kYWMsgCtrlKeyPushKeyHowToPushKeyData
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyPushKeyHowToPush;
/// 值为字符串，控制推送文案
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyPushKeyHowToPushKeyTitle;
/// 值为字符串，控制推送声音文件
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyPushKeyHowToPushKeySound;
/// 值为字符串，控制推送携带的数据
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyPushKeyHowToPushKeyData;

/// 漫游控制
/// 置为bool值，控制该消息不进入漫游
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyNoRoaming;

/// 值为一个字典，控制客户端本地行为。该字典包含：kYWMsgCtrlKeyClientLocalKeyOnlySave
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyClientLocal;
/// 值为一个bool值，控制该消息仅保存本地，不发送到服务器。无此key或者@(0)则为需要发送，@(1)则为仅保存本地
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyClientLocalKeyOnlySave;
/// 值为一个bool值，控制该消息的接收者是否为自己，不发送到服务器。无此key或者@(0)则自己为发送者，@(1)则为接收者，仅在单聊中当kYWMsgCtrlKeyClientLocalKeyOnlySave为YES时有效
FOUNDATION_EXTERN NSString *const kYWkMsgCtrlKeyClientLocalKeySelfAsReceiver;
/// 值为一个bool值，控制该消息保存本地时即标记删除，但仍然发送到服务器，本地因为被标记删除所以不会显示。无此key或者@(0)则为不标记删除，@(1)则为标记删除
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyClientLocalKeyMarkDeleted;

/// 反馈消息携带数据(设备信息等等)
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyFeedbackInfo;
/// 自动追加消息数据用于反馈系统
FOUNDATION_EXTERN NSString *const kYWMsgCtrlKeyAppendMsgInfo4Feedback;
/// 用于消息分组，分组内的消息按顺序发送，value类型为NSNumber *，仅用于图片消息
FOUNDATION_EXTERN NSString *const kYWKeyMessageGroupId;

@class YWMessageLifeContext;
@protocol IYWMessage;

/**
 *  用来监听消息的生命周期
 */
@protocol YWMessageLifeDelegate <NSObject>

@optional

/**
 *  即将发送某个消息体
 *  @param aContext 即将发送消息的上下文，目前有效的字段包含：messageBody, controlParameters, conversation
 *  @return 返回context IMSDK根据返回的context来真正发送消息，也就是说，可以通过needContinue字段控制实际是否发送，通过messageBody、controlParameters、conversation来控制实际发送的消息内容等；如果返回nil，则保持原先的值

 *  @brief 强烈的建议你，不要在这个回调中直接调用YWConversation的消息发送API，否则你需要特别注意发送的消息不会触发再次发送新消息，避免死循环。

 */
- (YWMessageLifeContext *)messageLifeWillSend:(YWMessageLifeContext *)aContext;

/**
 *  完成某条消息的发送
 *  @param aMessage 所完成的消息
 *  @param aResult 结果
 */
- (void)messageLifeDidSend:(NSString *)aMessageId conversationId:(NSString *)aConversationId result:(NSError *)aResult;

@end

@class YWConversation, YWMessageBody;

@interface YWMessageLifeContext : NSObject
/**
 *  用于控制是否继续
 *  如果为@(NO), 则停止发送，也不会在本地保存和显示
 */
@property (nonatomic, copy) NSNumber *needContinue;
/// messageBody
@property (nonatomic, strong) YWMessageBody *messageBody;
/// 消息控制信息, key的定义请参考：YWConversationServiceDef.h
@property (nonatomic, copy) NSDictionary *controlParameters;
/// conversation
@property (nonatomic, strong) YWConversation *conversation;

- (instancetype)initWithContext:(YWMessageLifeContext *)aContext;

- (void)mergeValidContentFromContext:(YWMessageLifeContext *)aContext;


@end

#pragma mark -

typedef NS_ENUM(NSInteger, YWConversationInputStatus) {
    YWConversationStopInputStatus = 0x0,    // 输入停止
    YWConversationInputTextStatus = 0x1,    // 正在输入文字
    YWConversationRecordingStatus = 0x2,    // 正在录音
    YWConversationSelectImageStatus = 0x4,  // 弃用
    YWConversationTakePictureStatus = YWConversationSelectImageStatus, //弃用
};


/**
 *  输入状态改变的回调
 *  @param aMessages 收到的新消息
 */
typedef void(^YWConversationInputStatusChangeBlock)(YWPerson *person, YWConversationInputStatus status);

/// 注意这里的定义不能随便修改，必须与底层的type保持一致
typedef NS_ENUM(NSInteger, YWConversationType) {
    YWConversationTypeP2P = 0,
    YWConversationTypeTribe = 30,
    YWConversationTypeCustom = 1024,
    YWConversationTypeUnsupported = 1024 << 1, /// 不支持的会话
};

#pragma mark - 通知定义

/// 会话置顶状态变更通知，Object为YWIMCore对象
#define kYWConvSvcNotForMarkOnTopChanged @"kYWConvSvcNotForMarkOnTopChanged"
/// 传递会话Id，NSString *
#define kYWConvSvcNotForMarkOnTopChangedKeyConvId @"kYWConvSvcNotForMarkOnTopChangedKeyConvId"
/// 传递置顶时间，<=0为不置顶，NSNumber *
#define kYWConvSvcNotForMarkOnTopChangedKeyTime @"kYWConvSvcNotForMarkOnTopChangedKeyTime"




@interface YWConversationServiceDef : NSObject

@end
