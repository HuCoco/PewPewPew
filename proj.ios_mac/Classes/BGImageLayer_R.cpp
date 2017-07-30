#include "BGImageLayer_R.h"
#include "GameConfig.h"

void authResultHandler(C2DXResponseState state, C2DXPlatType platType, __Dictionary *error)
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

void getUserResultHandler(C2DXResponseState state, C2DXPlatType platType, __Dictionary *userInfo, __Dictionary *error, __Dictionary *db)
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
            
            CCLog("key = %s", key -> getCString());
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

void shareResultHandler(C2DXResponseState state, C2DXPlatType platType, __Dictionary *shareInfo, __Dictionary *error)
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



BGImageLayer_R::BGImageLayer_R()
{
}


BGImageLayer_R::~BGImageLayer_R()
{
}

bool BGImageLayer_R::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size MyWinSize = Director::getInstance()->getVisibleSize();

    Sprite* BGImage = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
    BGImage->setPosition(MyWinSize.width / 2, MyWinSize.height / 2);
    this->addChild(BGImage);
	BGImage_One = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage_One->setPosition(Vec2(MyWinSize.width / 2, MyWinSize.height / 2));
	this->addChild(BGImage_One, 1);
	BGImage_Two =Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage_Two->setPosition(Vec2(MyWinSize.width / 2, MyWinSize.height / 2 * 3));
	this->addChild(BGImage_Two, 1);
	this->schedule(schedule_selector(BGImageLayer_R::BGIGo));


	//RankingList
	Sprite* RankingList = Sprite::createWithSpriteFrameName(RANKINGLIST_PNG);
	RankingList->setPosition(MyWinSize.width / 2, MyWinSize.height / 20 * 17);
	this->addChild(RankingList,2);
	//1st
	Sprite* First = Sprite::createWithSpriteFrameName(FIRST_PNG);
	First->setPosition(MyWinSize.width / 7, MyWinSize.height / 20 * 15);
	this->addChild(First,2);
	Sprite* ScorePart1 = Sprite::createWithSpriteFrameName(SCOREPART_PNG);
	ScorePart1->setPosition(MyWinSize.width / 7 * 5, MyWinSize.height / 20 * 15);
	this->addChild(ScorePart1,2);
	if (UserDefault::getInstance()->getIntegerForKey(FIRST_SCORE, 0) != 0 && UserDefault::getInstance()->getStringForKey(FIRST_PLANE,"")!="")
	{
		char ScoreString[20];
		sprintf(ScoreString, "%d", UserDefault::getInstance()->getIntegerForKey(FIRST_SCORE, 0));
		LabelBMFont* FirstScoreBMF = LabelBMFont::create(ScoreString, SG14_FNT);
		FirstScoreBMF->setPosition(ScorePart1->getPosition());
		this->addChild(FirstScoreBMF, 3);
		Sprite* FirstPlane = Sprite::createWithSpriteFrameName(UserDefault::getInstance()->getStringForKey(FIRST_PLANE));
		FirstPlane->setPosition(MyWinSize.width / 3, MyWinSize.height / 20 * 15-5);
		this->addChild(FirstPlane,3);
	}

	//2nd
	Sprite* Second = Sprite::createWithSpriteFrameName(SECOND_PNG);
 		Second->setPosition(MyWinSize.width / 7, MyWinSize.height / 20 * 12.5);
 		this->addChild(Second,2);
		Sprite* ScorePart2 = Sprite::createWithSpriteFrameName(SCOREPART_PNG);
 		ScorePart2->setPosition(MyWinSize.width / 7 * 5, MyWinSize.height / 20 * 12.5);
 		this->addChild(ScorePart2,2);
		if (UserDefault::getInstance()->getIntegerForKey(SECOND_SCORE, 0) != 0 && UserDefault::getInstance()->getStringForKey(SECOND_PLANE,"")!="")
 		{
 			char ScoreString[20];
 			sprintf(ScoreString, "%d", UserDefault::getInstance()->getIntegerForKey(SECOND_SCORE, 0));
 			LabelBMFont* SecondScoreBMF = LabelBMFont::create(ScoreString, SG14_FNT);
 			SecondScoreBMF->setPosition(ScorePart2->getPosition());
 			this->addChild(SecondScoreBMF, 3);
			Sprite* SecondPlane = Sprite::createWithSpriteFrameName(UserDefault::getInstance()->getStringForKey(SECOND_PLANE));
 			SecondPlane->setPosition(MyWinSize.width / 3, MyWinSize.height / 20 * 12.5 - 5);
 			this->addChild(SecondPlane, 3);
 		}
 		//3rd
		Sprite* Third = Sprite::createWithSpriteFrameName(THIRD_PNG);
 		Third->setPosition(MyWinSize.width / 7, MyWinSize.height / 20 * 10);
 		this->addChild(Third,2);
		Sprite* ScorePart3 = Sprite::createWithSpriteFrameName(SCOREPART_PNG);
 		ScorePart3->setPosition(MyWinSize.width / 7 * 5, MyWinSize.height / 20 * 10);
 		this->addChild(ScorePart3,2);
		if (UserDefault::getInstance()->getIntegerForKey(THIRD_SOCRE, 0) != 0 && UserDefault::getInstance()->getStringForKey(THIRD_PLANE,"")!="")
 		{
 			char ScoreString[20];
 			sprintf(ScoreString, "%d", UserDefault::getInstance()->getIntegerForKey(THIRD_SOCRE, 0));
 			LabelBMFont* ThirdScoreBMF = LabelBMFont::create(ScoreString, SG14_FNT);
 			ThirdScoreBMF->setPosition(ScorePart3->getPosition());
 			this->addChild(ThirdScoreBMF, 3);
			Sprite* ThirdPlane = Sprite::createWithSpriteFrameName(UserDefault::getInstance()->getStringForKey(THIRD_PLANE));
 			ThirdPlane->setPosition(MyWinSize.width / 3, MyWinSize.height / 20 * 10- 5);
 			this->addChild(ThirdPlane, 3);
 		}
 		//4th
		Sprite* Fourth = Sprite::createWithSpriteFrameName(FOURTH_PNG);
 		Fourth->setPosition(MyWinSize.width / 7, MyWinSize.height / 20 * 7.5);
 		this->addChild(Fourth,2);
		Sprite* ScorePart4 = Sprite::createWithSpriteFrameName(SCOREPART_PNG);
 		ScorePart4->setPosition(MyWinSize.width / 7 * 5, MyWinSize.height / 20 * 7.5);
 		this->addChild(ScorePart4,2);
		if (UserDefault::getInstance()->getIntegerForKey(FOURTH_SCORE, 0) != 0 && UserDefault::getInstance()->getStringForKey(SECOND_PLANE,"")!="")
 		{
 			char ScoreString[20];
 			sprintf(ScoreString, "%d", UserDefault::getInstance()->getIntegerForKey(FOURTH_SCORE, 0));
			LabelBMFont* FourthScoreBMF = LabelBMFont::create(ScoreString, SG14_FNT);
 			FourthScoreBMF->setPosition(ScorePart4->getPosition());
 			this->addChild(FourthScoreBMF, 3);
 			Sprite* FourthPlane = Sprite::createWithSpriteFrameName(UserDefault::getInstance()->getStringForKey(FOURTH_PLANE));
 			FourthPlane->setPosition(MyWinSize.width / 3, MyWinSize.height / 20 * 7.5 - 5);
 			this->addChild(FourthPlane, 3);
 		}
 		//5th
		Sprite* Fifth = Sprite::createWithSpriteFrameName(FIFTH_PNG);
 		Fifth->setPosition(MyWinSize.width / 7, MyWinSize.height / 20 * 5);
 		this->addChild(Fifth,2);
		Sprite* ScorePart5 = Sprite::createWithSpriteFrameName(SCOREPART_PNG);
 		ScorePart5->setPosition(MyWinSize.width / 7 * 5, MyWinSize.height / 20 * 5);
 		this->addChild(ScorePart5,2);
		if (UserDefault::getInstance()->getIntegerForKey(FIFTH_SCORE, 0) != 0 && UserDefault::getInstance()->getStringForKey(SECOND_PLANE,"")!="")
 		{
 			char ScoreString[20];
 			sprintf(ScoreString, "%d", UserDefault::getInstance()->getIntegerForKey(FIFTH_SCORE, 0));
 			LabelBMFont* FifthScoreBMF = LabelBMFont::create(ScoreString, SG14_FNT);
 			FifthScoreBMF->setPosition(ScorePart5->getPosition());
 			this->addChild(FifthScoreBMF, 3);
			Sprite* FifthPlane = Sprite::createWithSpriteFrameName(UserDefault::getInstance()->getStringForKey(FIFTH_PLANE));
 			FifthPlane->setPosition(MyWinSize.width / 3, MyWinSize.height / 20 * 5 - 5);
 			this->addChild(FifthPlane, 3);
 		}
 		//Shares
 		MenuItemSprite* ShareBtn = 
			MenuItemSprite::create(
			Sprite::createWithSpriteFrameName(SHARE_BTN),
			Sprite::createWithSpriteFrameName(Share_BTN_DOWN),
			NULL,
			this,
			menu_selector(BGImageLayer_R::Share));
 		ShareBtn->setPosition(MyWinSize.width / 2, MyWinSize.height / 20 * 2);
 		Menu* menu = Menu::create(ShareBtn, NULL);
 		menu->setPosition(0, 0);
 		this->addChild(menu,2);
	return true;
}
void BGImageLayer_R::BGIGo(float dt)
{
	if (BGImage_One != NULL && BGImage_Two != NULL)
	{
		Size visibleSize = Director::getInstance()->getVisibleSize();
		float p1 = BGImage_One->getPositionY() - 1;
		float p2 = BGImage_Two->getPositionY() - 1;
		BGImage_One->setPositionY(p1);
		BGImage_Two->setPositionY(p2);
		if (BGImage_One->getPositionY() < -visibleSize.height / 2)
			BGImage_One->setPositionY(visibleSize.height / 2 * 3);
		if (BGImage_Two->getPositionY() < -visibleSize.height / 2)
			BGImage_Two->setPositionY(visibleSize.height / 2 * 3);
	}
}

void BGImageLayer_R::screenShoot()
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

void BGImageLayer_R::Share(Ref* pSender)
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
    content -> setObject(String::create("ShareSDK"), "site");
    content -> setObject(String::create("http://mp3.mwap8.com/destdir/Music/2009/20090601/ZuiXuanMinZuFeng20090601119.mp3"), "musicUrl");
    content -> setObject(String::create("extInfo"), "extInfo"); //微信分享应用时传给应用的附加信息
    C2DXShareSDK::showShareMenu(NULL, content, cocos2d::Point(100, 100), C2DXMenuArrowDirectionLeft, shareResultHandler);
    //    C2DXShareSDK::showShareView(C2DXPlatTypeSinaWeibo, content, shareResultHandler);

}