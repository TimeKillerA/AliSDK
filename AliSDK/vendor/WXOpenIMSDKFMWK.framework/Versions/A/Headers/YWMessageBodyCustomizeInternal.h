//
//  YWMessageBodyCustomizeInternal.h
//  WXOpenIMSDK
//
//  Created by sidian on 16/7/12.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import "YWMessageBody.h"

typedef NS_ENUM(NSUInteger, YWCustomInternalMessageType) {
    YWCIMessageTypeActive = 1,
    YWCIMessageTypeVideoChatStart = 10001,
    YWCIMessageTypeVideoChatCancel = 10002,
    YWCIMessageTypeVideoChatReject = 10003,
    YWCIMessageTypeVideoChatStop = 10004,
    YWCIMessageTypeVideoChatAccept = 10005,
    YWCIMessageTypeTransferEHelper = 20001, /// E客服转交通知
    YWCIMessageTypeRedPacketOpenNotity = 30001, // 红包领取通知
    YWCIMessageTypeCombinedMessage = 40001, /// 消息合并转发
};

/// 当前支持的类型
#define YWCIMessageTypeSupportedArray \
@[\
@(YWCIMessageTypeActive),\
@(YWCIMessageTypeVideoChatStart),\
@(YWCIMessageTypeVideoChatCancel),\
@(YWCIMessageTypeVideoChatReject),\
@(YWCIMessageTypeVideoChatStop),\
@(YWCIMessageTypeVideoChatAccept),\
@(YWCIMessageTypeTransferEHelper),\
@(YWCIMessageTypeRedPacketOpenNotity),\
@(YWCIMessageTypeCombinedMessage),\
]

@interface YWMessageBodyCustomizeInternal : YWMessageBody

/**
 *  自定义数据，您应该组织您的数据格式，将其放入content字段中。
 *  请注意长度应该越短越好，有利于消息更快的加载和展示，也有利于节省流量。
 *  您应该尽量只放置元数据，例如图片的url等，而不是直接将图片之类的大数据放入content中。
 *  最长限制受服务端控制。您应该尽量控制在1KB以内。
 */
@property (nonatomic, strong, readonly) NSString *content;

/// 推送穿透内容。summary会显示在push提示或者会话最后消息穿透中。
@property (nonatomic, strong, readonly) NSString *summary;

/// 透传消息：这种消息不会有apns推送，并且对方接收到以后，也不会修改会话，仅通过-[IYWConversationService addOnNewMessageBlockV2:forKey:ofPriority:]
@property (nonatomic, assign) BOOL isTransparent;

@property (nonatomic, readonly) YWCustomInternalMessageType customInternalMessageType;


/// 初始化
- (instancetype)initWithMessageCustomizeContent:(NSString *)content summary:(NSString *)summary;
- (instancetype)initWithMessageCustomizeContent:(NSString *)content summary:(NSString *)summary isTransparent:(BOOL)aIsTransparent;


/**
 *  降级信息
 */
@property (nonatomic, copy, readonly) NSDictionary *degradeDictionary;

- (instancetype)initWithMessageCustomizeContent:(NSString *)content summary:(NSString *)summary isTransparent:(BOOL)aIsTransparent
                              degradeDictionary:(NSDictionary *)aDegradeDictionary;


@end
