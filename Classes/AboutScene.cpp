#include "AboutScene.h"


AboutScene::AboutScene()
{
}


AboutScene::~AboutScene()
{
}

bool AboutScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	//±³¾°²ã
	BGImageLayer_A* BGILayer = BGImageLayer_A::create();
	this->addChild(BGILayer, 1);
	//²Ëµ¥²ã
	MenuLayer_A* MenuLayer = MenuLayer_A::create();
	this->addChild(MenuLayer, 3);



	return true;
}



void AboutScene::GotoAboutScene(Ref* pSender)
{
	AboutScene* scene = AboutScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);

}