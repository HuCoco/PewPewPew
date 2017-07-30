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
	MenuItemSprite* BackBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(BACK_BTN_PNG),
		Sprite::createWithSpriteFrameName(BACK_BTN_DOWN_PNG),
		NULL, 
		this,
		menu_selector(HeadScene::GotoHeadScene));
	BackBtn->setPosition(visibleSize.width - BackBtn->getContentSize().width / 2 - 5, visibleSize.height - BackBtn->getContentSize().height / 2 - 5);


	Menu* menu = Menu::create(BackBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);
	return true;
}