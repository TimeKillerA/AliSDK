//
//  WXOConversationListViewController.h
//  TAEDemo
//
//  Created by Jai Chen on 14/12/24.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "IYWUIServiceDef.h"
#import "YWConversationCell.h"

@class YWConversation;
@class YWIMCore;
@class YWIMKit;
@class YWFetchedResultsController;
@class YWPredicate;


@interface YWConversationListViewController : UITableViewController
<YWViewControllerEventProtocol>

/**
 *  创建一个会话列表Controller
 *  @param aIMKit kit对象
 */
+ (instancetype)makeControllerWithIMKit:(YWIMKit *)aIMKit;

/**
 *  IMKit对象的弱引用
 */
@property (nonatomic, weak, readonly) YWIMKit *kitRef;


/**
 *  UI自定义的回调对象
 *  支持自定义的点统一在底部定义
 */
@property (nonatomic, weak, readwrite) id<YWUICustomizeProtocol> customizeDelegate;

#pragma mark -


@end


#pragma mark -

@interface YWConversationListViewController ()

/**
 *  在没有数据时显示该view，占据Controller的View整个页面
 */
@property (nonatomic, strong) UIView *viewForNoData;

@end

#pragma mark -

@interface YWConversationListViewController (YWSearchSupport)

/**
 *  与会话列表关联的 UISearchBar
 */
@property(nonatomic, readonly, strong) UISearchBar *searchBar;

@end

@interface YWConversationListViewController ()

/**
 *  内部数据源
 */
@property (nonatomic, readonly) YWFetchedResultsController *ywFRC;

/**
 *  修改数据源条件
 *  目前该接口仅支持阿里二方应用
 */
@property (nonatomic, readwrite) YWPredicate *predicate;

@end

#pragma mark - UI自定义点的定义



/// * 选中某个会话，无需返回值
/// * UserInfo中使用YWConvListCustomCommonKeyConversation传递会话
/// * UserInfo中使用YWConvListCustomCommonKeyConversationListController传递controller
/// * UserInfo中使用YWConvListCustomCommonKeyIndexPath传递被点击的NSIndexPath *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDidSelectItem;

/// * 删除某个会话，无需返回值
/// * UserInfo中使用YWConvListCustomCommonKeyConversation传递会话
/// * UserInfo中使用YWConvListCustomCommonKeyConversationListController传递controller
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDidDeleteItem;

/// * 自定义会话列表提供的默认cell上各个控件，例如头像、昵称、描述，未读数等，详细见下面YWConvListCustomTypeDefaultCellKey系列的定义
/// * UserInfo中使用YWConvListCustomCommonKeyConversation传递会话
/// * UserInfo中使用YWConvListCustomCommonKeyConversationListController传递controller
/// * UserInfo中使用YWUICustomizeUserInfoKeyAsyncBlock传递异步block，支持异步回调
/// * UserInfo中使用YWConvListCustomTypeDefaultCellKeySubtitleActions传递默认的SubtitleActions
/// * 返回结果中包含各个自定义的点以及对应的值
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCell;

/// 自定义默认cell时，传递自定义的头像，类型为UIImage *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCellKeyImage;
/// 自定义默认cell时，传递自定义的Title，类型为NSString *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCellKeyTitle;
/// 自定义默认cell时，传递自定义的Subtitle，类型为NSAttributedString *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCellKeySubtitle;
/// 自定义默认cell时，传递自定义的Date，类型为NSDate *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCellKeyDate;
/// 自定义默认cell时，传递自定义的UnreadCount，类型为NSString *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCellKeyUnreadCount;
/// 自定义默认cell时，传递自定义的UnreadType，类型为NSNumber *，内部数值类型为YWConversationCellBadgeType
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCellKeyUnreadType;
/// 自定义默认cell时，传递自定义的TitleActions，类型为NSArray<YWMoreActionItem *> *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCellKeyTitleActions;
/// 自定义默认cell时，传递自定义的SubtitleActions，类型为NSArray<YWMoreActionItem *> *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeDefaultCellKeySubtitleActions;

/// * 为某个会话提供完全自定义的Cell；返回nil为不自定义
/// * UserInfo中使用YWConvListCustomCommonKeyConversation传递会话
/// * UserInfo中使用YWConvListCustomCommonKeyConversationListController传递controller
/// * UserInfo中使用YWConvListCustomCommonKeyIndexPath传递IndexPath
/// * UserInfo中使用YWConvListCustomCommonKeyTableView传递TableView
/// * 返回值中使用YWConvListCustomCommonKeyCell返回你提供的Cell
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeCustomCell;

/// * 为某个会话提供自定义的Cell高度；返回nil为不自定义
/// * UserInfo中使用YWConvListCustomCommonKeyConversation传递会话
/// * UserInfo中使用YWConvListCustomCommonKeyConversationListController传递controller
/// * UserInfo中使用YWConvListCustomCommonKeyIndexPath传递IndexPath
/// * UserInfo中使用YWConvListCustomCommonKeyTableView传递TableView
/// * 返回值中使用YWConvListCustomTypeCustomCellHeight为键值，传递Cell高度，类型为NSNumber *
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeCustomCellHeight;


/// * 自由配置某个会话的Cell，可以添加子View等，无需返回值
/// * UserInfo中使用YWConvListCustomCommonKeyConversation传递会话
/// * UserInfo中使用YWConvListCustomCommonKeyConversationListController传递controller
/// * UserInfo中使用YWConvListCustomCommonKeyIndexPath传递IndexPath
/// * UserInfo中使用YWConvListCustomCommonKeyTableView传递TableView
/// * UserInfo中使用YWConvListCustomCommonKeyCell传递Cell
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeConfigCell;

