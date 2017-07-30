#pragma once
#include "cocos2d.h"
#include "GameScene.h"
USING_NS_CC;
class PauseLayer
	:public Layer
{
public:
	PauseLayer();
	~PauseLayer();
	CREATE_FUNC(PauseLayer);
	virtual bool init();
};
