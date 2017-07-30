#include "MenuLayer_O.h"
#include"GameConfig.h"
bool MenuLayer_O::isOn = true;
MenuLayer_O::MenuLayer_O()
{
	
}


MenuLayer_O::~MenuLayer_O()
{
}


bool MenuLayer_O::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto ListenrKeyPad = EventListenerKeyboard::create();
	ListenrKeyPad->onKeyReleased = CC_CALLBACK_2(MenuLayer_O::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(ListenrKeyPad, this);


	Size visibleSize = Director::getInstance()->getVisibleSize();

	switch (MyAudio::getBGMState())
	{
	case true:
		BGMBtn = MenuItemToggle::createWithTarget(
			this,
			menu_selector(MenuLayer_O::BGIOffAndOn),
			MenuItemSprite::create(Sprite::createWithSpriteFrameName(MUSIC_ON_BTN), Sprite::createWithSpriteFrameName(MUSIC_ON_BTN)),
			MenuItemSprite::create(Sprite::createWithSpriteFrameName(MUSIC_OFF_BTN), Sprite::createWithSpriteFrameName(MUSIC_OFF_BTN)),
			NULL
			);

		break;
	case false:
		BGMBtn = MenuItemToggle::createWithTarget(
			this,
			menu_selector(MenuLayer_O::BGIOffAndOn),
			MenuItemSprite::create(Sprite::createWithSpriteFrameName(MUSIC_OFF_BTN), Sprite::createWithSpriteFrameName(MUSIC_OFF_BTN)),
			MenuItemSprite::create(Sprite::createWithSpriteFrameName(MUSIC_ON_BTN), Sprite::createWithSpriteFrameName(MUSIC_ON_BTN)),
			NULL
			);

		break;
	}
		
	BGMBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 5*2));

	MenuItemSprite* BackBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(BACK_BTN_PNG),
		Sprite::createWithSpriteFrameName(BACK_BTN_PNG),
		NULL,
		this,
		menu_selector(HeadScene::GotoHeadScene));
	BackBtn->setPosition(visibleSize.width - BackBtn->getContentSize().width/2-5,visibleSize.height - BackBtn->getContentSize().height/2-5);


	MenuItemSprite* ReSetBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(RESET_BTN),
		Sprite::createWithSpriteFrameName(RESET_BTN_DOWN),
		NULL,
		this,
		menu_selector(MenuLayer_O::ReSetData));
	ReSetBtn->setPosition(visibleSize.width/2, visibleSize.height/5*3);


	
	Menu* menu = Menu::create(BGMBtn,BackBtn,ReSetBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);

	return true;
}

void MenuLayer_O::BGIOffAndOn(Ref* pSender)
{
	if (isOn == true)
	{
		MyAudio::PauseBGM();
		isOn = false;
		MyAudio::BGM_State(false);
	}
	else
	{
		MyAudio::resumeBGM();
		isOn = true;
		MyAudio::BGM_State(true);
	}
}


void MenuLayer_O::ReSetData(Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey(FIRST_SCORE, 0);
	UserDefault::getInstance()->setIntegerForKey(SECOND_SCORE, 0);
	UserDefault::getInstance()->setIntegerForKey(THIRD_SOCRE, 0);
	UserDefault::getInstance()->setIntegerForKey(FOURTH_SCORE, 0);
	UserDefault::getInstance()->setIntegerForKey(FIFTH_SCORE, 0);

	UserDefault::getInstance()->setStringForKey(FIRST_PLANE, "");
	UserDefault::getInstance()->setStringForKey(SECOND_PLANE, "");
	UserDefault::getInstance()->setStringForKey(THIRD_PLANE, "");
	UserDefault::getInstance()->setStringForKey(FOURTH_PLANE, "");
	UserDefault::getInstance()->setStringForKey(FIFTH_PLANE, "");
}

bool MenuLayer_O::getIsOn()
{
	return isOn;
}