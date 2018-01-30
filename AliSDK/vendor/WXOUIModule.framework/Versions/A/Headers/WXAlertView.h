//
//  WXAlertView.h
//  Messenger
//
//  Created by AKKun on 13-8-6.
//
//  https://github.com/expandtheroom/ETRAlertView

#import <UIKit/UIKit.h>

#define WXAlertViewCancelButtonIndex NSUIntegerMax

typedef enum
{
    WXAlertViewMaskTypeClear = 0,
    WXAlertViewMaskTypeBlack,
    WXAlertViewMaskTypeWhite,
    WXAlertViewMaskTypeGradient
}
WXAlertViewMaskType;

@class WXAlertView;

@protocol WXAlertViewDelegate <NSObject>

-(void)alertView:(WXAlertView *)alertView didSelectButtonAtIndex:(NSUInteger)index;

@end

@protocol WXAlertViewHeaderView <NSObject>

@property (nonatomic, strong) NSString *text;
@property (nonatomic, readonly) UILabel *textLabel;

@end

@protocol WXAlertViewTrunkView <NSObject>
@end

@protocol WXAlertViewTailView <NSObject>

@property (nonatomic, strong) UIButton *cancelButton;
@property (nonatomic, strong) NSArray *otherButtons;

@end

@interface WXAlertView : UIView

@property (nonatomic, readonly) UIView<WXAlertViewHeaderView> *headerView;
@property (nonatomic, readonly) UIView<WXAlertViewTailView> *tailView;
@property (nonatomic, readonly) UIView/*<WXAlertViewTrunkView>*/ *trunkView;
@property (nonatomic, readonly) UIButton *cancelButton;
@property (nonatomic, readonly) UIButton *otherButton;
@property (nonatomic, strong) NSDictionary *userInfo;
@property (nonatomic, weak) id<WXAlertViewDelegate>delegate;

+ (void)dismissAllAlertView;

// Common
- (void)showWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle;

- (void)showWithTitle:(NSString *)title
              message:(NSString *)message
             delegate:(id<WXAlertViewDelegate>)delegate
             maskType:(WXAlertViewMaskType)maskType
             userInfo:(NSDictionary *)userInfo
    cancelButtonTitle:(NSString *)cancelButtonTitle
    otherButtonTitles:(NSArray *)otherButtonTitles;

- (void)showWithTitle:(NSString *)title
              message:(NSString *)message
          clickAction:(void (^)(NSUInteger buttonIndex))clickAction
             maskType:(WXAlertViewMaskType)maskType
             userInfo:(NSDictionary *)userInfo
    cancelButtonTitle:(NSString *)cancelButtonTitle
    otherButtonTitles:(NSArray *)otherButtonTitles;

// Custom
- (void)showWithTitle:(NSString *)title
            trunkView:(UIView *)trunk
             delegate:(id<WXAlertViewDelegate>)delegate
             maskType:(WXAlertViewMaskType)maskType
             userInfo:(NSDictionary *)userInfo
    cancelButtonTitle:(NSString *)cancelButtonTitle
    otherButtonTitles:(NSArray *)otherButtonTitles;

- (void)showWithTitle:(NSString *)title
            trunkView:(UIView *)trunk
          clickAction:(void (^)(NSUInteger buttonIndex))clickAction
             maskType:(WXAlertViewMaskType)maskType
             userInfo:(NSDictionary *)userInfo
    cancelButtonTitle:(NSString *)cancelButtonTitle
    otherButtonTitles:(NSArray *)otherButtonTitles;

- (void)dismiss;

- (void)dismissAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

- (void)changeAlertOffset:(NSInteger)offset;//改变偏移量（> 0向下偏移，< 0向上偏移）

@end
