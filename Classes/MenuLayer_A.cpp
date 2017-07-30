#include "MenuLayer_A.h"
#include "GameConfig.h"

MenuLayer_A::MenuLayer_A()
{
}


MenuLayer_A::~MenuLayer_A()
{
}

bool MenuLayer_A::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//auto ListenrKeyPad = EventListenerKeyboard::create();
	//ListenrKeyPad->onKeyReleased = CC_CALLBACK_2(MenuLayer_A::onKeyReleased, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(ListenrKeyPad, this);
	
	//·µ»Ø°´Å¥
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

//android ·µ»Ø¼ü
//void MenuLayer_A::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event)
//{
//	HeadScene* scene = HeadScene::create();
//	Director* pDirector = Director::getInstance();
//	TransitionFade* jump = TransitionFade::create(0.3f, scene);
//	pDirector->replaceScene(jump);
//}