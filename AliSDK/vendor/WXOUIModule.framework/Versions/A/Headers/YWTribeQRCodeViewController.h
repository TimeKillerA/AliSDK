//
//  YWTribeQRCodeViewController.h
//  WXOpenIMSampleDev
//
//  Created by Jai Chen on 15/10/23.
//  Copyright © 2015年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WXOpenIMSDKFMWK/YWFMWK.h>

@interface YWTribeQRCodeViewController : UIViewController

@property (nonatomic, weak) YWIMKit *kitRef;
@property (nonatomic, strong) YWTribe *tribe;


/**
 *  群头像 image view
 */
@property (weak, nonatomic) IBOutlet UIImageView *avatarImageView;

/**
 *  群名称 label
 */
@property (weak, nonatomic) IBOutlet UILabel *tribeNameLabel;

/**
 *  群 ID label
 */
@property (weak, nonatomic) IBOutlet UILabel *tribeIDLabel;

/**
 *  二维码 image view
 */
@property (weak, nonatomic) IBOutlet UIImageView *qrCodeImageView;

/**
 *  二维码底部辅助说明 label
 */
@property (weak, nonatomic) IBOutlet UILabel *tipLabel;

/**
 *  卡片
 */
@property (weak, nonatomic) IBOutlet UIView *contentView;

/**
 *  二维码上方的分割线
 */
@property (weak, nonatomic) IBOutlet UIImageView *separator;
@end
