#include "AppDelegate.h"
#include "HeadScene.h"
#include "LoadingScene.h"
#include "MobClickCpp.h"
#include "C2DXShareSDK.h"
USING_NS_CC;
using namespace cn::sharesdk;
AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    
    MOBCLICKCPP_START_WITH_APPKEY_AND_CHANNEL("54d03fe0fd98c5ae8500009b", "appstore");
    
    C2DXShareSDK::open("59f2dfe07cc1",false);
    
    //Twitter
    __Dictionary *twConfigDict = __Dictionary::create();
    twConfigDict -> setObject(String::create("mnTGqtXk0TYMXYTN7qUxg"), "consumer_key");
    twConfigDict -> setObject(String::create("ROkFqr8c3m1HXqS3rm3TJ0WkAJuwBOSaWhPbZ9Ojuc"), "consumer_secret");
    twConfigDict -> setObject(String::create("http://www.sharesdk.cn"), "redirect_uri");
    C2DXShareSDK::setPlatformConfig(C2DXPlatTypeTwitter, twConfigDict);
    
    //Google+
    __Dictionary *gpConfigDict = __Dictionary::create();
    gpConfigDict -> setObject(String::create("232554794995.apps.googleusercontent.com"), "client_id");
    gpConfigDict -> setObject(String::create("PEdFgtrMw97aCvf0joQj7EMk"), "client_secret");
    //gpConfigDict -> setObject(String::create("http://localhost"), "redirect_uri");
    gpConfigDict -> setObject(String::create("http://www.sharesdk.cn"), "redirect_uri");
    C2DXShareSDK::setPlatformConfig(C2DXPlatTypeGooglePlus, gpConfigDict);
    
    //Facebook
    __Dictionary *fbConfigDict = __Dictionary::create();
    fbConfigDict -> setObject(String::create("107704292745179"), "api_key");
    fbConfigDict -> setObject(String::create("38053202e1a5fe26c80c753071f0b573"), "app_secret");
    C2DXShareSDK::setPlatformConfig(C2DXPlatTypeFacebook, fbConfigDict);
    

    
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("PewPewPew");
		glview->setFrameSize(288,512);
		director->setOpenGLView(glview);
		
    }
	glview->setDesignResolutionSize(640, 1136, ResolutionPolicy::FIXED_WIDTH);
	UserDefault::getInstance()->setBoolForKey(IS_GET_BATTLECRUISER, true);
    /*UserDefault::getInstance()->setBoolForKey(IS_GET_BATTLECRUISER_S, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_BANSHEE, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_BANSHEE_S, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_PHOENIX, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_PHOENIX_S, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_VIKING, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_VIKING_S, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_VOIDRAY, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_VOIDRAY_S, true);
    UserDefault::getInstance()->setBoolForKey(IS_GET_TEMPEST, true);*/
    
    

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = LoadingScene::create();
	//auto scene = HelloWorld::createScene();
    // run
    director->runWithScene(scene);
	


    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    umeng::MobClickCpp::applicationDidEnterBackground();

    // if you use SimpleAudioEngine, it must be pausea
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    umeng::MobClickCpp::applicationWillEnterForeground();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
