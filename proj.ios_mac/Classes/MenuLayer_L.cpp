#include "MenuLayer_L.h"


MenuLayer_L::MenuLayer_L()
{
}


MenuLayer_L::~MenuLayer_L()
{
}

bool MenuLayer_L::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	return true;
}