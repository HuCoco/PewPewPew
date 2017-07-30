#pragma once
#include "cocos2d.h"
#include "C2DXShareSDK.h"

using namespace cn::sharesdk;

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
    void screenShoot();
private:
	Sprite* BGImage_One;
	Sprite* BGImage_Two;
};

