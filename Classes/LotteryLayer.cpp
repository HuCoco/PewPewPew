#include "LotteryLayer.h"
NetTime* LotteryLayer::MyTime = new NetTime;
PrizeTimeINT LotteryLayer::NowTime = { 0, 0, 0, 0, 0, 0 };
PrizeTimeINT LotteryLayer::LastTime = { 0, 0, 0, 0, 0, 0 };
LotteryLayer::LotteryLayer()
{
	PullBarisWork = false;
	PrizeSpeed = 1;
	SpeedUp = 0.2;
	GetPrizeBool = true;
	GoTiME = 0;
	isCoinBlink = false;
	isCoinAction = true;
}



LotteryLayer::~LotteryLayer()
{
	MyTime->~NetTime();
}

PrizeTimeINT LotteryLayer::getNowTime()
{
	return NowTime;
}

PrizeTimeINT LotteryLayer::getLastTime()
{
	return LastTime;
}


void LotteryLayer::NowTimeinit()
{
	MyTime->SetLocalTime();
}

void LotteryLayer::SetTime()
{
	NowTime.Year = MyTime->GetYear();
	NowTime.Month = MyTime->GetMouth();
	NowTime.Day = MyTime->GetDay();
	NowTime.Hour = MyTime->GetHour();
	NowTime.Minute = MyTime->GetMinute();
	NowTime.Second = MyTime->GetSecond();

}
void LotteryLayer::SaveTime()
{
	UserDefault::getInstance()->setIntegerForKey(YEAR, NowTime.Year);
	UserDefault::getInstance()->setIntegerForKey(MONTH, NowTime.Month);
	UserDefault::getInstance()->setIntegerForKey(DAY, NowTime.Day);
	UserDefault::getInstance()->setIntegerForKey(HOUR, NowTime.Hour);
	UserDefault::getInstance()->setIntegerForKey(MINUTE, NowTime.Minute);
	UserDefault::getInstance()->setIntegerForKey(SECOND, NowTime.Second);
}

void LotteryLayer::ReadTime()
{
	LastTime.Year = UserDefault::getInstance()->getIntegerForKey(YEAR, 0);
	LastTime.Month = UserDefault::getInstance()->getIntegerForKey(MONTH, 0);
	LastTime.Day = UserDefault::getInstance()->getIntegerForKey(DAY, 0);
	LastTime.Hour = UserDefault::getInstance()->getIntegerForKey(HOUR, 0);
	LastTime.Minute = UserDefault::getInstance()->getIntegerForKey(MINUTE,0);
	LastTime.Second = UserDefault::getInstance()->getIntegerForKey(SECOND, 0);
}

bool LotteryLayer::isFullTime(int _time)
{
	int NowTimeHour;
	if (NowTime.Day > LastTime.Day)
	{
		NowTimeHour = NowTime.Hour + 24;
	}
	else
	{
		NowTimeHour = NowTime.Hour;
	}
	if (NowTime.Year - LastTime.Year > 0 || NowTime.Month - LastTime.Month > 0)
	{
		return true;
	}
	else if (
		((NowTimeHour - LastTime.Hour) * 60 * 60 +
		(NowTime.Minute - LastTime.Minute) * 60 +
		NowTime.Second - LastTime.Second)
		> _time)
	{
		return true;
	}

	return	false;

}
void LotteryLayer::SaveNextTime(int _hour,int _minute)
{
	UserDefault::getInstance()->setIntegerForKey(NEXT_YEAR, LastTime.Year);
	UserDefault::getInstance()->setIntegerForKey(NEXT_MONTH, LastTime.Month);
	UserDefault::getInstance()->setIntegerForKey(NEXT_DAY, LastTime.Day);
	UserDefault::getInstance()->setIntegerForKey(NEXT_HOUR, LastTime.Hour+_hour);
	UserDefault::getInstance()->setIntegerForKey(NEXT_MINUTE, LastTime.Minute+_minute);
	UserDefault::getInstance()->setIntegerForKey(NEXT_SECOND, LastTime.Second);
}



