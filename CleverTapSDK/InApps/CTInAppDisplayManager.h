//
//  CTInAppDisplayManager.h
//  CleverTapSDK
//
//  Created by Nikola Zagorchev on 3.10.23.
//  Copyright © 2023 CleverTap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CleverTapInAppNotificationDelegate.h"
#import "CTInAppFCManager.h"
#import "CTDeviceInfo.h"
#import "CleverTap.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CleverTapInAppRenderingStatus) {
    CleverTapInAppSuspend,
    CleverTapInAppDiscard,
    CleverTapInAppResume,
};

@interface CTInAppDisplayManager : NSObject

@property (atomic, weak) id <CleverTapInAppNotificationDelegate> _Nullable inAppNotificationDelegate;
@property (nonatomic, assign, readonly) CleverTapInAppRenderingStatus inAppRenderingStatus;

- (instancetype _Nonnull)initWithCleverTap:(CleverTap* _Nonnull)instance
                             deviceInfo:(CTDeviceInfo* _Nonnull)deviceInfo
                            inAppFCManager:(CTInAppFCManager* _Nonnull)inAppFCManager;

- (void)prepareNotificationForDisplay:(NSDictionary* _Nonnull)jsonObj;
- (BOOL)didHandleInAppTestFromPushNotificaton:(NSDictionary* _Nullable)notification;
- (void)clearInApps;

- (void)_addInAppNotificationsToQueue:(NSArray *)inappNotifs;
- (void)_showNotificationIfAvailable;
- (void)_suspendInAppNotifications;
- (void)_discardInAppNotifications;
- (void)_resumeInAppNotifications;
- (void)_showInAppNotificationIfAny;

@end

NS_ASSUME_NONNULL_END
