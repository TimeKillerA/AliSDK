//
//  YWCombinedForwardConversation.h
//  WXOpenIMSDK
//
//  Created by huanglei on 16/9/8.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import "YWConversation.h"

@class YWMessageBodyCustomizeInternal;

@interface YWCombinedForwardConversation : YWConversation

- (instancetype)initWithCombinedForwardMessage:(id<IYWMessage>)aMessage;

@property (nonatomic, readonly) YWMessageBodyCustomizeInternal *body;
@property (nonatomic, readonly) NSString *summary;

@end
