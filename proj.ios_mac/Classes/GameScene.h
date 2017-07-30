#pragma once
#include "cocos2d.h"
#include "HeadScene.h"
#include "GameLayer_G.h"
#include "BGILayer_G.h"
#include "GameOverLayer_G.h"
#include "MenuLayer_G.h"
#include "MyAudio.h"
#include "MobClickCpp.h"
USING_NS_CC;
class GameScene
	:public Scene
{
public:
	GameScene();
	~GameScene();
	CREATE_FUNC(GameScene);
	virtual bool init();
	void GotoGameScene(Ref* pSender);

};

