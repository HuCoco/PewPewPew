#include "MenuLayer_H.h"
#include "GameConfig.h"

MenuItemSprite* MenuLayer_H::GoBtn = NULL;
MenuLayer_H::MenuLayer_H()
{
}


MenuLayer_H::~MenuLayer_H()
{
}


bool MenuLayer_H::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto ListenrKeyPad = EventListenerKeyboard::create();
	ListenrKeyPad->onKeyReleased = CC_CALLBACK_2(MenuLayer_H::onKeyReleased,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(ListenrKeyPad, this);

	Size MyWinSize = Director::getInstance()->getWinSize();
    
    //MissionSystem.Reset();
    MissionSystem.InitData();
    MissionSystem.GetNewMission();
    MissionSystem.Save();
    MissionSystem.CompleteMission();
	//GameStartBtn
	GoBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(GO_BTN_PNG),
		Sprite::createWithSpriteFrameName(GO_BTN_DOWN_PNG),
		Sprite::createWithSpriteFrameName(GO_BTN_NULL),
		this,
		menu_selector(GameScene::GotoGameScene));
	GoBtn->setPosition(MyWinSize.width / 2, MyWinSize.height / 4);

	//AboutBtn
	MenuItemSprite* GotoAboutSceneBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(ABOUT_BTN_PNG),
		Sprite::createWithSpriteFrameName(ABOUT_BTN_DOWN_PNG),
		NULL,
		this,
		menu_selector(AboutScene::GotoAboutScene));
	GotoAboutSceneBtn->setScale(0.7f);
	GotoAboutSceneBtn->setPosition(GotoAboutSceneBtn->getContentSize().width / 2 * 0.7, MyWinSize.height - GotoAboutSceneBtn->getContentSize().height / 2 * 0.7);
	//MissionLayer
    MenuItemSprite* GotoMissionLayerBtn =
    MenuItemSprite::create(
                           Sprite::create("MissionBtnOn.png"),
                           Sprite::create("MissionBtnDown.png"),
                           NULL,
                           this,
                           menu_selector(MenuLayer_H::ShowMission));
    GotoMissionLayerBtn->setScale(0.7f);
    GotoMissionLayerBtn->setPosition(MyWinSize.width - GotoMissionLayerBtn->getContentSize().width/2 * 0.7 , MyWinSize.height - GotoMissionLayerBtn->getContentSize().height / 2 * 0.7);
    
	//OptionBtn
	MenuItemSprite* GotoOptionSceneBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(OPTION_BTN_PNG),
		Sprite::createWithSpriteFrameName(OPTION_BTN_DOWN_PNG),
		NULL,
		this,
		menu_selector(OptionScene::GotoOptionScene));
	GotoOptionSceneBtn->setScale(0.7f);
	GotoOptionSceneBtn->setPosition(MyWinSize.width / 6*5, MyWinSize.height / 9 );
	//LotteryBtn

	
	MenuItemSprite* GotoLotterySceneBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(LOTTERY_BTN_PNG),
		Sprite::createWithSpriteFrameName(LOTTERY_BTN_PNG),
		NULL,
		this,
		menu_selector(LotteryScene::GotoLotteryScene));
	GotoLotterySceneBtn->setPosition(MyWinSize.width / 2, MyWinSize.height / 9);
	//RankBtn
	MenuItemSprite* GotoRankSceneBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(RANKINGLIST_BTN_PNG),
		Sprite::createWithSpriteFrameName(RANKINGLIST_BTN_PNG),
		NULL,
		this,
		menu_selector(RankScene::GotoRankScene));
	GotoRankSceneBtn->setPosition(MyWinSize.width / 6, MyWinSize.height / 9);



	cocos2d::Menu* menu = 
		cocos2d::Menu::create(GotoLotterySceneBtn,GotoRankSceneBtn,GoBtn, GotoAboutSceneBtn, GotoOptionSceneBtn, GotoMissionLayerBtn,NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);

	return true;
}


void MenuLayer_H::onKeyReleased(EventKeyboard::KeyCode keycode, Event* event)
{
	Director::getInstance()->end();
}


void MenuLayer_H::goLift(Ref* pSender)
{

}

void MenuLayer_H::goRight(Ref* pSender)
{

}




void MenuLayer_H::SetGoBtnstate(bool _state)
{
	GoBtn->setEnabled(_state);
}


void MenuLayer_H::ShowMission(Ref* pSender)
{
    MenuItemSprite* OKBtn =
    MenuItemSprite::create(
                           Sprite::createWithSpriteFrameName(OK_BTN),
                           Sprite::createWithSpriteFrameName(OK_BTN_DOWN),
                           NULL,
                           this,
                           menu_selector(MenuLayer_H::CloseMission));
    OKBtn->setScale(0.7f);
    OKBtn->setPosition(Director::getInstance()->getVisibleSize().width/2,OKBtn->getContentSize().height+5);
    Menu* Mmenu =
    cocos2d::Menu::create(OKBtn,NULL);
    Mmenu->setPosition(0, 0);
   
    Mlayer = MissionLayer::create();
    Mlayer->addChild(Mmenu,2);
    this->addChild(Mlayer,10,"Mlayer");
}

void MenuLayer_H::CloseMission(cocos2d::Ref *pSender)
{
    this->removeChildByName("Mlayer");
}
