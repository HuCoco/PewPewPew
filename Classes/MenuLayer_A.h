#pragma once
#include "cocos2d.h"
#include "HeadScene.h"

USING_NS_CC;
class MenuLayer_A
	:public Layer
{
public:
	MenuLayer_A();
	~MenuLayer_A();
	CREATE_FUNC(MenuLayer_A);
	virtual bool init();
	//void onKeyReleased(EventKeyboard::KeyCode, Event*);
};

