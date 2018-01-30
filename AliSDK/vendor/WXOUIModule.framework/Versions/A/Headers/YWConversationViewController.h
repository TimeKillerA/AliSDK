//
//  WXOConversationViewController.h
//  testFreeOpenIM
//
//  Created by Jai Chen on 15/1/12.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "IYWUIServiceDef.h"

#import "YWMessageInputView.h"

@class YWConversation;
@protocol IYWMessage, YWIBAsset;
@class YWIMCore;
@class YWIMKit;
@class YWMoreActionItem;
@class YWMessageBodyCustomizeInternal;


/**
 *  自定义长按菜单项使用这个Key传递Controller
 */
FOUNDATION_EXTERN NSString *const YWConversationMessageCustomMenuItemUserInfoKeyController;
/**
 *  自定义长按菜单项使用这个Key传递MessageId
 */
FOUNDATION_EXTERN NSString *const YWConversationMessageCustomMenuItemUserInfoKeyMessageId;

/**
 *  某一个消息长按后弹出的菜单
 *  @return 返回的NSArray中包含的必须是 YWMoreActionItem 对象
 *  @note 当菜单项被点击时，会调用该菜单项的actionBlock，并且在UserInfo中使用 YWConversationMessageCustomMenuItemUserInfoKeyController 这个key传递当前的Controller
 */
typedef NSArray *(^YWConversationMessageCustomMenuItemsBlock)(id<IYWMessage> aMessage);

/**
 *  某一个消息长按后弹出的菜单
 *  @return 返回的NSArray中包含的必须是 YWMoreActionItem 对象
 *  @note 当菜单项被点击时，会调用该菜单项的actionBlock
 */
typedef NSArray *(^YWConversationMessageCustomMenuItemsBlockV2)(id<IYWMessage> aMessage, NSArray *defaultItems);

FOUNDATION_EXTERN NSString *const YWConversationViewActionIdentifyDelete; /// 删除


#pragma mark - UI自定义点的定义

/// * 自定义消息 Cell 的头像和显示名
/// * UserInfo中使用YWConvViewCustomCommonKeyMessage传递消息
/// * UserInfo中使用YWConvViewCustomCommonKeyConversationViewController传递controller
/// * UserInfo中使用YWUICustomizeUserInfoKeyAsyncBlock传递异步block，支持异步回调
FOUNDATION_EXTERN NSString *const YWConvViewCustomTypeCell;

/// 传递自定义的头像，类型为 UIImage *
FOUNDATION_EXTERN NSString *const YWConvViewCustomTypeCellAvatar;
/// 传递自定义的显示名，类型为 NSString *
FOUNDATION_EXTERN NSString *const YWConvViewCustomTypeCellDisplayName;
/// 传递是否需要在聊天气泡旁边显示时间，类型为 BOOL 生成的 NSNumber *
FOUNDATION_EXTERN NSString *const YWConvViewCustomTypeCellShowTimeBesideBubbleView;

/// 在UI自定义回调的UserInfo中，一般使用这个Key传递消息对象，类型为id<IYWMessage> *
FOUNDATION_EXTERN NSString *const YWConvViewCustomCommonKeyMessage;
/// 在UI自定义回调的UserInfo中，默认使用这个Key传递会话列表Controller，类型为YWConversationViewController *
FOUNDATION_EXTERN NSString *const YWConvViewCustomCommonKeyConversationViewController;


@interface YWConversationViewController : UIViewController
<UITableViewDataSource, UITableViewDelegate,
YWViewControllerEventProtocol,
YWMessageInputViewDelegate>


/**
 *  创建消息列表Controller
 *  @param aIMKit IMKit对象
 *  @param aConversation 会话对象
 */
+ (instancetype)makeControllerWithIMKit:(YWIMKit *)aIMKit conversation:(YWConversation *)aConversation;

/**
 *  YWIMKit对象的弱引用
 */
@property (nonatomic, weak, readonly)   YWIMKit *kitRef;

/**
 *  会话对象
 */
@property (nonatomic, strong, readonly) YWConversation *conversation;

/**
 *  加载更多消息
 *
 *  @param moreCount 期望加载更多消息的额外条数
 */
- (void)loadMoreMessages:(NSUInteger)moreCount;

#pragma mark - for CustomUI

/// 输入框
@property (nonatomic, strong) UIView<IYWMessageInputView> *messageInputView;

// 设置输入框隐藏
- (void)setMessageInputViewHidden:(BOOL)hidden animated:(BOOL)animated;

// 承载消息的 TableView
@property (nonatomic, strong, readonly) UITableView *tableView;

/// 顶部自定义View
@property (nonatomic, strong) UIView *customTopView;


