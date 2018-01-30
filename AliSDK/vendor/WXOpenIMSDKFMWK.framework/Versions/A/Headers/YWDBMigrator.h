//
//  YWDBMigrator.h
//  WXOpenIMSDK
//
//  Created by huanglei on 16/9/22.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "YWServiceDef.h"

@interface YWDBMigrator : NSObject

+ (instancetype)sharedInstance;

/// 强烈的建议你在调用YWAPI的初始化函数前，判断是否需要执行数据升级，如果需要，则调用下面的函数进行升级

- (BOOL)isNeedMigrate;



/// 根据数据库的大小，升级需要等待一段时间才能完成，建议为用户显示进度页面
/// @param aProcessBlock 进度回调
/// @param aCompletionBlock 完成回调
- (void)migrateWithProgressBlock:(YWProgressBlock)aProgressBlock
                 completionBlock:(YWCompletionBlock)aCompletionBlock;

/// 取消正在进行的数据库迁移
- (void)cancelMigrate;

/// 预计迁移时间，单位为分钟
- (CGFloat)estimatedMigrationTime;

@end


/// ERROR DOMAIN
FOUNDATION_EXTERN NSString *kYWDBMigratorDomain;

/// 一般来说，这些key用于调试了解数据库升级失败的原因

/// aCompletionBlock中使用这个key传递升级成功的数据库文件数目
FOUNDATION_EXTERN NSString *kYWDBMigratorKeySuccessCount;
/// aCompletionBlock中使用这个key传递升级失败的数据库文件数目
FOUNDATION_EXTERN NSString *kYWDBMigratorKeyFailedCount;
/// aCompletionBlock中使用这个key传递升级失败的Error数组
FOUNDATION_EXTERN NSString *kYWDBMigratorKeyErrors;



#pragma mark - For Remove Cipher

@interface YWDBMigrator ()

/// 由外部控制是否执行去加密
@property (nonatomic, assign) BOOL isExternalAllowRemoveCipher;

@end

