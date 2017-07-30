#include "LotteryScene.h"


LotteryScene::LotteryScene()
{
}


LotteryScene::~LotteryScene()
{
}

bool LotteryScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	MenuLayer_L* MenuLayer = MenuLayer_L::create();
	this->addChild(MenuLayer,3);
	LotteryLayer* MainLayer = LotteryLayer::create();
	this->addChild(MainLayer,2);

	return true;
}

void LotteryScene::GotoLotteryScene(Ref* pSender)
{
	LotteryScene* scene = LotteryScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);
}