/**
 * 设置顶部自定义View及其显示和隐藏View
 * @param customTopView, 顶部自定义View
 * @param hideView, 可选，显示在customTopView下方，用户点击会触发收起customTopView，若为nil，customTopView将会一直显示
 * @param showView, 可选，用户点击展开customTopView，若为nil且hideView不为nil，则会使用hideView
 */
- (void)setCustomTopView:(UIView *)customTopView withOptionHideView:(UIView *)hideView andOptionShowView:(UIView *)showView;

/// 通过接口设置背景图片
@property (nonatomic, strong) UIImage *backgroundImage;


/**
 *  某一个消息长按后弹出的菜单
 *  @return 返回的NSArray中包含的必须是 YWMoreActionItem 对象
 */
@property (nonatomic, copy, readwrite) YWConversationMessageCustomMenuItemsBlock messageCustomMenuItemsBlock;
@property (nonatomic, copy, readwrite) YWConversationMessageCustomMenuItemsBlockV2 messageCustomMenuItemsBlockV2;


/**
 *  合并聊天气泡点击后，sdk会构建一个专门用于展示合并聊天消息的页面controller，通过这个block传递controller和点击事件
 *  @return 合并聊天详情会话vc对象
 */
typedef void(^YWCombineChatBubbleClickedBlock)(YWConversationViewController *);
@property (nonatomic, copy, readwrite) YWCombineChatBubbleClickedBlock combineChatBubbleClickedBlock;


/**
 *  某一个消息长按后弹出的菜单
 *  @return 返回的NSArray中包含的必须是 YWMoreActionItem 对象
 */
- (void)setMessageCustomMenuItemsBlock:(YWConversationMessageCustomMenuItemsBlock)messageCustomMenuItemsBlock;

#pragma mark - 消息发送
/**
 *  文本发送
 */
- (void)sendTextMessage:(NSString *)text;

@property (nonatomic, copy) YWShouldSendTextBlock shouldSendTextBlock;

/*
 * 图片发送 包含图片上传交互
 *
 * @param image, 要发送的图片
 */
- (void)sendImageMessage:(UIImage *)image;

- (void)sendImageAsset:(id<YWIBAsset>)asset withOriginData:(BOOL)origin;
- (void)sendImageAsset:(id<YWIBAsset>)asset withOriginData:(BOOL)origin controlParameters:(NSDictionary *)controlParameters;

- (void)sendImageMessage:(UIImage *)image
       controlParameters:(NSDictionary *)controlParameters
           progressBlock:(YWMessageSendingProgressBlock)aProgressBlock
         completionBlock:(YWMessageSendingCompletionBlock)aCompletionBlock;

/**
 *  图片发送 包含图片上传交互
 *
 *  @param image         待发送图片
 *  @param shouldConfirm 如果为 YES，则需要用户确认才会发送
 */
- (void)sendImageMessage:(UIImage *)image shouldAskUserToConfirm:(BOOL)shouldConfirm;

- (void)sendImageMessageData:(NSData *)ImageData;

/**
 *  视频发送 包含视频上传交互
 *
 *  @param videoUrl                     待发送视频，可为本地file://地址，也为http地址
 *  @param size                         视频字节数
 *  @param frontImage                   封面图片
 *  @param frontImageUrl                封面图片，可为本地file://地址，也为http地址
 *  @param width                        视频宽度
 *  @param height                       视频高度
 *  @param duration                     视频时长
 */
- (void)sendVideoMessage:(NSURL *)videoUrl videoSize:(NSUInteger)size frontImage:(UIImage *)frontImage width:(NSUInteger)width height:(NSUInteger)height duration:(NSUInteger)duration;

- (void)sendVideoMessage:(NSURL *)videoUrl videoSize:(NSUInteger)size frontImageUrl:(NSURL *)frontImageUrl width:(NSUInteger)width height:(NSUInteger)height duration:(NSUInteger)duration;


/// 语音发送
- (void)sendVoiceMessage:(NSData*)wavData andTime:(NSTimeInterval)nRecordingTime;

/*
 * C端用户当前正在浏览的宝贝id，OpenIM完成数据从C端传递到B端展现的打通，开发者可以通过宝贝id展现宝贝详细信息，具体参考http://baichuan.taobao.com/doc2/detail?spm=0.0.0.0.aEXBLc&treeId=41&articleId=103769&docType=1#s1
 * @param itemId, 宝贝Id
 */
- (void)sendTradeItemMessage:(NSString *)itemId;

/*
 * C端用户交易焦点信息，OpenIM完成数据从C端传递到B端展现的打通，开发者可以通过宝贝id展现宝贝详细信息，具体参考http://baichuan.taobao.com/doc2/detail?spm=0.0.0.0.aEXBLc&treeId=41&articleId=103769&docType=1#s1
 * @param tradeId, 交易Id
 */
- (void)sendTradeInfoMessage:(NSString *)tradeId;

/**
 *  发送用户的当前输入状态
 *
 *  @param status 详情见 YWConversationInputStatus 枚举
 */
