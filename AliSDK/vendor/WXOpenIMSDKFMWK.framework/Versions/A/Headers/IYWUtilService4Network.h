//
//  IYWUtilService4Network.h
//
//
//  Created by huanglei on 15/3/11.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  HTTP方法定义
 */
typedef enum : NSUInteger {
    /// Get方法
    YWHttpRequestMethodGet,
    /// Post方法
    YWHttpRequestMethodPost,
} YWHttpRequestMethod;

typedef enum {
    YWNotReachable = 0,
    YWReachableViaWiFi,
    YWReachableViaWWAN
} YWNetworkStatus;

/// 用于WebRequest
FOUNDATION_EXTERN NSString *const kYWHttpRequestParamKeyForWebRequest;
/// 用于BizRequest
FOUNDATION_EXTERN NSString *const kYWHttpRequestParamKeyForBizRequest;

typedef void(^YWNetworkStatusChangeBlock) (YWNetworkStatus status);

typedef void(^YWHttpRequestSuccessBlock)(NSData *aResultData);
typedef void(^YWHttpRequestFailedBlock)(NSError *aError);

typedef void(^YWHttpRequestCompletionBlock)(NSData *aResponseData, NSError *aError, NSInteger aStatusCode, NSDictionary *aResponseHeaders);

typedef void (^YWImageLoadBlock) (UIImage *image, NSData *data, CGFloat progress, NSError *error);

@class YWIMCore;

@protocol IYWUtilService4Network <NSObject>

- (YWNetworkStatus)currentNetworkStatus;

- (void)addNetworkStatusChangeBlock:(YWNetworkStatusChangeBlock)block forKey:(NSString *)key ofPriority:(YWBlockPriority)aPriority;

- (void)removeNetworkStatusChangeBlockForKey:(NSString *)key;

/**
 *  发起一个HTTP请求
 */
- (BOOL)sendHttpRequestWithURLString:(NSString *)aURLString
                              method:(YWHttpRequestMethod)aMethod
                             timeout:(NSTimeInterval)aTimeout
                              params:(NSDictionary *)aParams
                             isAsync:(BOOL)aIsAsync
                        successBlock:(YWHttpRequestSuccessBlock)aSuccessBlock
                         failedBlock:(YWHttpRequestFailedBlock)aFailedBlock
                       inBaseContext:(YWIMCore *)aBaseContext;

/**
 *  发起一个HTTP请求, V2版本
 */
- (BOOL)sendHttpRequestWithURLStringV2:(NSString *)aURLString
                                method:(YWHttpRequestMethod)aMethod
                               timeout:(NSTimeInterval)aTimeout
                                params:(NSDictionary *)aParams
                               isAsync:(BOOL)aIsAsync
                          completionBlock:(YWHttpRequestCompletionBlock)aCompletionBlock
                         inBaseContext:(YWIMCore *)aBaseContext;


/**
 *  下载数据
 */
- (BOOL)downloadDataWithURLString:(NSString *)aURLString
                           method:(YWHttpRequestMethod)aMethod
                          timeout:(NSTimeInterval)aTimeout
                           params:(NSDictionary *)aParams
                          isAsync:(BOOL)aIsAsync
                      enableCache:(BOOL)aEnableCache
                     successBlock:(YWHttpRequestSuccessBlock)aSuccessBlock
                      failedBlock:(YWHttpRequestFailedBlock)aFailedBlock
                    inBaseContext:(YWIMCore *)aBaseContext;

- (void)loadImageFromUrl:(NSString *)imageUrl withLoadBlock:(YWImageLoadBlock)loadBlock;

/**
 *  当前网络状态是否可用
 */
- (BOOL)isReachable;


#pragma mark - https helper

/// 对于IMSDK内部部分cdn等url进行https适配
- (NSString *)changeToSecurityHttpsURL:(NSString*)urlString;

@end
