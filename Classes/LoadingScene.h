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
	void LoadingComplete(float);
private:
	static int LoadingNum;
};