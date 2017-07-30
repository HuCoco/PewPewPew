#include "RankScene.h"

RankScene::RankScene()
{

}

RankScene::~RankScene()
{

}

bool RankScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	MenuLayer_R* menulayer = MenuLayer_R::create();
	this->addChild(menulayer,10);

 	BGImageLayer_R* bgilayer = BGImageLayer_R::create();
	this->addChild(bgilayer);

	return true;
}

void RankScene::GotoRankScene(Ref* pSender)
{
	RankScene* scene = RankScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);
}