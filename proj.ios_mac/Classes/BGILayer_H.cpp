#include "BGILayer_H.h"
#include "GameConfig.h"


BGILayer_H::BGILayer_H()
{
}


BGILayer_H::~BGILayer_H()
{
}

bool BGILayer_H::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* BGImage = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(BGImage);
	Sprite* GameName1 = Sprite::createWithSpriteFrameName(GAME_NAME_PNG);
	GameName1->setPosition(Vec2(visibleSize.width*3/8, visibleSize.height*9/10));
	this->addChild(GameName1,3);

	Sprite* GameName2 = Sprite::createWithSpriteFrameName(GAME_NAME_PNG);
	GameName2->setPosition(Vec2(visibleSize.width * 4 / 8, visibleSize.height * 8 / 10));
	this->addChild(GameName2, 3);

	Sprite* GameName3 = Sprite::createWithSpriteFrameName(GAME_NAME_PNG);
	GameName3->setPosition(Vec2(visibleSize.width * 5 / 8, visibleSize.height * 7 / 10));
	this->addChild(GameName3, 3);


	BGImage_One = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage_One->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(BGImage_One);
	BGImage_Two = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage_Two->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height / 2 *3-5));
	this->addChild(BGImage_Two);
	this->schedule(schedule_selector(BGILayer_H::BGIGo));

	return true;
}
void BGILayer_H::BGIGo(float dt)
{
	if (BGImage_One!=NULL && BGImage_Two!=NULL)
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