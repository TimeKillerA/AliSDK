//
//  YWTribeJoinViewController.h
//  Messenger
//
//  Created by Jai Chen on 15/11/13.
//
//

#import "YWTextFieldEditViewController.h"

@class YWIMKit;

@interface YWTribeJoinViewController : YWTextFieldEditViewController

+ (instancetype)instantiateViewControllerWithYWIMKit:(YWIMKit *)imKit;

@property (strong, nonatomic) NSString *tribeId;
@property (weak, nonatomic) YWIMKit *kitRef;

@end
