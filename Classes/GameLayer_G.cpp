#include "GameLayer_G.h"
#include "GameConfig.h"
GameLayer_G::GameLayer_G()
{
	touch_listener = EventListenerTouchOneByOne::create();
	isTouchMoving = false;
	Level = Levelv1;
	MoreScore = 1;
	isPause = false;
	level = 1;
	BiuColorData = Yellow;
	Score = 0;
	DataString = "BestScore";
	UpdataTime = 2;
	BlueCome = 0;
	RedCome = 0;
}
//析构释放内存
GameLayer_G::~GameLayer_G()
{

	std::vector<ColorMeteorites>(Meteorites).swap(Meteorites);
	std::vector<ColorBiu>(Biu).swap(Biu);
}

bool GameLayer_G::CircleCollision(Sprite* _Sp1, Sprite* _Sp2)
{
	if (_Sp1 == NULL || _Sp2 == NULL)
	{
		return false;
	}
	Vec2 Sp1Position = _Sp1->getPosition();
	Size Sp1Size = _Sp1->getContentSize();

	Vec2 Sp2Position = _Sp2->getPosition();
	Size Sp2Size = _Sp2->getContentSize();

	float Len = sqrt((Sp1Position.x - Sp2Position.x)*(Sp1Position.x - Sp2Position.x) + (Sp1Position.y - Sp2Position.y)*(Sp1Position.y - Sp2Position.y));
	float distance = Sp1Size.width / 2 + Sp2Size.width / 2;
	if (Len > distance)
		return false;
	else
		return true;
}

void GameLayer_G::DeleteBiu(int _n)
{

	std::vector<ColorBiu>::iterator MyBiu_Iter = Biu.begin() + _n;
	Biu.erase(MyBiu_Iter);


}
void GameLayer_G::DeleteMeteorites(int _n)
{

	std::vector<ColorMeteorites>::iterator Meteorites_Iter = Meteorites.begin() + _n;
	Meteorites.erase(Meteorites_Iter);

}

