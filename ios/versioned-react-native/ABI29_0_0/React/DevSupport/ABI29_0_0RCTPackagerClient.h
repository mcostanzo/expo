/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ReactABI29_0_0/ABI29_0_0RCTDefines.h>

#if ABI29_0_0RCT_DEV // Only supported in dev mode

@class ABI29_0_0RCTPackagerClientResponder;
@class ABI29_0_0RCTReconnectingWebSocket;

#if defined(__cplusplus)
extern "C" {
#endif

extern const int ABI29_0_0RCT_PACKAGER_CLIENT_PROTOCOL_VERSION;

#if defined(__cplusplus)
}
#endif

@protocol ABI29_0_0RCTPackagerClientMethod <NSObject>

- (void)handleRequest:(NSDictionary<NSString *, id> *)params withResponder:(ABI29_0_0RCTPackagerClientResponder *)responder;
- (void)handleNotification:(NSDictionary<NSString *, id> *)params;

@optional

/** By default object will receive its methods on the main queue, unless this method is overriden. */
- (dispatch_queue_t)methodQueue;

@end

@interface ABI29_0_0RCTPackagerClientResponder : NSObject

- (instancetype)initWithId:(id)msgId socket:(ABI29_0_0RCTReconnectingWebSocket *)socket;
- (void)respondWithResult:(id)result;
- (void)respondWithError:(id)error;

@end

#endif
