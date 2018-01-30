//
//  YWMessageBodyUnsupported.h
//  
//
//  Created by Jai Chen on 15/1/23.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "YWMessageBody.h"

@interface YWMessageBodyUnsupported : YWMessageBody

@property (nonatomic, copy) NSManagedObjectID *internalManagedObjectID;
// 穿透文案
@property (nonatomic, strong, readwrite) NSString *summary;
// 降级文案
@property (nonatomic, strong, readwrite) NSString *degradeText;
// 提醒升级
@property (nonatomic, assign, readwrite) BOOL needUpgrade;
// 是否透传
@property (nonatomic, assign) BOOL isTransparent;

+ (instancetype)makeMessageBodyWithMsgContent:(NSString *)content imCore:(YWIMCore *)imCore;

@end