bool GameLayer_G::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//读取数据

	ReadRank();

	auto ListenrKeyPad = EventListenerKeyboard::create();
	ListenrKeyPad->onKeyReleased = CC_CALLBACK_2(MenuLayer_G::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(ListenrKeyPad, this);
	Size MyWinSize = Director::getInstance()->getVisibleSize();

	//Coin
	CoinSprite = Sprite::createWithSpriteFrameName("Coin.png");
	CoinSprite->setPosition(MyWinSize.width - CoinSprite->getContentSize().width, MyWinSize.height - CoinSprite->getContentSize().height);
	this->addChild(CoinSprite, 5);

	sprintf(CoinNumber, "%d", UserDefault::getInstance()->getIntegerForKey(COIN_NUM, 0));
	CoinBMFont = LabelBMFont::create(CoinNumber, SG14_FNT);
	CoinBMFont->setAnchorPoint(Vec2(1, 0.5));
	CoinBMFont->setPosition(MyWinSize.width - CoinSprite->getContentSize().width - 30, MyWinSize.height - CoinSprite->getContentSize().height);
	this->addChild(CoinBMFont, 5);

	//返回按钮
	BackBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(BACK_BTN_PNG),
		Sprite::createWithSpriteFrameName(BACK_BTN_DOWN_PNG),
		NULL,
		this,
		menu_selector(HeadScene::FromGameSceneToHeadScene));
	BackBtn->setPosition(Vec2(MyWinSize.width / 2, MyWinSize.height / 2));
	BackBtn->setScale(0.01f);



	PauseBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(PAUSE_BTN),
		Sprite::createWithSpriteFrameName(PAUSE_BTN),
		NULL,
		this,
		menu_selector(GameLayer_G::GamePause));
	PauseBtn->setPosition(Vec2(PauseBtn->getContentSize().width/2, MyWinSize.height -PauseBtn->getContentSize().height/2));


	ContinueBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(CONTINUE_BTN),
		Sprite::createWithSpriteFrameName(CONTINUE_BTN),
		NULL,
		this,
		menu_selector(GameLayer_G::GamePause));
	ContinueBtn->setPosition(Vec2(MyWinSize.width / 2, MyWinSize.height / 2 + ContinueBtn->getContentSize().height + 30));
	ContinueBtn->setScale(0.01f);
	Menu* menu = Menu::create(PauseBtn, BackBtn, ContinueBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu, 10);



	BlueBiuBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(BLUE_BIU_BTN_PNG),
		Sprite::createWithSpriteFrameName(BLUE_BIU_BTN_PNG),
		NULL,
		this,
		menu_selector(GameLayer_G::iSBlueBiu));
	BlueBiuBtn->setPosition(MyWinSize.width/2 + BlueBiuBtn->getContentSize().width*1.5+5,BlueBiuBtn->getContentSize().height/2*1.5);
	BlueBiuBtn->setScale(0.01f);

	RedBiuBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(RED_BIU_BTN_PNG),
		Sprite::createWithSpriteFrameName(RED_BIU_BTN_PNG),
		NULL,
		this,
		menu_selector(GameLayer_G::iSRedBiu));
	RedBiuBtn->setPosition(MyWinSize.width / 2 - RedBiuBtn->getContentSize().width*1.5-5, RedBiuBtn->getContentSize().height / 2*1.5 );
	RedBiuBtn->setScale(0.01f);

	YellowBiuBtn = 
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(YELLOW_BIU_BTN_PNG),
		Sprite::createWithSpriteFrameName(YELLOW_BIU_BTN_PNG),
		NULL,
		this,
		menu_selector(GameLayer_G::iSYellowBiu));
	YellowBiuBtn->setPosition(MyWinSize.width / 2, YellowBiuBtn->getContentSize().height / 2*1.5);
	YellowBiuBtn->setScale(1.5);
	Menu* menu1 = Menu::create(BlueBiuBtn, RedBiuBtn, YellowBiuBtn, NULL);
	menu1->setPosition(0, 0);
	this->addChild(menu1, 5);


	touch_listener->setSwallowTouches(false);
	touch_listener->onTouchBegan = CC_CALLBACK_2(GameLayer_G::onTouchBegan, this);
	touch_listener->onTouchMoved = CC_CALLBACK_2(GameLayer_G::onTouchMoved, this);
	touch_listener->onTouchEnded = CC_CALLBACK_2(GameLayer_G::onTouchEnded, this);
	touch_listener->onTouchCancelled = CC_CALLBACK_2(GameLayer_G::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch_listener, this);
	//加载飞机
	BiuPlane.CreatePlane(PlaneType(UserDefault::getInstance()->getIntegerForKey("ChooseType")));
	BiuPlane.setPosition(MyWinSize.width / 2, MyWinSize.height / 4);
	this->addChild(BiuPlane.getSprite(),1);
	//当前子弹颜色
	BiuState = LabelBMFont::create("YELLOW", SG14_FNT);
	BiuState->setColor(YELLOW_RGB);
	BiuState->setPosition(Vec2(MyWinSize.width / 2, MyWinSize.height / 8));
	this->addChild(BiuState);

	sprintf(ScoreString, "%d", Score);
	ScoreTTF = LabelBMFont::create(ScoreString, SG14_FNT);
	ScoreTTF->setColor(YELLOW_RGB);
	ScoreTTF->setPosition(Vec2(MyWinSize.width/2,MyWinSize.height/10*9 ));
	this->addChild(ScoreTTF);
	this->schedule(schedule_selector(GameLayer_G::AddMeteorites),UpdataTime);
	this->schedule(schedule_selector(GameLayer_G::LevelUpdate),10);
	this->schedule(schedule_selector(GameLayer_G::Scoreupdate));
	this->scheduleUpdate();
	return true;
}
void GameLayer_G::LevelUpdate(float dt)
{
	level+=1;
	
	if (level > 5)
	{
		
		level = 5;
	}
	this->unschedule(schedule_selector(GameLayer_G::AddMeteorites));
	UpdataTime -= 0.1;
	if (UpdataTime < 1)
	{
		UpdataTime = 0.5;
	}
	this->schedule(schedule_selector(GameLayer_G::AddMeteorites), UpdataTime);
	switch (level)
	{
	case 1:
		Level = Levelv1;
		break;
	case 2:
		Level = Levelv2;
		break;
	case 3:
		Level = Levelv3;
		break;
	case 4:
		Level = Levelv4;
		break;
	case 5:
		Level = Levelv5;
		break;
	}
	
}
void GameLayer_G::Scoreupdate(float dt)
{
	sprintf(ScoreString, "%d", Score);
	ScoreTTF->setString(ScoreString);
}

void GameLayer_G::Moving(float dt)
{
	int Len = Biu.size();
	for (int i = 0; i < Len; i++)
	{
		Biu.at(i).BiuMoving();
	}

}