bool LotteryLayer::IsCan()
{
	int LotteryNumber = UserDefault::getInstance()->getIntegerForKey(LOTTERY_NUMBER, 0);
	switch (LotteryNumber)
	{
	case 0:
		UserDefault::getInstance()->setIntegerForKey(WAIT_TIME, 0);
		return true;
	case 1:
		UserDefault::getInstance()->setIntegerForKey(WAIT_TIME, THREE_MINUTES);
		return isFullTime(THREE_MINUTES);
	case 2:
		UserDefault::getInstance()->setIntegerForKey(WAIT_TIME, HALF_HOUR);
		return isFullTime(HALF_HOUR);
	case 3:
		UserDefault::getInstance()->setIntegerForKey(WAIT_TIME, A_HOUR);
		return isFullTime(A_HOUR);
	case 4:
		UserDefault::getInstance()->setIntegerForKey(WAIT_TIME, THREE_HOURS);
		return isFullTime(THREE_HOURS);
	default:
		UserDefault::getInstance()->setIntegerForKey(WAIT_TIME, SIX_HOURS);
		return isFullTime(SIX_HOURS);
	}
}



bool LotteryLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//´¥ÃþÊÂ¼þ
	ReadTime();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//Coin
	Sprite* CoinSprite = Sprite::createWithSpriteFrameName("Coin.png");
	CoinSprite->setPosition(CoinSprite->getContentSize().width, visibleSize.height - CoinSprite->getContentSize().height);
	this->addChild(CoinSprite,5);

	sprintf(CoinNumber, "%d", UserDefault::getInstance()->getIntegerForKey(COIN_NUM, 0));
	CoinBMFont = LabelBMFont::create(CoinNumber, SG14_FNT);
	CoinBMFont->setAnchorPoint(Vec2(0, 0.5));
	CoinBMFont->setPosition(CoinSprite->getContentSize().width + 30, visibleSize.height  - CoinSprite->getContentSize().height );
	this->addChild(CoinBMFont, 5);
	BackBtn =
		MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(BACK_BTN_PNG),
		Sprite::createWithSpriteFrameName(BACK_BTN_DOWN_PNG),
		NULL,
		this,
		menu_selector(HeadScene::GotoHeadScene));
	BackBtn->setPosition(visibleSize.width - BackBtn->getContentSize().width / 2 - 5, visibleSize.height - BackBtn->getContentSize().height / 2 - 5);


	Menu* menu = Menu::create(BackBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu,5);

	auto touch_listener = EventListenerTouchOneByOne::create();
	touch_listener->setSwallowTouches(false);
	touch_listener->onTouchBegan = CC_CALLBACK_2(LotteryLayer::onTouchBegan, this);
	touch_listener->onTouchMoved = CC_CALLBACK_2(LotteryLayer::onTouchMoved, this);
	touch_listener->onTouchEnded = CC_CALLBACK_2(LotteryLayer::onTouchEnded, this);
	touch_listener->onTouchCancelled = CC_CALLBACK_2(LotteryLayer::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch_listener, this);


	Size MyWinSize = Director::getInstance()->getVisibleSize();


	LotteryLayer::ReadTime();
	LotteryLayer::NowTimeinit();
	LotteryLayer::SetTime();
	int NowTimeHour;
	if (!LotteryLayer::IsCan())
	{
		Layer* CantLotteryLayer = Layer::create();
		Sprite* PopupBGI = Sprite::createWithSpriteFrameName("PopupBGI.png");
		PopupBGI->setPosition(MyWinSize.width / 2, MyWinSize.height / 2);
		CantLotteryLayer->addChild(PopupBGI, 1);
		if (LotteryLayer::getNowTime().Day > LotteryLayer::getLastTime().Day)
		{
			NowTimeHour = LotteryLayer::getNowTime().Hour + 24;
		}
		else
		{
			NowTimeHour = LotteryLayer::getNowTime().Hour;
		}
		int waittime = UserDefault::getInstance()->getIntegerForKey(WAIT_TIME);
		int timegoesby = (NowTimeHour - LotteryLayer::getLastTime().Hour) * 60 * 60 +
			(LotteryLayer::getNowTime().Minute - LotteryLayer::getLastTime().Minute) * 60 +
			LotteryLayer::getNowTime().Second - LotteryLayer::getLastTime().Second;
		int Sec = (waittime - timegoesby) % 60;
		int Min = (waittime - timegoesby) / 60 % 60;
		int Hour = (waittime - timegoesby) / 3600;
		std::string TimeBMF = String::createWithFormat("Next In %d:%d:%d", Hour, Min, Sec)->getCString();
		TimeBMFont = LabelBMFont::create(TimeBMF, SG14_FNT);
		TimeBMFont->setPosition(MyWinSize.width / 2,MyWinSize.height / 2 );
		CantLotteryLayer->addChild(TimeBMFont, 4);
		this->addChild(CantLotteryLayer,10);
		this->schedule(schedule_selector(LotteryLayer::TimeUpdate), 1);
	}


	BGImage_One = Sprite::createWithSpriteFrameName(LOTTERY_BGI_PNG);
	BGImage_One->setPosition(Vec2(MyWinSize.width / 2, MyWinSize.height / 2));
	this->addChild(BGImage_One,2);


	Sprite* Part1 = Sprite::createWithSpriteFrameName(LOTTERY_PART1_PNG);
	Part1->setPosition(MyWinSize.width / 2, MyWinSize.height / 5 * 2);
	this->addChild(Part1,2);

	Sprite* Part2 = Sprite::createWithSpriteFrameName(LOTTERY_PART2_PNG);
	Part2->setPosition(MyWinSize.width / 2, MyWinSize.height / 5 * 2);
	this->addChild(Part2, 3);

	Sprite* Title = Sprite::createWithSpriteFrameName(LOTTERY_TITLE_PNG);
	Title->setPosition(MyWinSize.width / 2, MyWinSize.height * 0.82);
	this->addChild(Title,4);

	Sprite* WinPart1 = Sprite::createWithSpriteFrameName(WINDOWS_PNG);
	WinPart1->setPosition(MyWinSize.width * 0.403, MyWinSize.height *0.437);
	this->addChild(WinPart1,1);
	

	Sprite* WinPart2 = Sprite::createWithSpriteFrameName(WINDOWSFRAME_PNG);
	WinPart2->setPosition(MyWinSize.width * 0.403, MyWinSize.height*0.433);
	this->addChild(WinPart2, 4);

	Sprite* RightArrow = Sprite::createWithSpriteFrameName("Arrow.png");
	RightArrow->setPosition(MyWinSize.width * 0.403 + WinPart2->getContentSize().width/2-15, MyWinSize.height*0.433);
	this->addChild(RightArrow, 4);

	Sprite* LiftArrow = Sprite::createWithSpriteFrameName("Arrow.png");
	LiftArrow->setPosition(MyWinSize.width * 0.403 - WinPart2->getContentSize().width / 2 + 15, MyWinSize.height*0.433);
	LiftArrow->setRotation(180);
	this->addChild(LiftArrow, 4);


	Sprite* OutPart = Sprite::createWithSpriteFrameName(OUT_PNG);
	OutPart->setPosition(MyWinSize.width*0.4, MyWinSize.height*0.18);
	this->addChild(OutPart,4);

	LabelBMFont* NeedCoinBMFont = LabelBMFont::create("100", SG14_FNT);
	NeedCoinBMFont->setPosition(MyWinSize.width*0.8+10, MyWinSize.height / 3);
	NeedCoinBMFont->setScale(0.8);
	NeedCoinBMFont->setColor(YELLOW_RGB);
	this->addChild(NeedCoinBMFont, 4);
	Sprite* CoinNeed = Sprite::createWithSpriteFrameName("Coin.png");
	CoinNeed->setPosition(MyWinSize.width*0.8 - NeedCoinBMFont->getContentSize().width/2-10, MyWinSize.height / 3);
	this->addChild(CoinNeed, 4);

	Sprite* PullBarBase = Sprite::createWithSpriteFrameName(PULL_BAR_BASE_PNG);
	PullBarBase->setPosition(MyWinSize.width*0.77, MyWinSize.height*0.22);
	this->addChild(PullBarBase,4);

	PullBarPart1 = Sprite::createWithSpriteFrameName(PULL_BAR_PART1_PNG);
	PullBarPart1->setPosition(MyWinSize.width*0.7676, MyWinSize.height*0.23);
	this->addChild(PullBarPart1, 4);

	PullBarPart2 = Sprite::createWithSpriteFrameName(PULL_BAR_PART2_PNG);
	PullBarPart2->setPosition(MyWinSize.width * 0.7676, MyWinSize.height*0.27);
	this->addChild(PullBarPart2, 4);
	GoTiME = CCRANDOM_0_1() * 40 + 40;
	if (UserDefault::getInstance()->getBoolForKey(IS_GET_BATTLECRUISER, 0) == true &&
		UserDefault::getInstance()->getBoolForKey(IS_GET_VIKING, 0) == true &&
		UserDefault::getInstance()->getBoolForKey(IS_GET_BANSHEE, 0) == true &&
		UserDefault::getInstance()->getBoolForKey(IS_GET_VOIDRAY,0) == true &&
		UserDefault::getInstance()->getBoolForKey(IS_GET_PHOENIX,0) == true)
	{
		Prizeinit(11);
	}
	else
	{
		Prizeinit(5);
	}
	
	
	NowTimeinit();
 	SetTime();
	
	
 	

	return true;

	
}

