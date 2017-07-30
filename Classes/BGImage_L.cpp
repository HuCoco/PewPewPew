#include "BGImage_L.h"


BGImage_L::BGImage_L()
{
}


BGImage_L::~BGImage_L()
{
}

bool BGImage_L::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	BGImage_One = Sprite::create(BACKGROUND_IMAGE_PNG);
	BGImage_One->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(BGImage_One);
	BGImage_Two = Sprite::create(BACKGROUND_IMAGE_PNG);
	BGImage_Two->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 * 3));
	this->addChild(BGImage_Two);
	this->schedule(schedule_selector(BGImage_L::BGIGo));
	return true;
}
//±³¾°¹ö¶¯
void BGImage_L::BGIGo(float dt)
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
