#pragma once
#include "cocos2d.h"
USING_NS_CC;
class BGImageLayer_A
	:public Layer
{
public:
	BGImageLayer_A();
	~BGImageLayer_A();
	CREATE_FUNC(BGImageLayer_A);
	virtual bool init();

	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);
};

