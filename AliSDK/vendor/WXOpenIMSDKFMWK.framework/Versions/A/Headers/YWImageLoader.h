//
//  YWImageLoader.h
//  WXOpenIMSDK
//
//  Created by sidian on 15/12/13.
//  Copyright © 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^YWImageLoadBlock) (UIImage *image, NSData *data, CGFloat progress, NSError *error);

@interface YWImageLoader : NSObject

+ (id)sharedInstance;

- (UIImage *)getNativeCachesForUrl:(NSString *)url;

- (void)loadImageFromUrl:(NSString *)imageUrl withLoadBlock:(YWImageLoadBlock)loadBlock;

- (void)saveImage:(UIImage *)image forKey:(NSString *)url withFinishBlock:(void(^)(NSError *error, NSString *fileName))finishBlock;

@end


@interface YWImageLoader (Grayscale)

- (UIImage *)getNativeCachesForUrl:(NSString *)url grayscale:(BOOL)grayscale;
- (void)loadImageFromUrl:(NSString *)imageUrl grayscale:(BOOL)grayscale withLoadBlock:(YWImageLoadBlock)loadBlock;

@end