void LotteryLayer::PlayPullBarAction()
{
	if (PullBarisWork == false)
	{
		SaveTime();
		ReadTime();
		PullBarisWork = true;
		Vec2 PartOnePosition = PullBarPart1->getPosition();
		MoveTo* PullBarPart1Up = MoveTo::create(0.5f, Vec2(PartOnePosition.x, PartOnePosition.y - 30));
		MoveTo* PullBarPart1Down = MoveTo::create(0.7f, PartOnePosition);
		Sequence* PullBarPart1Action = Sequence::create(PullBarPart1Up, PullBarPart1Down, NULL);
		CallFunc* setPullBarCallBack = CallFunc::create(this,callfunc_selector(LotteryLayer::setPullBar));
		Vec2 PartTwoPosition = PullBarPart2->getPosition();
		MoveTo* PullBarPart2Up = MoveTo::create(0.5f, Vec2(PartOnePosition.x, PartOnePosition.y - 80));
		MoveTo* PullBarPart2Down = MoveTo::create(0.7f, PartTwoPosition);
		Sequence* PullBarPart2Action = Sequence::create(PullBarPart2Up, PullBarPart2Down,setPullBarCallBack, NULL);
		PullBarPart1->runAction(PullBarPart1Action);
		PullBarPart2->runAction(PullBarPart2Action);
		int LotteryNumber = UserDefault::getInstance()->getIntegerForKey(LOTTERY_NUMBER, 0)+1;
		UserDefault::getInstance()->setIntegerForKey(LOTTERY_NUMBER, LotteryNumber);
		CostCoin();
	}
}


