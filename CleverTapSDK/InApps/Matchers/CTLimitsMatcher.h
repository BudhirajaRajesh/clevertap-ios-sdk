//
//  CTLimitsMatcher.h
//  CleverTapSDK
//
//  Created by Nikola Zagorchev on 2.09.23.
//  Copyright © 2023 CleverTap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTImpressionManager.h"
#import "CTLimitAdapter.h"

NS_ASSUME_NONNULL_BEGIN

@interface CTLimitsMatcher : NSObject

- (BOOL)matchWhenLimits:(NSArray *)whenLimits forCampaignId:(NSString *)campaignId withImpressionManager:(CTImpressionManager *)manager;

@end

NS_ASSUME_NONNULL_END
