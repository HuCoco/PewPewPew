#include "LoadingScene.h"
#include "GameConfig.h"
#include "HeadScene.h"


int LoadingScene::LoadingNum = 0;
LoadingScene::LoadingScene()
{

}

LoadingScene::~LoadingScene()
{

}


bool LoadingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	Director::getInstance()->getTextureCache()->addImageAsync("AllRes.png", CC_CALLBACK_1(LoadingScene::AllResCallback, this));
	this->scheduleOnce(schedule_selector(LoadingScene::LoadingComplete),5);
	return true;
}

void LoadingScene::AllResCallback(Texture2D* texture)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("AllRes.plist", texture);
	LoadingNum++;
}

void LoadingScene::LoadingComplete(float dt)
{
		MyAudio::PlayHeadSceneBGM();
		HeadScene* scene = HeadScene::create();
		Director* pDirector = Director::getInstance();
		TransitionFade* jump = TransitionFade::create(0.3f, scene);
		pDirector->replaceScene(jump);
}