#pragma once
#include "cocos2d.h"
USING_NS_CC;
class BGILayer_G
	:public Layer
{
public:
	BGILayer_G();
	~BGILayer_G();
	CREATE_FUNC(BGILayer_G);
	virtual bool init();
	void BGIGo(float);
private:
	Sprite* BGImage_One;
	Sprite* BGImage_Two;
};

