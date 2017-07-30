#include "BGImageLayer_O.h"
#include "GameConfig.h"


BGImageLayer_O::BGImageLayer_O()
{
}


BGImageLayer_O::~BGImageLayer_O()
{
}


bool BGImageLayer_O::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* BGImage = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(BGImage);
	BGImage_One = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage_One->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(BGImage_One);
	BGImage_Two = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage_Two->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height / 2*3));
	this->addChild(BGImage_Two);
	this->schedule(schedule_selector(BGImageLayer_O::BGIGo));
	return true;
}
void BGImageLayer_O::BGIGo(float dt)
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
			BGImage_Two->setPositionY(BGImage_One->getPositionY() + BGImage_Two->getContentSize().height);
	}
}