bool LotteryLayer::onTouchBegan(Touch* pTouch, Event* pEvent)
{
	Point touchLocation = pTouch->getLocationInView();
	touchLocation = Director::getInstance()->convertToGL(touchLocation);
	if (IsCan() && UserDefault::getInstance()->getIntegerForKey(COIN_NUM, 0) - 100 >= 0)
	{
		return true;
	}
	else if (UserDefault::getInstance()->getIntegerForKey(COIN_NUM, 0) - 100 < 0 && isCoinBlink == false)
	{
		CoinNotEnough();
		return false;
	}
	else if (!IsCan())
	{
		return false;
	}
}
void LotteryLayer::onTouchMoved(Touch* pTouch, Event* pEvent)
{
	PlayPullBarAction();
}

void LotteryLayer::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	

	return;
}
void LotteryLayer::setPullBar()
{
	//PullBarisWork = false;
	this->schedule(schedule_selector(LotteryLayer::GoGift));
}
void LotteryLayer::GoGift(float dt)
{	
	
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	int i;
	for (i = 0; i < NumPrize; i++)
	{
		PrizeVector.at(i).Prize->setPositionY(PrizeVector.at(i).Prize->getPositionY() - PrizeSpeed);
	}
	for (i = 0; i < NumPrize; i++)
	{
		if (PrizeVector.at(i).Prize->getPositionY() < MyWinSize.height*0.32 - PrizeVector.at(i).Prize->getContentSize().height)
		{
			PrizeVector.at(i).Prize->setPositionY(
				i == 0 ?
				PrizeVector.back().Prize->getPositionY() + PrizeVector.back().Prize->getContentSize().height :
				PrizeVector.at(i-1).Prize->getPositionY() + PrizeVector.at(i).Prize->getContentSize().height);
		}
	}
	if (PrizeSpeed > GoTiME)
	{
		SpeedUp = -0.2;
	}
	PrizeSpeed += SpeedUp;
	if (PrizeSpeed <= 0)
	{
		PrizeSpeed = 0;
		SpeedUp = 0;
		if (GetPrizeBool == true)
		{
			GetPrize();
			GetPrizeBool = false;
		}

	}
	
}

