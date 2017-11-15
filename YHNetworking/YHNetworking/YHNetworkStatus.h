//
//  YHNetworkStatus.h
//  DouFuShop
//
//  Created by 王英辉 on 15/10/27.
//  Copyright © 2015年 book. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworkReachabilityManager.h"

// 网络连接通知
@interface YHNetworkStatus : NSObject

/**
 *  监测网络状态
 */
- (void)checkNetworkStatus:(void (^)(NSInteger type)) callback;

/**
 *  -1:网络未知错误，0:网络错误，1:3G、4G连接，2:wifi连接
 */
@property (nonatomic,assign) AFNetworkReachabilityStatus status;

@end