void GameLayer_G::AddBiu()
{
	if (MenuLayer_O::getIsOn())
	{
		MyAudio::PlayShootEffect();
	}
	ColorBiu BiuExample;
	BiuExample.CreateBiu(BiuColorData,BiuPlane.getPlaneType());
	BiuExample.getSprite()->setRotation(BiuPlane.getRotation());
	Biu.push_back(BiuExample);
	Biu.back().setPosition(BiuPlane.getPosition());
	Biu.back().setDirection(TouchPoint,BiuPlane.getPosition());
	Biu.back().setSpeed(BiuPlane.getSpeed());
	Biu.back().setSpeed();
	this->addChild(Biu.back().getSprite());
	this->schedule(schedule_selector(GameLayer_G::Moving));
}
void GameLayer_G::AddMeteorites(float dt)
{
	float i;
	i = CCRANDOM_0_1() * 100;
	ColorMeteorites MeteoritesExample;
	switch (Level)
	{
	case Levelv1:
	
		if (i < 20)
		{
			MeteoritesExample.CreateMyMeteorites(VerySmallYellow);
		}
		else if(i >= 20 && i < 40)
		{
			MeteoritesExample.CreateMyMeteorites(SmallYellow);
		}
		else if (i >= 40 && i < 60)
		{
			MeteoritesExample.CreateMyMeteorites(MiddleYellow);
		}
		else if (i >= 60 && i < 80)
		{
			MeteoritesExample.CreateMyMeteorites(BigYellow);
		}
		else
		{
			MeteoritesExample.CreateMyMeteorites(VeryBigYellow);
		}
		break;

	
	
	case Levelv2:
		i = CCRANDOM_0_1() * 140;
		if (i < 20)
		{
			MeteoritesExample.CreateMyMeteorites(VerySmallYellow);
		}
		else if (i >= 20 && i < 40)
		{
			MeteoritesExample.CreateMyMeteorites(SmallYellow);
		}
		else if (i >= 40 && i < 60)
		{
			MeteoritesExample.CreateMyMeteorites(MiddleYellow);
		}
		else if (i >= 60 && i < 80)
		{
			MeteoritesExample.CreateMyMeteorites(BigYellow);
		}
		else if (i>=80 && i<100)
		{
			MeteoritesExample.CreateMyMeteorites(VeryBigYellow);
		}
		else if (i >= 100 && i < 120)
		{
			MeteoritesExample.CreateMyMeteorites(VerySmallRed);
		}
		else if (i >= 120 && i < 140)
		{
			MeteoritesExample.CreateMyMeteorites(VeryBigRed);
		}
		if (RedCome == 0)
		{
			RedBiuBtn->setScale(1.5);
			RedCome = 1;
			AddFinger(RedBiuBtn->getPosition());
		}
		break;
	default:
		i = CCRANDOM_0_1() * 180;
		if (i < 20)
		{
			MeteoritesExample.CreateMyMeteorites(VerySmallYellow);
		}
		else if (i >= 20 && i < 40)
		{
			MeteoritesExample.CreateMyMeteorites(SmallYellow);
		}
		else if (i >= 40 && i < 60)
		{
			MeteoritesExample.CreateMyMeteorites(MiddleYellow);
		}
		else if (i >= 60 && i < 80)
		{
			MeteoritesExample.CreateMyMeteorites(BigYellow);
		}
		else if (i >= 80 && i < 100)
		{
			MeteoritesExample.CreateMyMeteorites(VeryBigYellow);
		}
		else if (i >= 100 && i < 120)
		{
			MeteoritesExample.CreateMyMeteorites(VerySmallRed);
		}
		else if (i >= 120 && i < 140)
		{
			MeteoritesExample.CreateMyMeteorites(VeryBigRed);
		}
		else if (i >= 140 && i < 160)
		{
			MeteoritesExample.CreateMyMeteorites(VerySmallBlue);
		}
		else if (i >= 160 && i < 180)
		{
			MeteoritesExample.CreateMyMeteorites(VeryBigBlue);
		}
		if (BlueCome == 0)
		{
			BlueBiuBtn->setScale(1.5);
			BlueCome = 1;
			AddFinger(BlueBiuBtn->getPosition());
		}
		break;
		
	}
	Meteorites.push_back(MeteoritesExample);
	Meteorites.back().setDirection(BiuPlane.getPosition());
	if (Level == Levelv4 || Level == Levelv5)
	{
		Meteorites.back().setSpeed();
		Meteorites.back().setSpeed(1);
	}
	else
		Meteorites.back().setSpeed();
	this->addChild(Meteorites.back().getSprite());
	this->schedule(schedule_selector(GameLayer_G::Rotating));
	
}
void GameLayer_G::Rotating(float dt)
{
	for (unsigned int i = 0; i < Meteorites.size(); i++)
	{
		
		Meteorites.at(i).MeteoritesRotation();
		Meteorites.at(i).Moving();
	}

}
void GameLayer_G::update(float dt)
{
// 	飞船和陨石碰撞
		for (unsigned int i = 0; i < Meteorites.size(); i++)
		{
			if (Meteorites.at(i).getSprite() != NULL)
			if (CircleCollision(BiuPlane.getSprite(), Meteorites.at(i).getSprite()))
			{
				BiuPlane.setLife(BiuPlane.getLife() - 1);
				MeteoritesBOOM(Meteorites.at(i), Meteorites.at(i).getColorType());
				this->removeChild(Meteorites.at(i).getSprite());
				Meteorites.at(i).setSpriteNULL();
				DeleteMeteorites(i);

				if (BiuPlane.getLife() > 0)
				{
					continue;
				}
				//暂停
				_eventDispatcher->removeAllEventListeners();
				this->unscheduleAllSelectors();
				this->removeChild(ScoreTTF);
				PauseBtn->setScale(0.01f);
				PlaneBOOM(BiuPlane.getSprite()->getPosition());
				this->removeChild(BiuPlane.getSprite());
				//加载结束游戏层
				GameOverLayer_G* GameOverLayer = GameOverLayer_G::create();
				this->addChild(GameOverLayer, 5);
				ScreenShake(GameOverLayer);
				//显示当前分数
				sprintf(ScoreString, "%d", Score);
				LabelBMFont* FinalScoreTTF = LabelBMFont::create(ScoreString, SG14_FNT);
				FinalScoreTTF->setColor(WHITE_RGB);
				FinalScoreTTF->setPosition(Vec2(Director::getInstance()->getVisibleSize().width *2/3, Director::getInstance()->getVisibleSize().height *11/ 20));
				GameOverLayer->addChild(FinalScoreTTF);
					
				//显示最好成绩
				if (UserDefault::getInstance()->getIntegerForKey(FIRST_SCORE,0) < Score)//刷新记录
				{
// 			
					sprintf(BestScoreString, "%d", Score);
					LabelBMFont* BestScoreTTF = LabelBMFont::create(BestScoreString, SG14_FNT);
					BestScoreTTF->setColor(RED_RGB);
					BestScoreTTF->setPosition(Vec2(Director::getInstance()->getVisibleSize().width *2/3, Director::getInstance()->getVisibleSize().height*9/20));
					GameOverLayer->addChild(BestScoreTTF);
					RankingList[5].SocreData = Score;
					RankingList[5].PlaneDataPNG = BiuPlane.getPlanePNG();
					SaveRank();
				}
				else                                                                   //未刷新记录
				{
					sprintf(BestScoreString, "%d", UserDefault::getInstance()->getIntegerForKey(FIRST_SCORE));
					LabelBMFont* BestScoreTTF = LabelBMFont::create(BestScoreString, SG14_FNT);
					BestScoreTTF->setColor(WHITE_RGB);
					BestScoreTTF->setPosition(Vec2(Director::getInstance()->getVisibleSize().width *2 /3, Director::getInstance()->getVisibleSize().height *9/20));
					GameOverLayer->addChild(BestScoreTTF);
					RankingList[5].SocreData = Score;
					RankingList[5].PlaneDataPNG = BiuPlane.getPlanePNG();
					SaveRank();
				}
				
				break;
			}
	
		}
		//子弹和陨石碰撞
	int hitCombe = 0; //连击
	for (unsigned int j = 0; j < Meteorites.size(); j++)
	{
		for (unsigned int i = 0; i < Biu.size(); i++)
		{
			if (Biu.at(i).getSprite() != NULL && Meteorites.at(j).getSprite() != NULL)
			{
				if (CircleCollision(Biu.at(i).getSprite(), Meteorites.at(j).getSprite()))
				{

					if (Biu.at(i).getColor() == Meteorites.at(j).getColor())
					{
						Meteorites.at(j).LoseLife(BiuPlane);
						if (Meteorites.at(j).getLife() <= 0)
						{
							//连续击毁相同颜色陨石等分增加
							if (Meteorites.at(j).getColor() == upColor)
							{
								hitCombe++;
								Score += Meteorites.at(j).getScore() + hitCombe;
							}
							else
							{
								hitCombe = 0;
								Score += Meteorites.at(j).getScore();
							}
							//难度5下大陨石击毁后分裂
							if (Meteorites.at(j).getColorType() == MyColor::VeryBigRed || Meteorites.at(j).getColorType() == MyColor::VeryBigBlue || Meteorites.at(j).getColorType() == MyColor::VeryBigYellow)
							{
								int i = CCRANDOM_0_1() * 100;
								if (i < 50)
								{
									GetCoinAction((Meteorites.at(j).getSprite()));
								}
							}
							if (Meteorites.at(j).getBreak() == false && Level == Levelv5 && (Meteorites.at(j).getColorType() == MyColor::VeryBigRed || Meteorites.at(j).getColorType() == MyColor::VeryBigBlue || Meteorites.at(j).getColorType() == MyColor::VeryBigYellow))
							{
								AddTwoSmallMeteorites(Meteorites.at(j).getColorType(), Meteorites.at(j).getPosition(), BiuPlane.getPosition());
							}
							upColor = Meteorites.at(j).getColor();
							MeteoritesBOOM(Meteorites.at(j), Meteorites.at(j).getColorType());
							this->removeChild(Meteorites.at(j).getSprite());
							Meteorites.at(j).setSpriteNULL();
							DeleteMeteorites(j);
							if (MenuLayer_O::getIsOn())
							{
								MyAudio::PlayBoomEffict();
							}
						}
					}
					else
					{
						hitCombe = 0;
						Score--;
						if (Score < 0)
							Score = 0;
					}
					BiuBoom(Biu.at(i).getSprite()->getPosition(),Biu.at(i).getColorData());
					this->removeChild(Biu.at(i).getSprite());
					Biu.at(i).setSpriteNULL();
					DeleteBiu(i);
					break;
				}

			}
		}
	}
	//子弹飞出屏幕后销毁
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	for (unsigned int i = 0; i < Biu.size(); i++)
		{
		if (Biu.at(i).getSprite() != NULL)
		if (Biu.at(i).getPosition().x> MyWinSize.width|| Biu.at(i).getPosition().x < 0 || Biu.at(i).getPosition().y>MyWinSize.height || Biu.at(i).getPosition().y < 0)
		{
			if (Score < 0)
				Score = 0;
			this->removeChild((Biu.at(i)).getSprite());
			(Biu.at(i)).setSpriteNULL();
			DeleteBiu(i);
			break;
		}

	}
}
bool GameLayer_G::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	Point touchLocation = pTouch->getLocationInView();
	touchLocation = Director::getInstance()->convertToGL(touchLocation);
	TouchPoint = touchLocation;
	if (isPause == true)
		return false;
	BiuPlane.setRotation(TouchPoint);
	AddBiu();
	return true;
}
void GameLayer_G::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	Point touchLocation = pTouch->getLocationInView();
	touchLocation = Director::getInstance()->convertToGL(touchLocation);
	TouchPoint = touchLocation;
	BiuPlane.setRotation(TouchPoint);
	isTouchMoving = true;
}

