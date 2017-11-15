//
//  YHNetworkStatus.m
//  DouFuShop
//
//  Created by 王英辉 on 15/10/27.
//  Copyright © 2015年 book. All rights reserved.
//

#import "YHNetworkStatus.h"

@implementation YHNetworkStatus


#pragma mark 网络状态监测
-(void)checkNetworkStatus:(void (^)(NSInteger type)) callback {
    
    AFNetworkReachabilityManager *manager = [AFNetworkReachabilityManager sharedManager];
    //开始监控
    [manager startMonitoring];
    
    // 检测网络连接的单例,网络变化时的回调方法
    [manager setReachabilityStatusChangeBlock:^(AFNetworkReachabilityStatus status) {
        if (callback) {
            callback(status);
        }
        switch (status) {
            case AFNetworkReachabilityStatusUnknown:
            {
                //NSLog(@"网络无法连接");
            }
                break;
            case AFNetworkReachabilityStatusNotReachable:
            {
                //NSLog(@"网络无法连接");
            }
                break;
            case AFNetworkReachabilityStatusReachableViaWWAN:
            {
                //NSLog(@"2G/3G/4G 连接");
            }
                break;
            case AFNetworkReachabilityStatusReachableViaWiFi:
            {
                //NSLog(@"WiFi 连接");
            }
                break;
                
            default:
                break;
        }
        self.status = status;
    }];
}


@end
