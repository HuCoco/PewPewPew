#include "HeadScene.h"
#include "PlaneChooseLayer.h"
bool HeadScene::GameState = true;
HeadScene::HeadScene()
{
}

HeadScene::~HeadScene()
{
}

bool HeadScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	if (GameState==true && MyAudio::getBGMState() == true)
	{
		MyAudio::PlayHeadSceneBGM();
	}
    cocos2d::UserDefault::getInstance()->setBoolForKey("AD_COIN", false);
	BGILayer_H* BGILayer = BGILayer_H::create();
	this->addChild(BGILayer, 1);
	MenuLayer_H* MenuLayer = MenuLayer_H::create();
	this->addChild(MenuLayer, 3);
	PlaneChooseLayer* PlaneLayer = PlaneChooseLayer::create();
	this->addChild(PlaneLayer, 2);
	GameState = false;

	
	return true;


}



void HeadScene::GotoHeadScene(Ref* pSender)
{
	HeadScene* scene = HeadScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);
}

void HeadScene::FromGameSceneToHeadScene(Ref* pSender)
{
	if (MenuLayer_O::getIsOn())
	{
		MyAudio::StopBGM();
		MyAudio::PlayHeadSceneBGM();
	}
	Director::getInstance()->resume();
	HeadScene* scene = HeadScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);
}


void HeadScene::Close(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