void GameLayer_G::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	
	isTouchMoving = false;
	return;
}



void GameLayer_G::GamePause(Ref* pSender)
{
	if (isPause == false)
	{
		BackBtn->setScale(1.0f);
		ContinueBtn->setScale(1.0f);
		PauseBtn->setScale(0.1f);
		Director::getInstance()->pause();
		isPause = true;
		return;
	}
	else
	{
		BackBtn->setScale(0.01f);
		ContinueBtn->setScale(0.01f);
		PauseBtn->setScale(1.0f);
		Director::getInstance()->resume();
		isPause = false;
		return;

	}
}

void GameLayer_G::iSBlueBiu(Ref* pSender)
{
	BiuColorData = BiuColor::Blue;
	BiuState->setString("BLUE");
	BiuState->setColor(BLUE_RGB);
}
void GameLayer_G::iSRedBiu(Ref* pSender)
{
	BiuColorData = BiuColor::Red;
	BiuState->setString("RED");
	BiuState->setColor(RED_RGB);
}
void GameLayer_G::iSYellowBiu(Ref* pSender)
{
	BiuColorData = BiuColor::Yellow;
	BiuState->setString("YELLOW");
	BiuState->setColor(YELLOW_RGB);

}

void GameLayer_G::AddTwoSmallMeteorites(MyColor _color, Vec2 _position,Vec2 _PlanePosition)
{
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	ColorMeteorites SmallOne;
	ColorMeteorites SmallTwo;
	MyColor ColorType;
	switch (_color)
	{
	case VeryBigBlue:
		ColorType = VerySmallBlue;
		break;
	case VeryBigRed:
		ColorType = VerySmallRed;
		break;
	case VeryBigYellow:
		ColorType = VerySmallYellow;
		break;
	}


	SmallOne.CreateMyMeteorites(ColorType);
	SmallTwo.CreateMyMeteorites(ColorType);
	if (_position.x > _PlanePosition.x && _position.y > _PlanePosition.y)
	{
		SmallOne.setPosition(Vec2(_position.x - SmallOne.getSprite()->getContentSize().width / 2, _position.y + SmallOne.getSprite()->getContentSize().height / 2));
		SmallTwo.setPosition(Vec2(_position.x + SmallTwo.getSprite()->getContentSize().width / 2, _position.y - SmallTwo.getSprite()->getContentSize().height / 2));
	}
	else if (_position.x > _PlanePosition.x / 2 && _position.y < _PlanePosition.y)
	{
		SmallOne.setPosition(Vec2(_position.x + SmallOne.getSprite()->getContentSize().width / 2, _position.y + SmallOne.getSprite()->getContentSize().height / 2));
		SmallTwo.setPosition(Vec2(_position.x - SmallTwo.getSprite()->getContentSize().width / 2, _position.y - SmallTwo.getSprite()->getContentSize().height / 2));
	}
	else if (_position.x < _PlanePosition.x && _position.y > _PlanePosition.y)
	{
		SmallOne.setPosition(Vec2(_position.x + SmallOne.getSprite()->getContentSize().width / 2, _position.y + SmallOne.getSprite()->getContentSize().height / 2));
		SmallTwo.setPosition(Vec2(_position.x - SmallTwo.getSprite()->getContentSize().width / 2, _position.y - SmallTwo.getSprite()->getContentSize().height / 2));
	}
	else if (_position.x < _PlanePosition.x && _position.y < _PlanePosition.y)
	{
		SmallOne.setPosition(Vec2(_position.x - SmallOne.getSprite()->getContentSize().width / 2, _position.y + SmallOne.getSprite()->getContentSize().height / 2));
		SmallTwo.setPosition(Vec2(_position.x + SmallTwo.getSprite()->getContentSize().width / 2, _position.y - SmallTwo.getSprite()->getContentSize().height / 2));
	}
	Meteorites.push_back(SmallOne);
	Meteorites.back().setDirection(BiuPlane.getPosition());
	Meteorites.back().setSpeed();
	this->addChild(Meteorites.back().getSprite());

	Meteorites.push_back(SmallTwo);
	Meteorites.back().setDirection(BiuPlane.getPosition());
	Meteorites.back().setSpeed();
	this->addChild(Meteorites.back().getSprite());

}

