#include "GameScene.h"


GameScene::GameScene()
{
}


GameScene::~GameScene()

{
}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	BGILayer_G* BGILayer = BGILayer_G::create();
	this->addChild(BGILayer,1);
	GameLayer_G* GameLayer = GameLayer_G::create();
	this->addChild(GameLayer, 3);
	MenuLayer_G* MenuLayer = MenuLayer_G::create();
	this->addChild(MenuLayer, 4);
	if (MenuLayer_O::getIsOn())
	{
		MyAudio::PlayGameSceneBGM();
	}
		








	return true;
}

void GameScene::GotoGameScene(Ref* pSender)
{
	if (MenuLayer_O::getIsOn())
	{
		MyAudio::StopBGM();
		MyAudio::PlayGameSceneBGM();
	}
	GameScene* scene = GameScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);
}
