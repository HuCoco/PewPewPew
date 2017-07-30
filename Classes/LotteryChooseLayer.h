#pragma once
#include"cocos2d.h"
#include"GameConfig.h"
#include"LotteryScene.h"
USING_NS_CC;

class LotteryChooseLayer
	:public Layer
{
public:
	LotteryChooseLayer();
	~LotteryChooseLayer();
	CREATE_FUNC(LotteryChooseLayer);
	virtual bool init();
	static int GetChooseState();
	void GotoNormal(Ref*);
	void GotoSpecial(Ref*);
private:
	static int ChooseState;


};