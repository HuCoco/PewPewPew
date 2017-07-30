#pragma once
#include "cocos2d.h"
#include "HeadScene.h"
#include "C2DXShareSDK.h"
#include "AdsMogoInterstitial.h"
using namespace cn::sharesdk;

USING_NS_CC;
class GameOverLayer_G
	:public Layer
{
public:
	GameOverLayer_G();
	~GameOverLayer_G();
	CREATE_FUNC(GameOverLayer_G);
	virtual bool init();
    void ShareScore(Ref*);
    void screenShoot();
    void requestInterstitialCallback();
    void showInterstitialCallback();
    void CloseInterstitialCallback();
};

