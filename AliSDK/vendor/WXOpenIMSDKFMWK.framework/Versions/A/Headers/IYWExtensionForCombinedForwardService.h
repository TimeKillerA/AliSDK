//
//  IYWExtensionForCombinedForwardService.h
//  WXOpenIMUIKit
//
//  Created by huanglei on 16/9/8.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IYWExtensionServiceDef.h"
#import "IYWMessage.h"

@class YWMessageBodyCustomizeInternal;
@class YWCombinedForwardConversation;

@protocol IYWExtensionForCombinedForwardService <IYWExtension>

/**
 *  构造合并转发消息体
 *  @param  aMessages   需要合并转发的消息Array
 *  @param  aFromConversation   来源conversation
 *  @param  pTips     获取提示语
 *  @return 返回构造的内部自定义消息体，如果为nil则表示所有传入的消息都不支持合并转发
 */
- (YWMessageBodyCustomizeInternal *)makeCombinedForwardMessageBodyWithMessages:(NSArray< id<IYWMessage> > *)aMessages
                                                              fromConversation:(YWConversation *)aFromConversation
                                                                       getTips:(NSString * __autoreleasing * )pTips;


/**
 *  将合并后的自定义消息体，转发给某个会话
 *  @param  aBody   合并后的自定义消息体
 *  @param  aConversation   目标会话
 */
- (void)sendCombinedForwardBody:(YWMessageBodyCustomizeInternal *)aBody
                 toConversation:(YWConversation *)aConversation
                       progress:(YWMessageSendingProgressBlock)aProgress
                     completion:(YWMessageSendingCompletionBlock)aCompletion;

/**
 *  构造合并转发的消息记录会话
 *  @param aMessage 合并转发消息
 *  @return 返回构造的会话，如果为nil则表示传入的aMessage不合法
 */
- (YWCombinedForwardConversation *)makeCombinedForwardConversationWithMessage:(id<IYWMessage>)aMessage
                                                       getTips:(NSString * __autoreleasing *)pTips;


@end