void LotteryLayer::Prizeinit(int _num_prize)
{
	NumPrize = _num_prize;
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	PrizeData PrizeExmaple;
	int i, k;
	bool* Used = new bool[_num_prize];
	for (i = 0; i < _num_prize; i++)
	{
		Used[i] = 0;
	}
	for (i = 0; i < _num_prize; i++)
	{
		k = CCRANDOM_0_1()*(_num_prize-1);
		switch (k)
		{
		case 0:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(BANSHEE_PRIZE);
			PrizeExmaple.PrizePNG = BANSHEE;
			PrizeExmaple.PrizeName = "BanShee";
			PrizeExmaple.PrizeGet = IS_GET_BANSHEE;
			break;
		case 1:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(BATTLECRUISER_PRIZE);
			PrizeExmaple.PrizePNG = BATTLECRUISER;
			PrizeExmaple.PrizeName = "BattleCruiser";
			PrizeExmaple.PrizeGet = IS_GET_BATTLECRUISER;
			break;
		case 2:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(VIKING_PRIZE);
			PrizeExmaple.PrizePNG = VIKING;
			PrizeExmaple.PrizeName = "Viking";
			PrizeExmaple.PrizeGet = IS_GET_VIKING;
			break;
		case 3:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(PHOENIX_PRIZE);
			PrizeExmaple.PrizePNG = PHOENIX;
			PrizeExmaple.PrizeName = "Tempest";
			PrizeExmaple.PrizeGet = IS_GET_PHOENIX;
			break;
		case 4:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(VOIDRAY_PRIZE);
			PrizeExmaple.PrizePNG = VOIDRAY;
			PrizeExmaple.PrizeName = "Tempest";
			PrizeExmaple.PrizeGet = IS_GET_VOIDRAY;
			break;
		case 5:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(BANSHEE_PRIZE_S);
			PrizeExmaple.PrizePNG = BANSHEE;
			PrizeExmaple.PrizeName = "BanShee+";
			PrizeExmaple.PrizeGet = IS_GET_BANSHEE_S;
			break;
		case 6:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(BATTLECRUISER_PRIZE_S);
			PrizeExmaple.PrizePNG = BATTLECRUISER;
			PrizeExmaple.PrizeName = "BattleCruiser+";
			PrizeExmaple.PrizeGet = IS_GET_BATTLECRUISER_S;
			break;
		case 7:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(VIKING_PRIZE_S);
			PrizeExmaple.PrizePNG = VIKING;
			PrizeExmaple.PrizeName = "Viking+";
			PrizeExmaple.PrizeGet = IS_GET_VIKING_S;
			break;
		case 8:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(PHOENIX_PRIZE_S);
			PrizeExmaple.PrizePNG = PHOENIX_PRIZE_S;
			PrizeExmaple.PrizeName = "Phoenix+";
			PrizeExmaple.PrizeGet = IS_GET_PHOENIX;
			break;
		case 9:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(VOIDRAY_PRIZE_S);
			PrizeExmaple.PrizePNG = VOIDRAY_PRIZE_S;
			PrizeExmaple.PrizeName = "VoidRay+";
			PrizeExmaple.PrizeGet = IS_GET_VOIDRAY;
			break;
		case 10:
			PrizeExmaple.Prize = Sprite::createWithSpriteFrameName(TEMPEST_PRIZE);
			PrizeExmaple.PrizePNG = TEMPEST_PRIZE;
			PrizeExmaple.PrizeName = "Tempest";
			PrizeExmaple.PrizeGet = IS_GET_TEMPEST;
			break;
		}
		Used[k] = 1;
		if (i == 0)
		{
			PrizeExmaple.Prize->setPosition(MyWinSize.width*0.403, MyWinSize.height*0.32 );
		}
		else
		{
			PrizeExmaple.Prize->setPosition(PrizeVector.back().Prize->getPositionX(), PrizeVector.back().Prize->getPositionY() + PrizeExmaple.Prize->getContentSize().height);
		}
		PrizeVector.push_back(PrizeExmaple);
		this->addChild(PrizeVector.back().Prize,1);
	}
}

