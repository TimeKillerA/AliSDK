//
//  YWTribeKitManager.h
//  WXOpenIMUIKit
//
//  Created by Jai Chen on 16/7/8.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YWPerson;
@class YWTribe;
@class YWIMKit;

@protocol YWTribeKitManagerDelegate <NSObject>

/**
 *  需要显示联系人选择界面
 *
 *  @param viewController    触发该逻辑的视图控制器
 *  @param excludedPersons   需要在联系人选择界面排除掉的联系人
 *  @param completionHandler 完成联系人选择后调用该 Block，以选中的联系人作为参数
 */
- (void)presentContactsPickerFromViewController:(UIViewController *)viewController
                                       excluded:(NSArray<YWPerson *> *)excludedPersons
                              completionHandler:(void (^)(NSArray<YWPerson *> *selectedPersons))completionHandler;


/**
 *  需要为 view 显示提醒信息
 */
- (void)showHint:(NSString *)text forView:(UIView *)view;

- (void)showHint:(NSString *)text withIcon:(UIImage*)image;

/**
 *  需要为 view 显示加载中的指示
 */
- (void)configureActivityIndicator:(NSString *)additionalText hidden:(BOOL)hidden forView:(UIView *)view;


@optional

/**
 *  提供展示群二维码界面的 view controller，如果实现该方法，群资料列表中奖展示群二维码的 cell
 *
 *  @param tribe 待展示二维码的群
 *
 *  @return view controller，二维码的加载和展示需要自己实现，YWTribeQRCodeViewController 提供了基本的布局，可以考虑通过继承该类进行实现
 */
- (UIViewController *)instantiateQRCodeViewControllerForTribe:(YWTribe *)tribe imKit:(YWIMKit *)imKit;

@end

@interface YWTribeKitManager : NSObject

+ (id<YWTribeKitManagerDelegate>)managerDelegate;
+ (void)setManagerDelegate:(id<YWTribeKitManagerDelegate>)delegate;

@end