void GameLayer_G::ReadRank()
{
	RankingList[0].SocreData = UserDefault::getInstance()->getIntegerForKey(FIRST_SCORE,0);
	RankingList[1].SocreData = UserDefault::getInstance()->getIntegerForKey(SECOND_SCORE,0);
	RankingList[2].SocreData = UserDefault::getInstance()->getIntegerForKey(THIRD_SOCRE,0);
	RankingList[3].SocreData = UserDefault::getInstance()->getIntegerForKey(FOURTH_SCORE,0);
	RankingList[4].SocreData = UserDefault::getInstance()->getIntegerForKey(FIFTH_SCORE,0);
	
	RankingList[0].PlaneDataPNG = UserDefault::getInstance()->getStringForKey(FIRST_PLANE,"");
	RankingList[1].PlaneDataPNG = UserDefault::getInstance()->getStringForKey(SECOND_PLANE, "");
	RankingList[2].PlaneDataPNG = UserDefault::getInstance()->getStringForKey(THIRD_PLANE, "");
	RankingList[3].PlaneDataPNG = UserDefault::getInstance()->getStringForKey(FOURTH_PLANE, "");
	RankingList[4].PlaneDataPNG = UserDefault::getInstance()->getStringForKey(FIFTH_PLANE, "");

}

