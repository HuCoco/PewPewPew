//
//
//
//
//


#pragma once
#include "cocos2d.h"
//
#include "MyAudio.h"
#include "BGILayer_H.h"
#include "MenuLayer_H.h"
#include "HeadScene.h"
#include "AboutScene.h"
#include "OptionScene.h"
USING_NS_CC;

class HeadScene
	:public Scene
{
public:
	HeadScene();
	~HeadScene();
	CREATE_FUNC(HeadScene);
	virtual bool init();
	void Close(Ref* pSender);
	void GotoHeadScene(Ref* pSender);
	void FromGameSceneToHeadScene(Ref* pSender);
private:
	static bool GameState;

};

