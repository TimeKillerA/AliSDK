//
//  IYWDBModel.h
//  WXOpenIMSDK
//
//  Created by huanglei on 16/8/18.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YWFetchedResultsController;

@protocol IYWDBModel <NSObject>

- (NSArray *)ywFetchResult;

- (YWFetchedResultsController *)ywFetchedResultsController;

@end
