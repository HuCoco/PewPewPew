#pragma once
#include "cocos2d.h"
#include "HeadScene.h"
#include "MyAudio.h"
USING_NS_CC;
class MenuLayer_O
	:public Layer
{
public:
	MenuLayer_O();
	~MenuLayer_O();
	CREATE_FUNC(MenuLayer_O);
	virtual bool init();
	void BGIOffAndOn(Ref* pSender);
	void ReSetData(Ref*);
	static bool getIsOn();
    void DataResetAnimation();
private:
	static bool isOn;
	MenuItemToggle* BGMBtn;
    LabelBMFont* Str_Reset;
};

