//
//  YWPickFriendViewController.h
//  WXOpenIMUIKit
//
//  Created by Chongyi on 16/7/6.
//  Copyright © 2016年 www.alibaba.com. All rights reserved.
//

#import <UIKit/UIKit.h>


@class YWSearchEngine;
@class YWIMKit;

#define kQueryKeyMembers                    @"kQueryKeyMembers"
#define kQueryValueMembers                  @"kQueryValueMembers"
#define kQueryKeyTribes                     @"kQueryKeyTribes"
#define SettingGetBatchWangWangUsersProfileEmpty    21

@protocol IYWPickerPersonModel <NSObject>
@property (nonatomic, copy) NSString * nickForYWPickerPerson;
@property (nonatomic, copy) NSString * searchName;
@property (nonatomic, copy) NSString * avatarUrlForUI;
@property (nonatomic, copy) NSString * itemId;

@optional
@property (nonatomic, assign) BOOL online;
@property (nonatomic, assign) BOOL isUpdateData;

/**
 *  搜索回调
 */
typedef BOOL (^YWPickerVCSearchBlock)(NSString * searchText);
@property (nonatomic, copy) YWPickerVCSearchBlock searchBlock;

- (NSString *)asyncFetchAvatorUrl:(id)userContext retBlock:(void (^)(NSString *url))retBlock;
@end


/////////////////////////////////////////////////////////////////////////////////

@interface YWPickerPersonTabItem : NSObject
@property (nonatomic, copy) NSString * title;
@property (nonatomic, copy) NSString * descriptions;
@property (nonatomic, assign) NSUInteger indexPos;
@property (nonatomic, strong) NSMutableArray * dataSource; //[{@"groupname":objArray}, ...]
@property (nonatomic, assign) BOOL isUpdateData;
@property (nonatomic, strong) YWSearchEngine * searchEngine;
@property (nonatomic, weak) YWIMKit *ywimkit;
/**
 *  获取数据回调
 */
typedef void (^YWPickerVCGetDataBlock)();
@property (nonatomic, copy) YWPickerVCGetDataBlock getDataBlock;

+ (YWPickerPersonTabItem *)initPickerModelWithTitle:(NSString *)title descriptions:(NSString *)descriptions indexPos:(NSUInteger)indexPos;
@end


/////////////////////////////////////////////////////////////////////////////////

@interface YWPFSectionModel : NSObject
@property (nonatomic, copy) NSString *sectionTitle;
// 是否是展开的
@property (nonatomic, assign) BOOL isExpanded;

@property (nonatomic, strong) NSMutableArray *cellModels;

@end


/////////////////////////////////////////////////////////////////////////////////

@class YWPickFriendViewController;
@protocol YWPickFriendViewCtlerDelegate <NSObject>
@optional
@property (nonatomic, strong) id userContext;

- (void)pickFriendViewCtler:(YWPickFriendViewController *)controller didFinishWithInfo:(NSDictionary *)info;
- (void)pickFriendViewCtlerDidCancel:(YWPickFriendViewController *)controller;

- (void)pickFriendViewCtlerUpdateData:(YWPickFriendViewController *)controller;

- (void)asyncOnlineSearchPerson:(YWPickFriendViewController *)controller keyWord:(NSString *)keyword;
@end


/////////////////////////////////////////////////////////////////////////////////

@interface YWPickFriendViewController : UIViewController<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) id<YWPickFriendViewCtlerDelegate> delegate;

@property (nonatomic, strong)IBOutlet UITableView* internalTableView;
@property (nonatomic, strong)IBOutlet UIScrollView* hScrollView;
@property (nonatomic, strong)IBOutlet UIView* memberView;
@property (nonatomic, strong)IBOutlet UIButton* doneBtn;
@property (nonatomic, strong) IBOutlet UILabel *labelNoData;
@property (nonatomic, strong) IBOutlet UISearchDisplayController * searchDisplayController;

@property (nonatomic, strong) NSMutableDictionary *selectedMembers;    // key:user_id  object:@name
@property (nonatomic, strong) NSMutableArray *segmentItems;
@property (nonatomic, assign) NSUInteger selectTabIndex;
@property (nonatomic, copy) NSString * navigationTitle;
@property (nonatomic, assign) NSUInteger selectMembersMaxCount;

@property (nonatomic, assign) BOOL bSingleSelect;
@property (nonatomic, assign) BOOL bSurportGroup;
@property (nonatomic, assign) BOOL enableSearchOnlineFeature;
@property (nonatomic, assign) BOOL enableIndexTitles;

@property (nonatomic, weak) YWIMKit *imkit;

- (instancetype)initWithIMKit:(YWIMKit *)aKit;
- (instancetype)initWithSegmentItems:(NSArray*)items;


- (BOOL)updateDataSourceWithIndex:(NSArray *)dataSource index:(NSUInteger)indexPos;

- (void)updateTabItemWithIndex:(YWPickerPersonTabItem *)tabItem index:(NSUInteger)indexPos;

- (void)filterGivenContacts:(NSArray *)selectContacts index:(NSUInteger)indexPos;

- (void)removeTabItem:(NSUInteger)indexPos;

- (void)didSearchBatchContactsProfile:(NSArray *)profileSnippetArray withError:(NSError *)error;
@end


/////////////////////////////////////////////////////////////////////////////////

@interface YWPickerFriendMemberSelView : UIControl
@property (nonatomic, strong) UIImageView* avatarView;
@property (nonatomic, strong) id<IYWPickerPersonModel> userModel;
@property (nonatomic, weak) YWPickFriendViewController * pickFriendVC;

- (void)updateWithWWPerson:(NSObject *)person;
@end