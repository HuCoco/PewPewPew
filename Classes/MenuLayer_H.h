#pragma once
#include "cocos2d.h"
#include "HeadScene.h"
#include "GameScene.h"
#include "AboutScene.h"
#include "OptionScene.h"
#include "RankScene.h"
#include "LotteryScene.h"
#include "LotteryLayer.h"
#include "LotteryChooseLayer.h"
#include "PlaneChooseLayer.h"
USING_NS_CC;
class MenuLayer_H
	:public Layer
{
public:
	MenuLayer_H();
	~MenuLayer_H();
	CREATE_FUNC(MenuLayer_H);
	virtual bool init();
	void onKeyReleased(EventKeyboard::KeyCode, Event*);
	void goRight(Ref*);
	void goLift(Ref*);
	static void SetGoBtnstate(bool);
	void GotoChooseLayer(Ref* pSender);
private:

	static MenuItemSprite* GoBtn;
};

