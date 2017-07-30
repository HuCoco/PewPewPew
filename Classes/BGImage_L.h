#pragma once
#include"cocos2d.h"
#include "GameConfig.h"
USING_NS_CC;
class BGImage_L
	:public Layer
{
public:
	BGImage_L();
	~BGImage_L();
	CREATE_FUNC(BGImage_L);
	virtual bool init();
	void BGIGo(float);
private:
	Sprite* BGImage_One;
	Sprite* BGImage_Two;
};

