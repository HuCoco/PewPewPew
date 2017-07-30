#include "GameOverLayer_G.h"
#include "GameConfig.h"


GameOverLayer_G::GameOverLayer_G()
{
}


GameOverLayer_G::~GameOverLayer_G()
{
}

bool GameOverLayer_G::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite* GameOver = Sprite::createWithSpriteFrameName(GAMEOVER_PNG);
	GameOver->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4 *3));
	this->addChild(GameOver);

	Sprite* ScoreBar = Sprite::createWithSpriteFrameName(SCORE_PNG);
	ScoreBar->setPosition(Vec2(visibleSize.width / 3, visibleSize.height /20 * 11));
	this->addChild(ScoreBar);
	Sprite* BestBar = Sprite::createWithSpriteFrameName(BEST_PNG);
	BestBar->setPosition(Vec2(visibleSize.width / 3, visibleSize.height /20 * 9));
	this->addChild(BestBar);

	MenuItemSprite* BackBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(BACK_BTN_PNG), 
		Sprite::createWithSpriteFrameName(BACK_BTN_DOWN_PNG),
		NULL,
		this,
		menu_selector(HeadScene::FromGameSceneToHeadScene));
	Size BackBtnSize = BackBtn->getContentSize();
	BackBtn->setPosition(visibleSize.width / 2, visibleSize.height/4);
	Menu* menu = Menu::create(BackBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);
	return true;
}

