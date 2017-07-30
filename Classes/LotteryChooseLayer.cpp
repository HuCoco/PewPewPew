#include "LotteryChooseLayer.h"
int LotteryChooseLayer::ChooseState = 0;
LotteryChooseLayer::LotteryChooseLayer()
{

}



LotteryChooseLayer::~LotteryChooseLayer()
{

}

bool LotteryChooseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	Sprite* BGImgae = Sprite::createWithSpriteFrameName("BGI.png");
	BGImgae->setPosition(MyWinSize.width / 2, MyWinSize.height / 2);
	this->addChild(BGImgae);
	MenuItemSprite* Normal = MenuItemSprite::create
		(Sprite::createWithSpriteFrameName(GO_BTN_PNG),
		Sprite::createWithSpriteFrameName(GO_BTN_DOWN_PNG),
		NULL,
		this,
		menu_selector(LotteryChooseLayer::GotoNormal));
	Normal->setPosition(MyWinSize.width / 3, MyWinSize.height / 2);

	MenuItemSprite* Special = MenuItemSprite::create
		(Sprite::createWithSpriteFrameName(GO_BTN_PNG),
		Sprite::createWithSpriteFrameName(GO_BTN_DOWN_PNG),
		NULL,
		this,
		menu_selector(LotteryChooseLayer::GotoSpecial));
	Special->setPosition(MyWinSize.width / 3 * 2, MyWinSize.height / 2);

	MenuItemSprite* BackBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(BACK_BTN_PNG),
		Sprite::createWithSpriteFrameName(BACK_BTN_DOWN_PNG),
		NULL,
		this,
		menu_selector(HeadScene::GotoHeadScene));
	BackBtn->setPosition(MyWinSize.width - BackBtn->getContentSize().width / 2, MyWinSize.height - BackBtn->getContentSize().height / 2);


	Menu* menu = Menu::create(Normal, Special,BackBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);


	return true;
}

int LotteryChooseLayer::GetChooseState()
{
	return ChooseState;
}

void LotteryChooseLayer::GotoNormal(Ref* pSender)
{
	ChooseState = 1;
	LotteryScene* scene = LotteryScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);
}

void LotteryChooseLayer::GotoSpecial(Ref* pSender)
{
	ChooseState = 2;
	LotteryScene* scene = LotteryScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene);
	pDirector->replaceScene(jump);
}