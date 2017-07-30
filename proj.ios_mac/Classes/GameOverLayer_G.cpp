#include "GameOverLayer_G.h"
#include "GameConfig.h"


void authResultHandlerGameOver(C2DXResponseState state, C2DXPlatType platType, __Dictionary *error)
{
    switch (state) {
        case C2DXResponseStateSuccess:
            C2DXShareSDK::toast("授权成功");
            break;
        case C2DXResponseStateFail:
            C2DXShareSDK::toast("授权失败");
            break;
        default:
            C2DXShareSDK::toast("授权取消");
            break;
    }
}

void getUserResultHandlerGameOver(C2DXResponseState state, C2DXPlatType platType, __Dictionary *userInfo, __Dictionary *error, __Dictionary *db)
{
    if (state == C2DXResponseStateSuccess)
    {
        //输出用户信息
        static __Array*allKeys = userInfo -> allKeys();
        allKeys->retain();
        for (int i = 0; i < allKeys -> count(); i++)
        {
            __String *key = (__String *)allKeys -> objectAtIndex(i);
            Ref *obj = userInfo -> objectForKey(key -> getCString());
            
            //CCLog("key = %s", key -> getCString());
            if (dynamic_cast<__String *>(obj))
            {
                //CCLog("value = %s", dynamic_cast<__String *>(obj) -> getCString());
            }
            else if (dynamic_cast<__Integer *>(obj))
            {
                //CCLog("value = %d", dynamic_cast<__Integer *>(obj) -> getValue());
            }
            else if (dynamic_cast<__Double *>(obj))
            {
                //CCLog("value = %f", dynamic_cast<__Double *>(obj) -> getValue());
            }
        }
        allKeys->release();
    }
}

void shareResultHandlerGameOver(C2DXResponseState state, C2DXPlatType platType, __Dictionary *shareInfo, __Dictionary *error)
{
    switch (state) {
        case C2DXResponseStateSuccess:
            C2DXShareSDK::toast("分享成功");
            break;
        case C2DXResponseStateFail:
            C2DXShareSDK::toast("分享失败");
            break;
        default:
            C2DXShareSDK::toast("分享取消");
            break;
    }
}


GameOverLayer_G::GameOverLayer_G()
{
}


GameOverLayer_G::~GameOverLayer_G()
{
    CloseInterstitialCallback();
}

bool GameOverLayer_G::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite* GameOver = Sprite::createWithSpriteFrameName(GAMEOVER_PNG);
	GameOver->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4 *3));
	this->addChild(GameOver);

	Sprite* ScoreBar = Sprite::createWithSpriteFrameName(SCORE_PNG);
	ScoreBar->setPosition(Vec2(visibleSize.width / 3, visibleSize.height /20 * 11));
	this->addChild(ScoreBar);
	Sprite* BestBar = Sprite::createWithSpriteFrameName(BEST_PNG);
	BestBar->setPosition(Vec2(visibleSize.width / 3, visibleSize.height /20 * 9));
	this->addChild(BestBar);

	MenuItemSprite* BackBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(TRYAGAIN_BTN),
		Sprite::createWithSpriteFrameName(TRYAGAIN_BTN_DOWN),
		NULL,
		this,
		menu_selector(HeadScene::FromGameSceneToHeadScene));
	Size BackBtnSize = BackBtn->getContentSize();
	BackBtn->setPosition(visibleSize.width / 2, visibleSize.height/4);
    
    MenuItemSprite* ShareBtn =
    MenuItemSprite::create(
                           Sprite::createWithSpriteFrameName(SHARE_BTN),
                           Sprite::createWithSpriteFrameName(Share_BTN_DOWN),
                           NULL,
                           this,
                           menu_selector(GameOverLayer_G::ShareScore));
    ShareBtn->setPosition(visibleSize.width/2, visibleSize.height/4 + BackBtn->getContentSize().height + 10);
    ShareBtn->setScale(0.7f);
	Menu* menu = Menu::create(BackBtn,ShareBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);
    
    showInterstitialCallback();

    
	return true;
}

void GameOverLayer_G:: requestInterstitialCallback(){
    char  mogoid[]="e3dfdc5ce7ae4e629926746bf86a17a0";
    AdsMogoInterstitial::sharedInterstitial()->loadInterstitial(mogoid,AdsMogoInterstitialTypeFullScreen,true);
}
void  GameOverLayer_G::showInterstitialCallback(){
    char  mogoid[]="e3dfdc5ce7ae4e629926746bf86a17a0";
    AdsMogoInterstitial::sharedInterstitial()->loadInterstitial(mogoid,AdsMogoInterstitialTypeFullScreen,true);
    AdsMogoInterstitial::sharedInterstitial()->showInterstitial();
}
void GameOverLayer_G:: CloseInterstitialCallback(){
    AdsMogoInterstitial::sharedInterstitial()->hideInterstitial();
}



void GameOverLayer_G::screenShoot()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //定义一个屏幕大小的渲染纹理
    RenderTexture* renderTexture = RenderTexture::create(visibleSize.width , visibleSize.height, Texture2D::PixelFormat::RGBA8888);
    
    Scene* curScene = Director::getInstance()->getRunningScene();
    
    //渲染纹理开始捕捉
    renderTexture->begin();
    
    
    
    //绘制当前场景
    curScene->visit();
    
    //结束
    renderTexture->end();
    
    //保存png
    renderTexture->saveToFile("screenshoot.png", Image::Format::PNG);
    
}

void GameOverLayer_G::ShareScore(Ref* pSender)
{

        screenShoot();
        __Dictionary *content = __Dictionary::create();
        //Dictionary可用的Key如下，如果需要用到其它字段，可自行参考Sample中的代码实现：
        // (并不是所有平台都有这些字段，需要参考文档http://wiki.mob.com/Android_%E4%B8%8D%E5%90%8C%E5%B9%B3%E5%8F%B0%E5%88%86%E4%BA%AB%E5%86%85%E5%AE%B9%E7%9A%84%E8%AF%A6%E7%BB%86%E8%AF%B4%E6%98%8E)
        std::string path =FileUtils::getInstance()->getWritablePath() + "screenshoot.png";
        content -> setObject(String::create("write what you want to share"), "content"); //要分享的内容，注意在文档中content对应的是text字段
        content -> setObject(String::create(path), "image"); //可以是本地路径（如：/sdcard/a.jpg）或是一个URL
        content -> setObject(String::create("for title"), "title");
        content -> setObject(String::create("测试描述"), "description");
        content -> setObject(String::create("http://sharesdk.cn"), "url");
        content -> setObject(String::createWithFormat("%d", C2DXContentTypeNews), "type");
        content -> setObject(String::create("http://sharesdk.cn"), "siteUrl");
        content -> setObject(String::create("Shar`  ``eSDK"), "site");
        content -> setObject(String::create("http://mp3.mwap8.com/destdir/Music/2009/20090601/ZuiXuanMinZuFeng20090601119.mp3"), "musicUrl");
        content -> setObject(String::create("extInfo"), "extInfo"); //微信分享应用时传给应用的附加信息
        C2DXShareSDK::showShareMenu(NULL, content, cocos2d::Point(100, 100), C2DXMenuArrowDirectionLeft, shareResultHandlerGameOver);
        //    C2DXShareSDK::showShareView(C2DXPlatTypeSinaWeibo, content, shareResultHandler);
    
}