void GameLayer_G::SaveRank()
{
	int i, j;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (RankingList[i].SocreData>RankingList[j].SocreData)
			{
				RankingData Temp;
				Temp = RankingList[i];
				RankingList[i] = RankingList[j];
				RankingList[j] = Temp;
			}

		}
	}
	UserDefault::getInstance()->setIntegerForKey(FIRST_SCORE, RankingList[0].SocreData);
	UserDefault::getInstance()->setIntegerForKey(SECOND_SCORE, RankingList[1].SocreData);
	UserDefault::getInstance()->setIntegerForKey(THIRD_SOCRE, RankingList[2].SocreData);
	UserDefault::getInstance()->setIntegerForKey(FOURTH_SCORE, RankingList[3].SocreData);
	UserDefault::getInstance()->setIntegerForKey(FIFTH_SCORE, RankingList[4].SocreData);

	UserDefault::getInstance()->setStringForKey(FIRST_PLANE, RankingList[0].PlaneDataPNG);
	UserDefault::getInstance()->setStringForKey(SECOND_PLANE, RankingList[1].PlaneDataPNG);
	UserDefault::getInstance()->setStringForKey(THIRD_PLANE, RankingList[2].PlaneDataPNG);
	UserDefault::getInstance()->setStringForKey(FOURTH_PLANE, RankingList[3].PlaneDataPNG);
	UserDefault::getInstance()->setStringForKey(FIFTH_PLANE, RankingList[4].PlaneDataPNG);
}

void GameLayer_G::AddFinger(Vec2 _position)
{
	Finger = Sprite::createWithSpriteFrameName(FINGER_PNG);
	Finger->setPosition(_position.x, _position.y + Finger->getContentSize().height + 30);
	Finger->setScale(1.5);
	MoveTo* MoveOne = MoveTo::create(0.5, Vec2(Finger->getPosition().x, Finger->getPosition().y - 5));
	MoveTo* MoveTwo = MoveTo::create(0.5, Finger->getPosition());
	Sequence* FingerMoving = Sequence::create(MoveOne, MoveTwo, NULL);
	Repeat* FingerMovingRepeat = Repeat::create(FingerMoving,5);
	CallFunc* ReMoveFingerMoving = CallFunc::create(this, callfunc_selector(GameLayer_G::RemoveFinger));
	Sequence* AllFingerAction = Sequence::create(FingerMovingRepeat, ReMoveFingerMoving, NULL);
	this->addChild(Finger,5);
	Finger->runAction(AllFingerAction);
}

