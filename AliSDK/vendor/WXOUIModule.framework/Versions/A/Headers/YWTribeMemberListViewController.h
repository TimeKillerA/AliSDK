//
//  YWTribeMemberListViewController.h
//  WXOpenIMSampleDev
//
//  Created by Jai Chen on 15/10/15.
//  Copyright © 2015年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <WXOpenIMSDKFMWK/YWFMWK.h>
#import "YWIMKit.h"

//#import <WXOUIModule/YWIMKit.h>

/// 成员被当前账号移出群的通知
FOUNDATION_EXTERN  NSString *const YWTribeMemberListNotficationRemovedSucceed;
FOUNDATION_EXTERN  NSString *const YWTribeMemberListNotficationRemovedSucceedKeyTribeId;
FOUNDATION_EXTERN  NSString *const YWTribeMemberListNotficationRemovedSucceedKeyRemovedPerson;

@interface YWTribeMemberListViewController : UITableViewController

@property (nonatomic, weak) YWIMKit *kitRef;
@property (nonatomic, strong) YWTribe *tribe;

@end
