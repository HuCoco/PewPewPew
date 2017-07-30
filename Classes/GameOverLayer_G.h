#pragma once
#include "cocos2d.h"
#include "HeadScene.h"
USING_NS_CC;
class GameOverLayer_G
	:public Layer
{
public:
	GameOverLayer_G();
	~GameOverLayer_G();
	CREATE_FUNC(GameOverLayer_G);
	virtual bool init();
};

