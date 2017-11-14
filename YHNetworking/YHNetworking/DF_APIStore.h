//
//  DF_APIStore.h
//  DouFuShop
//
//  Created by 王英辉 on 16/5/26.
//  Copyright © 2016年 王英辉. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AFNetworking/AFNetworking.h>
#import <YHExtension/Singleton.h>


/**
 请求类型
 */
typedef enum {
    kGET,
    kPOST
}kRequestType;


/**
 *  请求成功回调block
 *
 *  @param task           会话对象
 *  @param responseObject 请求对象
 */
typedef void(^success)(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject);

/**
 *  请求失败回调block
 *
 *  @param task           会话对象
 *  @param NSError 请求对象
 */
typedef void(^failure)(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error);

typedef void(^yhPublicSuccess)(NSURLSessionDataTask * _Nullable task, id _Nullable responseObject);
typedef void(^yhPublicFailure)(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error);

@interface DF_APIStore : NSObject

singleton_interface(DF_APIStore);

@property(nonatomic, strong) NSMutableDictionary *_Nonnull serviceStorage;
@property (nonatomic, strong) NSString * _Nullable token;
@property (nonatomic, strong) yhPublicSuccess _Nonnull publicSuccess;
@property (nonatomic, strong) yhPublicFailure _Nonnull publicFailure;

/**
 *  请求
 *
 *  @param type       请求类型
 *  @param URLString  urlString
 *  @param parameters 请求参数
 *  @param success    成功回调
 *  @param failres    失败回调
 */
- (void)requestType:(kRequestType)type url:(NSString * _Nullable )URLString
         parameters:( NSMutableDictionary *_Nullable )parameters success:(success _Nullable)success failure:(failure _Nullable)failres;

- (void)requestWithServiceId:(NSString * _Nullable)ServiceId RequestType:(kRequestType)type url:(NSString * _Nullable )URLString
                  parameters:( NSMutableDictionary *_Nullable )parameters success:(success _Nullable)success failure:(failure _Nullable)failres;

@end
