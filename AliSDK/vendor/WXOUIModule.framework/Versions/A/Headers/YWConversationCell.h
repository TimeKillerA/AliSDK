//
//  YWConversationCell.h
//  WXOpenIMUIKit
//
//  Created by Jai Chen on 16/1/7.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, YWConversationCellBadgeType) {
    YWConversationCellBadgeTypeText,        // 显示未读数的具体文本
    YWConversationCellBadgeTypeRedDot,      // 显示为红点
};

@interface YWConversationCell : UITableViewCell

/**
 *  当作 UITableViewCell 的 contentView 使用
 */
@property (nonatomic, weak, readonly) UIScrollView *contentScrollView;

/**
 *  头像的尺寸，默认值 (46, 46)
 */
@property (nonatomic, assign) CGSize avatarImageViewSize UI_APPEARANCE_SELECTOR;


/**
 *  头像的圆角，未设置时使用 -[YWIMKit setAvatarImageViewCornerRadius:] 的值
 */
@property (nonatomic, assign) CGFloat avatarCornerRadius UI_APPEARANCE_SELECTOR;

/**
 *  头像视图的布局 margin，默认值 (8, 14, 0, 11)
 */
@property (nonatomic, assign) UIEdgeInsets avatarImageViewMargin UI_APPEARANCE_SELECTOR;

/// 设置未读数以及显示类型
- (void)setBadgeValue:(NSString *)aBadgeValue badgeType:(YWConversationCellBadgeType)aBadgeType;

/**
 *  未读数视图的 frame.origin ，默认值 (55, 13)
 */
@property (nonatomic, assign) CGPoint badgeViewCenter UI_APPEARANCE_SELECTOR;

/**
 *  名称 Label 的 margin，默认值 (9, 0, 0, 0)
 */
@property (nonatomic, assign) UIEdgeInsets nameLabelMargin UI_APPEARANCE_SELECTOR;

/**
 *  时间 Label 的布局 margin，默认值 (8, 0, 0, 15)
 */
@property (nonatomic, assign) UIEdgeInsets timeLabelMargin UI_APPEARANCE_SELECTOR;

/**
 *  最近消息内容 Label 的布局 margin，默认值 (7, 0, 0, 15)
 */
@property (nonatomic, assign) UIEdgeInsets contentLabelMargin UI_APPEARANCE_SELECTOR;

/**
 *  底部分割线布局 margin，默认值 (0, 71, 0, 0)
 */
@property (nonatomic, assign) UIEdgeInsets bottomSeparatorInset UI_APPEARANCE_SELECTOR;


@end
