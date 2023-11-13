//
//  CTSessionManager.h
//  CleverTapSDK
//
//  Created by Akash Malhotra on 12/10/23.
//  Copyright © 2023 CleverTap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CleverTapInstanceConfig.h"
#import "CTInAppDisplayManager.h"
#import "CTImpressionManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface CTSessionManager : NSObject

@property (nonatomic, assign) long minSessionSeconds;
@property (atomic, assign) long sessionId;
@property (atomic, assign) int screenCount;
@property (atomic, assign) BOOL firstSession;
@property (atomic, assign) BOOL firstRequestInSession;
@property (atomic, assign) int lastSessionLengthSeconds;
@property (atomic, assign) BOOL appLaunchProcessed;

@property (atomic, retain, nullable) NSString *source;
@property (atomic, retain, nullable) NSString *medium;
@property (atomic, retain, nullable) NSString *campaign;
@property (atomic, retain, nullable) NSDictionary *wzrkParams;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithConfig:(CleverTapInstanceConfig *)config impressionManager:(CTImpressionManager *)impressionManager inAppStore:(CTInAppStore *)inAppStore;
- (void)updateSessionStateOnLaunch;
- (void)updateSessionTime:(long)ts;
- (void)createSessionIfNeeded;
- (void)resetSession;

@end

NS_ASSUME_NONNULL_END
