#pragma once
#include "cocos2d.h"
#include "GameConfig.h"
#include"MenuLayer_L.h"
#include"LotteryLayer.h"
USING_NS_CC;
class LotteryScene
	:public Scene
{
public:
	LotteryScene();
	~LotteryScene();
	CREATE_FUNC(LotteryScene);
	virtual bool init();
	void GotoLotteryScene(Ref*);
};

