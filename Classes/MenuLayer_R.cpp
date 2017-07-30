#include "MenuLayer_R.h"
#include "HeadScene.h"
#include "GameConfig.h"

MenuLayer_R::MenuLayer_R()
{
}


MenuLayer_R::~MenuLayer_R()
{
}

bool MenuLayer_R::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size MyWinSize = Director::getInstance()->getVisibleSize();

	MenuItemSprite* BackBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(BACK_BTN_PNG),
		Sprite::createWithSpriteFrameName(BACK_BTN_DOWN_PNG),
		NULL,
		this, menu_selector(HeadScene::GotoHeadScene));
	BackBtn->setPosition(MyWinSize.width - BackBtn->getContentSize().width / 2 - 5, MyWinSize.height - BackBtn->getContentSize().height / 2 - 5);


	Menu* menu = Menu::create(BackBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);

	return true;
}