void GameLayer_G::RemoveFinger()
{
	this->removeChild(Finger);
}

void GameLayer_G::BiuBoom(Vec2 _position,BiuColor _colordata)
{
	ParticleSystem *BiuBoomMeteorites = ParticleSystemQuad::create("BiuBOOM.plist");
	BiuBoomMeteorites->setTexture(TextureCache::getInstance()->addImage("BiuBOOM.png"));
	BiuBoomMeteorites->setPosition(_position);
	BiuBoomMeteorites->setAutoRemoveOnFinish(true);
	switch (_colordata)
	{
	case Blue:
		BiuBoomMeteorites->setStartColor(Color4F(0, 0, 255, 255));
		break;
	case Red:
		BiuBoomMeteorites->setStartColor(Color4F(255, 0, 100, 255));
		break;
	case Yellow:
		BiuBoomMeteorites->setStartColor(Color4F(128, 255,0 , 255));
		break;
	default:
		break;
	}
	
	this->addChild(BiuBoomMeteorites, 5,1);
}

void GameLayer_G::MeteoritesBOOM(ColorMeteorites _meteoritesdata,MyColor _colordata)
{
	ParticleSystem* MeteotritesBoomBiu = ParticleSystemQuad::create("MeteoritesBOOM.plist");
	MeteotritesBoomBiu->setTexture(TextureCache::getInstance()->addImage("MeteoritesBOOM.png"));
	MeteotritesBoomBiu->setAutoRemoveOnFinish(true);
 	MeteotritesBoomBiu->setPosition(_meteoritesdata.getSprite()->getPosition());
 	MeteotritesBoomBiu->setStartSize(_meteoritesdata.getSprite()->getContentSize().width);
	MeteotritesBoomBiu->setSpeedVar(25);
	MeteotritesBoomBiu->setStartColorVar(Color4F(0, 0, 0, 0));
	switch (_colordata)
	{
	case VerySmallBlue:
		MeteotritesBoomBiu->setStartColor(BLUE_RGBA);
		MeteotritesBoomBiu->setSpeed(75);
		break;
	case VeryBigBlue:
		MeteotritesBoomBiu->setStartColor(BLUE_RGBA);
		MeteotritesBoomBiu->setSpeed(175);
		break;
	case VerySmallRed:
		MeteotritesBoomBiu->setStartColor(RED_RGBA);
		MeteotritesBoomBiu->setSpeed(75);
		break;
	case VeryBigRed:
		MeteotritesBoomBiu->setStartColor(RED_RGBA);
		MeteotritesBoomBiu->setSpeed(175);
		break;
	case VeryBigYellow:
		MeteotritesBoomBiu->setStartColor(YELLOW_RGBA);
		MeteotritesBoomBiu->setSpeed(175);
		break;
	case VerySmallYellow:
		MeteotritesBoomBiu->setStartColor(YELLOW_RGBA);
		MeteotritesBoomBiu->setSpeed(75);
		break;
	case BigYellow:
		MeteotritesBoomBiu->setStartColor(YELLOW_RGBA);
		MeteotritesBoomBiu->setSpeed(150);
		break;
	case SmallYellow:
		MeteotritesBoomBiu->setStartColor(YELLOW_RGBA);
		MeteotritesBoomBiu->setSpeed(100);
		break;
	case MiddleYellow:
		MeteotritesBoomBiu->setStartColor(YELLOW_RGBA);
		MeteotritesBoomBiu->setSpeed(125);
		break;
	}
	this->addChild(MeteotritesBoomBiu,5);
}

void GameLayer_G::PlaneBOOM(Vec2 _position)
{
	ParticleSystem* MeteoritesBoomPlane = ParticleSystemQuad::create("PlaneBOOM.plist");
	MeteoritesBoomPlane->setTexture(TextureCache::getInstance()->addImage("MeteoritesBOOM.png"));
	MeteoritesBoomPlane->setTotalParticles(500);
	MeteoritesBoomPlane->setLife(1);
	MeteoritesBoomPlane->setPosition(_position);
	//MeteoritesBoomPlane->setStartSize(100);
	MeteoritesBoomPlane->setAutoRemoveOnFinish(true);
	this->addChild(MeteoritesBoomPlane,5);
}

