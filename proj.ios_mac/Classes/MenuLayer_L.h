#pragma once
#include"cocos2d.h"
#include "GameConfig.h"
#include "HeadScene.h"
USING_NS_CC;
class MenuLayer_L
	:public Layer
{
public:
	MenuLayer_L();
	~MenuLayer_L();
	virtual bool init();
	CREATE_FUNC(MenuLayer_L);

};

