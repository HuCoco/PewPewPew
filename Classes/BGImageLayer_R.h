#pragma once
#include "cocos2d.h"

USING_NS_CC;
class BGImageLayer_R 
	:public Layer
{
public:
	BGImageLayer_R();
	~BGImageLayer_R();
	CREATE_FUNC(BGImageLayer_R);
	virtual bool init();
	void BGIGo(float);
	void Share(Ref*);
private:
	Sprite* BGImage_One;
	Sprite* BGImage_Two;
};

