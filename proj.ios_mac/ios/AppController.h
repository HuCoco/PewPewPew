#import <UIKit/UIKit.h>
#import "AdMoGoSplashAds.h"
#import "AdMoGoSplashAdsDelegate.h"

@class RootViewController;

@interface AppController : NSObject <UIApplicationDelegate,AdMoGoSplashAdsDelegate> {
    UIWindow *window;
}

@property(nonatomic, readonly) RootViewController* viewController;

@end

