//
//  YWPhotoPickerHelper.h
//  WXOpenIMUIKit
//
//  Created by huanglei on 16/4/5.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YWIMKit;

typedef NS_ENUM(NSUInteger, YWPhotoPickerType) {
    YWPhotoPickerTypeTakePhoto, /// 拍照
    YWPhotoPickerTypeSingle, /// 相册单选
    YWPhotoPickerTypeMultiEnableOriginalCheck, /// 相册多选，显示原图选项
//    YWPhotoPickerTypeMultiDisableOriginal, /// 相册多选，隐藏原图选项
};


typedef void(^YWPhotoPickerResultBlock)(NSDictionary *aUserInfo);

/// 所选中的图片数据组成的NSArray<NSData *> *
FOUNDATION_EXTERN NSString *const YWPhotoPickerResultKeySelectedImageDataArray;

/// 所选中的图片数据组成的NSArray<id<YWIBAsset>> *
FOUNDATION_EXTERN NSString *const YWPhotoPickerResultKeySelectedAssetsArray;

/// 用户勾选了发送原图，类型为由BOOL构建的：NSNumber *
FOUNDATION_EXTERN NSString *const YWPhotoPickerResultKeyOriginalChecked;


/**
 *  开放接口，用于选择图片；
 *  支持单选，多选，拍照
 */

@interface YWPhotoPickerHelper : NSObject

- (instancetype)initWithYWIMKit:(YWIMKit *)aIMKit;

@property (nonatomic, assign) YWPhotoPickerType photoPickerType;
@property (nonatomic, copy) YWPhotoPickerResultBlock photoPickerResultBlock;
@property (nonatomic, assign) NSUInteger maxCount2Pick; // 照片选择张数上限，多选时生效。默认六张

- (void)setPhotoPickerResultBlock:(YWPhotoPickerResultBlock)photoPickerResultBlock;
- (void)presentFromController:(UIViewController *)aController;
- (void)presentFromController:(UIViewController *)aController completion:(void (^)(void))completion;

@end
