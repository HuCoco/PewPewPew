#pragma once
#include "cocos2d.h"
#include "HeadScene.h"
USING_NS_CC;
class BGILayer_H     //background image layer
	:public Layer
{
public:
	BGILayer_H();
	~BGILayer_H();
	CREATE_FUNC(BGILayer_H);
	virtual bool init();
	void BGIGo(float);
private:
	Sprite* BGImage_One;
	Sprite* BGImage_Two;
};