void LotteryLayer::GetPrize()
{
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	Point Center = Vec2(MyWinSize.width * 0.403, MyWinSize.height*0.433);
	float MinLength = 999;
	PrizeData MyPrize;
	int i;
	for (i = 0; i < 4; i++)
	{
		int NowLength = abs(PrizeVector.at(i).Prize->getPosition().y - Center.y);
		if (NowLength < MinLength)
		{
			MinLength = NowLength;
			MyPrize = PrizeVector.at(i);
		}
	}
	Layer* GetPrizeLayer = Layer::create();
	Sprite* PopupWindow = Sprite::createWithSpriteFrameName("PopupWindow.png");
	PopupWindow->setPosition(MyWinSize.width / 2, MyWinSize.height / 2);
	GetPrizeLayer->addChild(PopupWindow, 2);
	Sprite* PopupBGI = Sprite::createWithSpriteFrameName("PopupBGI.png");
	PopupBGI->setPosition(MyWinSize.width / 2, MyWinSize.height / 2);
	GetPrizeLayer->addChild(PopupBGI, 1);
	Sprite* PrizePlane = Sprite::createWithSpriteFrameName(MyPrize.PrizePNG);
	PrizePlane->setPosition(MyWinSize.width / 2, MyWinSize.height / 2 + PrizePlane->getContentSize().height);
	PrizePlane->setScale(2);
	GetPrizeLayer->addChild(PrizePlane, 3);
	LabelBMFont* PlaneName = LabelBMFont::create(MyPrize.PrizeName, SG14_FNT);
	PlaneName->setPosition(MyWinSize.width / 2, MyWinSize.height / 2 - PlaneName->getContentSize().height);
	GetPrizeLayer->addChild(PlaneName, 3);
	BackBtn->setScale(0.01f);
	MenuItemSprite* OKBtn = MenuItemSprite::create(
		Sprite::createWithSpriteFrameName(OK_BTN),
		Sprite::createWithSpriteFrameName(OK_BTN_DOWN),
		NULL,
		this,
		menu_selector(HeadScene::GotoHeadScene));
	OKBtn->setPosition(MyWinSize.width / 2, MyWinSize.height / 2 - PlaneName->getContentSize().height - OKBtn->getContentSize().height);
	Menu* menu = Menu::create(OKBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu,5);
	UserDefault::getInstance()->setBoolForKey(MyPrize.PrizeGet, true);
	this->addChild(GetPrizeLayer,4);

}

void LotteryLayer::CoinNotEnough()
{
	isCoinBlink = true;
	CallFunc* CoinBMFontCallBack = CallFunc::create(this, callfunc_selector(LotteryLayer::CoinCallBack));
	Blink* CoinBMFontBlink = Blink::create(0.5, 6);
	Sequence* CoinSequence = Sequence::create(CoinBMFontBlink, CoinBMFontCallBack, NULL);
	CoinBMFont->runAction(CoinSequence);
}

void LotteryLayer::CostCoin()
{
	isCoinAction = true;
	UserDefault::getInstance()->setIntegerForKey(COIN_NUM, UserDefault::getInstance()->getIntegerForKey(COIN_NUM) - 100);
	ScaleTo* CoinBMFontScaleToOne = ScaleTo::create(0.3f, 1.3f);
	ScaleTo* CoinBMFontScaleToTwo = ScaleTo::create(0.3f, 1.0f);
	Sequence* CoinBMFontSequence = Sequence::create(CoinBMFontScaleToOne,CoinBMFontScaleToTwo,NULL);
	CoinBMFont->runAction(CoinBMFontSequence);
}

void LotteryLayer::TimeUpdate(float dt)
{
	LotteryLayer::ReadTime();
	LotteryLayer::NowTimeinit();
	LotteryLayer::SetTime();
	int NowTimeHour;
	if (!LotteryLayer::IsCan())
	{
		if (LotteryLayer::getNowTime().Day > LotteryLayer::getLastTime().Day)
		{
			NowTimeHour = LotteryLayer::getNowTime().Hour + 24;
		}
		else
		{
			NowTimeHour = LotteryLayer::getNowTime().Hour;
		}
		int waittime = UserDefault::getInstance()->getIntegerForKey(WAIT_TIME);
		int timegoesby = (NowTimeHour - LotteryLayer::getLastTime().Hour) * 60 * 60 +
			(LotteryLayer::getNowTime().Minute - LotteryLayer::getLastTime().Minute) * 60 +
			LotteryLayer::getNowTime().Second - LotteryLayer::getLastTime().Second;
		int Sec = (waittime - timegoesby) % 60;
		int Min = (waittime - timegoesby) / 60 % 60;
		int Hour = (waittime - timegoesby) / 3600;
		std::string TimeBMF = String::createWithFormat("Next In %d:%d:%d", Hour, Min, Sec)->getCString();
		TimeBMFont->setString(TimeBMF);
	}
}

void LotteryLayer::CoinCallBack()
{
	isCoinBlink = false;
}