/// * 为某个会话的cell提供自定义的左滑菜单
/// * UserInfo中使用YWConvListCustomCommonKeyConversation传递会话
/// * UserInfo中使用YWConvListCustomCommonKeyConversationListController传递controller
/// * UserInfo中使用YWConvListCustomCommonKeyIndexPath传递IndexPath
/// * UserInfo中使用YWConvListCustomCommonKeyTableView传递TableView
/// * UserInfo中使用YWConvListCustomTypeCustomEditActions传递默认Action，类型为:NSArray<YWMoreActionItem> *
/// * 返回值中使用YWConvListCustomTypeEditActions传递新的Action，类型为:NSArray<YWMoreActionItem> *。如果需要为空，则要返回空数组。
FOUNDATION_EXTERN NSString *const YWConvListCustomTypeEditActions;
/// 默认左滑菜单项的Identify定义，默认提供的action使用如下这些Identify识别
FOUNDATION_EXTERN NSString *const YWConversationEditActionIdentifyForDelete; /// 删除
FOUNDATION_EXTERN NSString *const YWConversationEditActionIdentifyForMarkOnTop; /// 置顶或者取消置顶





/// 在UI自定义回调的UserInfo中，一般使用这个Key传递Conversation对象，类型为YWConversation *
FOUNDATION_EXTERN NSString *const YWConvListCustomCommonKeyConversation;
/// 在UI自定义回调的UserInfo中，默认使用这个Key传递会话列表Controller，类型为YWConversationListViewController *
FOUNDATION_EXTERN NSString *const YWConvListCustomCommonKeyConversationListController;
/// 在UI自定义回调的UserInfo中，默认使用这个Key传递Cell，类型为UITableViewCell *
FOUNDATION_EXTERN NSString *const YWConvListCustomCommonKeyCell;
/// 在UI自定义回调的UserInfo中，默认使用这个Key传递IndexPath，类型为NSIndexPath *
FOUNDATION_EXTERN NSString *const YWConvListCustomCommonKeyIndexPath;
/// 在UI自定义回调的UserInfo中，默认使用这个Key传递TableView，类型为UITableView *
FOUNDATION_EXTERN NSString *const YWConvListCustomCommonKeyTableView;











































#pragma mark - old APIs

@interface YWConversationListViewController ()

///设置选中某个会话后的回调
typedef void(^YWConversationsListDidSelectItemBlock)(YWConversation *aConversation);
@property (nonatomic, copy) YWConversationsListDidSelectItemBlock didSelectItemBlock;
- (void)setDidSelectItemBlock:(YWConversationsListDidSelectItemBlock)didSelectItemBlock;

/// 删除某个会话后的回调
typedef void(^YWConversationsListDidDeleteItemBlock)(YWConversation *aConversation);
@property (nonatomic, copy) YWConversationsListDidDeleteItemBlock didDeleteItemBlock;
- (void)setDidDeleteItemBlock:(YWConversationsListDidSelectItemBlock)didDeleteItemBlock;

/**
 *  设置某个会话的最近消息内容后的回调
 *  @param aConversation 需要设置最近消息内容的会话
 *  @return 无需自定义最近消息内容返回nil
 */
typedef NSString *(^YWConversationsLatestMessageContent)(YWConversation *aConversation);
@property (nonatomic, copy) YWConversationsLatestMessageContent latestMessageContentBlock;
- (void)setLatestMessageContentBlock:(YWConversationsLatestMessageContent)latestMessageContentBlock;

/*
 *  会话左滑菜单设置block
 *  @ret,   需要显示的菜单数组
 *  @param, aConversation, 会话
 *  @param, editActions, 默认的菜单数组，成员为YWMoreActionItem类型
 */
typedef NSArray *(^YWConversationEditActionsBlock)(YWConversation *aConversation, NSArray *editActions);
@property (nonatomic, copy) YWConversationEditActionsBlock conversationEditActionBlock;
- (void)setConversationEditActionBlock:(YWConversationEditActionsBlock)conversationEditActionBlock;


/// 提供自定义行高的 Block，其中 tableView 和 indexPath 可能为搜索列表的对象
@property (nonatomic, copy) CGFloat (^heightForRowBlock) (UITableView *tableView, NSIndexPath *indexPath, YWConversation *conversation);

/// 会话列表 Cell 的默认高度
FOUNDATION_EXTERN const CGFloat YWConversationListCellDefaultHeight;

/// 提供自定义 Cell 的 Block，如果返回为 nil 则使用默认 Cell
/// 当使用自定义的 Cell 时，内部将不会处理 Cell，需要使用 configureCellBlock 自行配制 Cell
@property (nonatomic, copy) UITableViewCell* (^cellForRowBlock)(UITableView *tableView, NSIndexPath *indexPath, YWConversation *conversation);

/// 配置 Cell 的 Block，当默认的 Cell 或自定义的 Cell 需要配置时，该 block 将被调用
@property (nonatomic, copy) void (^configureCellBlock) (UITableViewCell *cell, UITableView *tableView, NSIndexPath *indexPath, YWConversation *conversation);

/// 设置cell头像点击回调
typedef void (^YWConversationListAvatarPressedBlock)(YWConversation *aConversation, YWConversationListViewController *aController);
@property (nonatomic, copy) YWConversationListAvatarPressedBlock avatarPressedBlock;
- (void)setAvatarPressedBlock:(YWConversationListAvatarPressedBlock)avatarPressedBlock;


@end