- (void)sendInputStatus:(YWConversationInputStatus)status;

@end

@interface YWConversationViewController ()

/**
 *  在没有数据时显示该view，占据Controller的View整个页面
 */
@property (nonatomic, strong) UIView *viewForNoData;


/**
 *  会话失效的处理 block，如当群被解散或当前用户不再属于该会话时，对应会话会失效应当被删除并且关闭聊天窗口
 */
- (void)setConversationInvalidedHandler:(void (^)(NSError *))conversationInvalidedHandler;

@end



@interface YWConversationViewController()

/**
 *  是否禁止导航栏标题的自动设置，默认为NO;
 *  默认情况下在单聊界面导航栏显示在线状态和输入状态，如果您想自定义聊天界面的标题，请置为YES，
 *  注意这里只是UI显示控制，如果需要真实在线状态，请将IMCore层中IYWContactService中的enableContactOnlineStatus置为YES。
 */
@property (nonatomic, assign) BOOL disableTitleAutoConfig;

/**
 *  顶部导航栏标题不显示在线状态
 */
@property (nonatomic, assign) BOOL disableTitleOnlineDisplay;

/**
 *  是否禁用文字的双击放大功能，默认为NO
 */
@property (nonatomic, assign) BOOL disableTextShowInFullScreen;

/**
 *  禁用群聊中显示发送者的昵称
 */
@property (nonatomic, assign) BOOL disablePersonTribeNick;

/**
 *  控制消息是否显示发送者的昵称
 */
@property (nonatomic, copy) BOOL (^shouldShowNickForMessageBlock)(id<IYWMessage> message);

/**
 *  禁用聊天窗口中显示接收方消息已读未读标记，默认为NO
 */
@property (nonatomic, assign) BOOL disableReceiverReadFlag;

/// 设置cell头像点击回调
@property (nonatomic, copy) void (^avatarPressedBlock)(id<IYWMessage> message, YWConversationViewController *viewController);

/**
 *  UI自定义的回调对象
 *  支持自定义的点统一在底部定义
 */
@property (nonatomic, weak, readwrite) id<YWUICustomizeProtocol> customizeDelegate;

@end

@interface YWConversationViewController(TribeAtFeature)

@property (nonatomic, readonly, strong) NSArray<YWPerson *>* selectedAtMembers;

- (void)setSelectedAtMembers:(NSArray<YWPerson *> *)selectedAtMembers atAll:(BOOL)atAll;

@end



#pragma mark - 菜单项相关工具函数


@interface YWConversationViewController ()

/// SDK提供的消息长按菜单项：时间显示控制菜单
- (YWMoreActionItem *)fetchLongPressItemForTimeControl;
/// 时间显示菜单项
@property (nonatomic, assign) BOOL shouldShowTimeBesideBubbleView;

/// SDK提供的消息长按菜单项：“更多”菜单，点击后会进入多选模式(编辑模式)
- (YWMoreActionItem *)fetchLongPressItemForEditMode;



/// 开启或者关闭消息TableView多选模式
@property (nonatomic, assign) BOOL editingFlag;


/**
 *  用于获取消息多选模式下的菜单项
 *  @brief 当某个菜单项被选中时，SDK会通过 YWMoreActionBlock 中的 aUserInfo 参数，传递相关信息，具体的key值定义见下面
 *  @return 你需要返回正确构建的菜单项
 */
typedef NSArray<YWMoreActionItem *> *(^YWCVCEditModeActionsBlock)(YWConversationViewController *aFromController);
/// 如果进入多选模式，则SDK会调用这个block来获取多选模式的底部菜单
@property (nonatomic, copy) YWCVCEditModeActionsBlock editModeActionsBlock;

/// 被选中的消息
FOUNDATION_EXTERN NSString *const YWCVCEditModeActionsUserInfoKeySelectedMessages;

/// SDK提供的多选模式底部菜单:"删除"菜单, 点击后会删除选中的消息
- (YWMoreActionItem *)fetchEditModeItemForDelete;
/// SDK提供的多选模式底部菜单:"转发"菜单, 点击后会显示进入转发逻辑
- (YWMoreActionItem *)fetchEditModeItemForForward;

/// 多选消息后，点击合并转发后的回调
typedef void(^YWCVCEditModeMergeForwardBlock)(YWMessageBodyCustomizeInternal *aMergedBody, YWConversationViewController *aFromController);
@property (nonatomic, copy) YWCVCEditModeMergeForwardBlock mergeForwardBlock;

/// 多选消息后，点击逐条转发后的回调
typedef void(^YWCVCEditModeRespectivelyForwardBlock)(NSArray< id<IYWMessage> > *aMessages, YWConversationViewController *aFromController);
@property (nonatomic, copy) YWCVCEditModeRespectivelyForwardBlock respectivelyForwardBlock;

@end


