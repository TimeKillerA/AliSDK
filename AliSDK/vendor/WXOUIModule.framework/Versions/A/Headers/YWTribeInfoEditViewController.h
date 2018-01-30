//
//  YWTribeInfoEditViewController.h
//  WXOpenIMSampleDev
//
//  Created by shili.nzy on 15/4/11.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WXOpenIMSDKFMWK/YWFMWK.h>
#import "YWTextFieldEditViewController.h"

typedef enum : NSUInteger {
    YWTribeInfoEditModeModify,
    YWTribeInfoEditModeCreateNormal,
    YWTribeInfoEditModeCreateMultipleChat,
} YWTribeInfoEditMode;

@interface YWTribeInfoEditViewController : YWTextFieldEditViewController

+ (instancetype)instantiateViewControllerWithYWIMKit:(YWIMKit *)imKit;

@property (nonatomic, weak) YWIMKit *kitRef;
@property (nonatomic, strong) YWTribe *tribe;
@property (nonatomic, assign) YWTribeInfoEditMode mode;

@property (nonatomic, strong) NSArray *memberIDs;
@end
