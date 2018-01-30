//
//  IYWDBService.h
//  WXOpenIMSDK
//
//  Created by huanglei on 16/8/18.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "YWDBServiceDef.h"
#import "YWServiceDef.h"

@protocol IYWDBService <NSObject>






#pragma mark - Context Manage

typedef void (^YWDBReadonlyBlock)();

/**
 *  Readonly模式，一般用于在次线程搜索等大数据量读取
 *  在block中引起数据库修改和保存，将导致不可预估的结果
 */
- (void)performReadonlyBlock:(YWDBReadonlyBlock)aBlock;

typedef void (^YWDBBatchOperationBlock)(void);

/**
 *  批量读写操作，一般用于在次线程修改或者写入大数据量，block最后会自动执行一次save，通过YWCompletionBlock回调save结果
 *  如果是只读，请使用👆的performReadonlyBlock
 */
- (void)performBatchOperationBlock:(YWDBBatchOperationBlock)aBlock completionBlock:(YWCompletionBlock)aCompletion;


@end
