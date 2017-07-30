#pragma once
#include "cocos2d.h"
#include "BGImageLayer_O.h"
#include "MenuLayer_O.h"
USING_NS_CC;
class OptionScene
	:public Scene
{
public:
	OptionScene();
	~OptionScene();
	CREATE_FUNC(OptionScene);
	virtual bool init();
	void GotoOptionScene(Ref* pSender);
};