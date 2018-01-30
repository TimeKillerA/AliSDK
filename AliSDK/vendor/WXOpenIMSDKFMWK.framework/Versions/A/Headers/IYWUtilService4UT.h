//
//  IYWUtilService4UT.h
//  WXOpenIMSDK
//
//  Created by sidian on 15/7/22.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IYWUtilService4UT <NSObject>

/*
 * @brief  UT打点
 * @param  page,打点所在页面
 * @param  eventId,事件Id，pageEnter，2001， ctrlClick，2101
 * @param  arg1\arg2\arg3\args，其他参数。
 */
- (void)commitEvent:(NSObject *)page
            eventID:(int)eventID
               arg1:(NSString *)arg1
               arg2:(NSString *)arg2
               arg3:(NSString *)arg3
               args:(NSDictionary *)dict;

/*
 * 进入VC
 */
-(void) pageAppear:(UIViewController *)pViewController withUTName:(NSString *)UTName;

/*
 * 离开VC
 */
-(void) pageDisAppear:(UIViewController *) pViewController withUTName:(NSString *)UTName;

/*
 * @brief 时长打点
 * @param duration,毫秒
 * @param eventId,事件
 * @param pageName,页面名称
 * @param args,其他参数信息
 */
- (void)commitDuration:(long long)duration withEventLabel:(NSString *)eventId onEventPage:(NSString *)pageName args:(NSDictionary *)args;

- (void)ctrlClicked:(NSString *)controlName onPage:(NSObject *)pageName;
@end