void GameLayer_G::MeteoritesBreak(ColorMeteorites _colormeteorites)
{
	SpriteFrameCache* Cache = SpriteFrameCache::getInstance();
	Cache->addSpriteFramesWithFile("MeteoritesBreak.plist", "MeteoritesBreak.png");
	int i;
	char PNGName[40];
	Vector<SpriteFrame*> BreakSpriteFrame;
	switch (_colormeteorites.getColorType())
	{
	case VeryBigBlue:
		for (i = 1; i <= 7; i++)
		{
			sprintf(PNGName, "BlueMeteoritesBreakPart%d.png", i);
			SpriteFrame* MeteoritesBreakActionPart = Cache->spriteFrameByName(PNGName);
			BreakSpriteFrame.pushBack(MeteoritesBreakActionPart);
		}
		break;
	case VeryBigRed:
		for (i = 1; i <= 7; i++)
		{
			sprintf(PNGName, "RedMeteoritesBreakPart%d.png", i);
			SpriteFrame* MeteoritesBreakActionPart = Cache->spriteFrameByName(PNGName);
			BreakSpriteFrame.pushBack(MeteoritesBreakActionPart);
		}
		break;
	case VeryBigYellow:
		for (i = 1; i <= 7; i++)
		{
			sprintf(PNGName, "YellowMeteoritesBreakPart%d.png", i);
			SpriteFrame* MeteoritesBreakActionPart = Cache->spriteFrameByName(PNGName);
			BreakSpriteFrame.pushBack(MeteoritesBreakActionPart);
		}
		break;

	}
	
	Animation* BreakAnimation = Animation::createWithSpriteFrames(BreakSpriteFrame,0.1f);
	Animate* BreakAnimate = Animate::create(BreakAnimation);
	CallFunc* BreakCallBack = CallFunc::create(this,callfunc_selector(GameLayer_G::MeteoritesDeleteCallBack));
	Sequence* BreakSquence = Sequence::create(BreakAnimate, BreakCallBack, NULL);
	_colormeteorites.getSprite()->runAction(BreakSquence);
}

void GameLayer_G::MeteoritesDeleteCallBack()
{
	this->removeChild(Meteorites.at(BreakNumber).getSprite());
	Meteorites.at(BreakNumber).setSpriteNULL();
	DeleteMeteorites(BreakNumber);
}
void GameLayer_G::ScreenShake(Layer* _layer)
{
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	float ShakeX_Var;
	float ShakeY_Var;
	int i;
	std::vector<MoveBy*>ShakeSequence;
	for (i = 0; i < 12; i++)
	{
		ShakeX_Var = CCRANDOM_MINUS1_1()*2;
		ShakeY_Var = CCRANDOM_MINUS1_1()*2;
		MoveTo* ScreenMoveBy = MoveTo::create(0.02, Vec2( ShakeX_Var, ShakeY_Var));
		ShakeSequence.push_back(ScreenMoveBy);
	}
	Sequence* Shake = Sequence::create(
		ShakeSequence.at(0),
		ShakeSequence.at(1),
		ShakeSequence.at(2),
		ShakeSequence.at(3),
		ShakeSequence.at(4),
		ShakeSequence.at(5),
		ShakeSequence.at(6),
		ShakeSequence.at(7),
		ShakeSequence.at(8),
		ShakeSequence.at(9),
		ShakeSequence.at(10),
		ShakeSequence.at(11),
		NULL);
	this->runAction(Shake);
	_layer->runAction(Shake);
}

void GameLayer_G::GetCoinAction(Sprite* _sprite)
{
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	CoinData CoinExample;
	Vec2 position = _sprite->getPosition();
	CoinExample.Coin= Sprite::createWithSpriteFrameName("Coin.png");
	CoinExample.Coin->setPosition(position);
	CoinExample.isGet = true;
	DelayTime* CoinDelayTime = DelayTime::create(2);
	MoveTo* CoinMoveTo = MoveTo::create(2, CoinSprite->getPosition());
	FadeOut* CoinFedaOut = FadeOut::create(2);
	EaseExponentialOut* CoinEaseExponentialOut = EaseExponentialOut::create(CoinMoveTo);
	Spawn* CoinSpawn = Spawn::create(CoinEaseExponentialOut, CoinFedaOut, NULL);
	CallFunc* CoinCallBack = CallFunc::create(this,callfunc_selector(GameLayer_G::GetCoinCallBack));
	Sequence* CoinSequence = Sequence::create(CoinDelayTime, CoinSpawn, CoinCallBack, NULL);

	MyCoin.push_back(CoinExample);
	this->addChild(MyCoin.back().Coin, 4);
	MyCoin.back().Coin->runAction(CoinSequence);
}

void GameLayer_G::GetCoinCallBack()
{
	int NowCoin = UserDefault::getInstance()->getIntegerForKey(COIN_NUM) + 1 * BiuPlane.getPlaneCoin();
		UserDefault::getInstance()->setIntegerForKey(COIN_NUM, NowCoin);
	sprintf(CoinNumber, "%d", UserDefault::getInstance()->getIntegerForKey(COIN_NUM, 0));
	CoinBMFont->setString(CoinNumber);
}



