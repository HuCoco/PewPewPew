#pragma once
#include "cocos2d.h"
USING_NS_CC;
class BGImageLayer_O
	:public Layer
{
public:
	BGImageLayer_O();
	~BGImageLayer_O();
	CREATE_FUNC(BGImageLayer_O);
	virtual bool init();
	void BGIGo(float);
private:
	Sprite* BGImage_One;
	Sprite* BGImage_Two;
};
