#include "BGImageLayer_A.h"
#include "GameConfig.h"
BGImageLayer_A::BGImageLayer_A()
{

}
BGImageLayer_A::~BGImageLayer_A()
{

}

bool BGImageLayer_A::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//´¥ÃþÊÂ¼þ
	auto touch_listener = EventListenerTouchOneByOne::create();
	touch_listener->setSwallowTouches(false);
	touch_listener->onTouchBegan = CC_CALLBACK_2(BGImageLayer_A::onTouchBegan, this);
	touch_listener->onTouchMoved = CC_CALLBACK_2(BGImageLayer_A::onTouchMoved, this);
	touch_listener->onTouchEnded = CC_CALLBACK_2(BGImageLayer_A::onTouchEnded, this);
	touch_listener->onTouchCancelled = CC_CALLBACK_2(BGImageLayer_A::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch_listener, this);

	//±³¾°Í¼Æ¬
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite* BGImage = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
	BGImage->setPosition(Vec2(visibleSize.width /2 , visibleSize.height / 2));
	this->addChild(BGImage);
	return true;
}
bool BGImageLayer_A::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	Point touchLocation = pTouch->getLocationInView();
	touchLocation = Director::getInstance()->convertToGL(touchLocation);
	return true;
}
void BGImageLayer_A::onTouchMoved(Touch* pTouch, Event* pEvent)
{

}

void BGImageLayer_A::onTouchEnded(Touch* pTouch, Event* pEvent)
{


	return;
}
