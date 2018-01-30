//
//  YWTribeProfileViewController.h
//  WXOpenIMSampleDev
//
//  Created by Jai Chen on 15/10/15.
//  Copyright © 2015年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WXOpenIMSDKFMWK/YWFMWK.h>

#import "YWIMKit.h"
//#import <WXOUIModule/YWIMKit.h>

@interface YWTribeProfileViewController : UIViewController

+ (instancetype)instantiateViewControllerWithYWIMKit:(YWIMKit *)imKit;

@property (nonatomic, weak) YWIMKit *kitRef;
@property (nonatomic, strong) YWTribe *tribe;
@property (nonatomic, copy) NSString *tribeId;

@end
