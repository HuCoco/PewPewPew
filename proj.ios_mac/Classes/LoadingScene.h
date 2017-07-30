#pragma once 
#include "cocos2d.h"
USING_NS_CC;

class LoadingScene
	:public Scene
{
public:
	CREATE_FUNC(LoadingScene);
	virtual bool init();
	LoadingScene();
	~LoadingScene();
	void AllResCallback(Texture2D* texture);
	void LoadingComplete();
    void LoadingAction();
    Sequence* LoadingActioninit(Sprite* ,Vec2,float _delaytime,bool _callback = 0);
    void RingGo(float);
private:
	static int LoadingNum;
    Sprite* Ring;
};