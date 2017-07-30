#include "OptionScene.h"


OptionScene::OptionScene()
{
}


OptionScene::~OptionScene()
{
}
bool OptionScene::init()
{
	if (!CCScene::init())
	{
		return false;
	}
	BGImageLayer_O* BGILayer = BGImageLayer_O::create();
	this->addChild(BGILayer, 1);
	MenuLayer_O* MenuLayer = MenuLayer_O::create();
	this->addChild(MenuLayer, 3);
	return true;
}
void OptionScene::GotoOptionScene(Ref* pSender)
{
	OptionScene* scene = OptionScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);

}

