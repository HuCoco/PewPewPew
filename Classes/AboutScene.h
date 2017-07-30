#pragma once
#include"cocos2d.h"
#include "BGImageLayer_A.h"
#include "MenuLayer_A.h"
#include "PlaneChooseLayer.h"

USING_NS_CC;
class AboutScene
	:public Scene
{
public:
	AboutScene();
	~AboutScene();
	CREATE_FUNC(AboutScene);
	virtual bool init();
	void GotoAboutScene(Ref* pSender);	 //×ª»»µ½About³¡¾°

};