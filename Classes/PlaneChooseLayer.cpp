#include "PlaneChooseLayer.h"
#include "GameConfig.h"
PlaneData PlaneChooseLayer::ThePlane = { NULL, Battlecruiser_Plane, Vec2(0, 0), 0 };
PlaneChooseLayer::PlaneChooseLayer()
{
	touch_listener = EventListenerTouchOneByOne::create();
	TouchPoint = Vec2(0, 0);
	LastTouchPoint = Vec2(0, 0);
}

PlaneChooseLayer::~PlaneChooseLayer()
{

}

bool PlaneChooseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	touch_listener->setSwallowTouches(false);
	touch_listener->onTouchBegan = CC_CALLBACK_2(PlaneChooseLayer::onTouchBegan, this);
	touch_listener->onTouchMoved = CC_CALLBACK_2(PlaneChooseLayer::onTouchMoved, this);
	touch_listener->onTouchEnded = CC_CALLBACK_2(PlaneChooseLayer::onTouchEnded, this);
	touch_listener->onTouchCancelled = CC_CALLBACK_2(PlaneChooseLayer::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch_listener, this);
	
	
	
	Size MyWinSize = Director::getInstance()->getVisibleSize();


	PlaneData BattlecruiserData;
	if (UserDefault::getInstance()->getBoolForKey(IS_GET_BATTLECRUISER_S, 0) == true)
	{
		BattlecruiserData.MyPlaneSprite = Sprite::createWithSpriteFrameName(BATTLECRUISER_S);
		BattlecruiserData.MyPlaneType = Battlecruiser_Plane_S;
		BattlecruiserData.PlaneName = BATTLECRUISER_S;
		BattlecruiserData.NameData = BATTLECRUISER_NAME_S;
		BattlecruiserData.GetIt = true;
	}
	else if ( UserDefault::getInstance()->getBoolForKey(IS_GET_BATTLECRUISER_S, 0) == false)
	{
		BattlecruiserData.MyPlaneSprite = Sprite::createWithSpriteFrameName(BATTLECRUISER);
		BattlecruiserData.MyPlaneType = Battlecruiser_Plane;
		BattlecruiserData.PlaneName = BATTLECRUISER;
		BattlecruiserData.NameData = BATTLECRUISER_NAME;
		BattlecruiserData.GetIt = true;
	}
	AllPlaneData.push_back(BattlecruiserData);

	PlaneData VikingData;
	if (UserDefault::getInstance()->getBoolForKey(IS_GET_VIKING, 0) == true && UserDefault::getInstance()->getBoolForKey(IS_GET_VIKING, 0) == true)
	{
		VikingData.MyPlaneSprite = Sprite::createWithSpriteFrameName(VIKING_S);
		VikingData.GetIt = true;
		VikingData.MyPlaneType = Viking_Plane_S;
		VikingData.PlaneName = VIKING_S;
		VikingData.NameData = VIKING_NAME_S;

	}
	else if (UserDefault::getInstance()->getBoolForKey(IS_GET_VIKING, 0) == true && UserDefault::getInstance()->getBoolForKey(IS_GET_VIKING, 0) == false)
	{
		VikingData.MyPlaneSprite = Sprite::createWithSpriteFrameName(VIKING);
		VikingData.GetIt = true;
		VikingData.MyPlaneType = Viking_Plane;
		VikingData.PlaneName = VIKING;
		VikingData.NameData = VIKING_NAME;
	}
	else if (UserDefault::getInstance()->getBoolForKey(IS_GET_VIKING, 0) == false && UserDefault::getInstance()->getBoolForKey(IS_GET_VIKING, 0) == false)

	{
		VikingData.MyPlaneSprite = Sprite::createWithSpriteFrameName(VIKING_SHADOW);
		VikingData.GetIt = false;
		VikingData.MyPlaneType = Viking_Plane;
		VikingData.PlaneName = VIKING;
		VikingData.NameData = VIKING_NAME;

	}
	AllPlaneData.push_back(VikingData);

	PlaneData BansheeData;
	if (UserDefault::getInstance()->getBoolForKey(IS_GET_BANSHEE, 0) == true && UserDefault::getInstance()->getBoolForKey(IS_GET_BANSHEE_S, 0) == true)
	{
		BansheeData.MyPlaneSprite = Sprite::createWithSpriteFrameName(BANSHEE_S);
		BansheeData.GetIt = true;
		BansheeData.MyPlaneType = Banshee_Plane_S;
		BansheeData.PlaneName = BANSHEE_S;
		BansheeData.NameData = BANSHEE_NAME_S;

	}
	else if (UserDefault::getInstance()->getBoolForKey(IS_GET_BANSHEE, 0) == true && UserDefault::getInstance()->getBoolForKey(IS_GET_BANSHEE_S, 0) == false)
	{
		BansheeData.MyPlaneSprite = Sprite::createWithSpriteFrameName(BANSHEE);
		BansheeData.GetIt = true;
		BansheeData.MyPlaneType = Banshee_Plane;
		BansheeData.PlaneName = BANSHEE;
		BansheeData.NameData = BANSHEE_NAME;

	}
	else if (UserDefault::getInstance()->getBoolForKey(IS_GET_BANSHEE, 0) == false && UserDefault::getInstance()->getBoolForKey(IS_GET_BANSHEE_S, 0) == false)

	{
		BansheeData.MyPlaneSprite = Sprite::createWithSpriteFrameName(BANSHEE_SHADOW);
		BansheeData.GetIt = false;
		BansheeData.MyPlaneType = Banshee_Plane;
		BansheeData.PlaneName = BANSHEE;
		BansheeData.NameData = BANSHEE_NAME;

	}
	AllPlaneData.push_back(BansheeData);

	PlaneData VoidRayData;
	if (UserDefault::getInstance()->getBoolForKey(IS_GET_VOIDRAY, 0) == true && UserDefault::getInstance()->getBoolForKey(IS_GET_VOIDRAY_S, 0) == true)
	{
		VoidRayData.MyPlaneSprite = Sprite::createWithSpriteFrameName(VOIDRAY_S);
		VoidRayData.GetIt = true;
		VoidRayData.MyPlaneType = VoidRay_Plane_S;
		VoidRayData.PlaneName = VOIDRAY_S;
		VoidRayData.NameData = VOIDRAY_NAME_S;

	}
	else if (UserDefault::getInstance()->getBoolForKey(IS_GET_VOIDRAY, 0) == true && UserDefault::getInstance()->getBoolForKey(IS_GET_VOIDRAY_S, 0) == false)
	{
		VoidRayData.MyPlaneSprite = Sprite::createWithSpriteFrameName(VOIDRAY);
		VoidRayData.GetIt = true;
		VoidRayData.MyPlaneType = VoidRay_Plane;
		VoidRayData.PlaneName = VOIDRAY;
		VoidRayData.NameData = VOIDRAY_NAME;

	}
	else if (UserDefault::getInstance()->getBoolForKey(IS_GET_VOIDRAY, 0) == false && UserDefault::getInstance()->getBoolForKey(IS_GET_VOIDRAY_S, 0) == false)

	{
		VoidRayData.MyPlaneSprite = Sprite::createWithSpriteFrameName(VOIDRAY_SHADOW);
		VoidRayData.GetIt = false;
		VoidRayData.MyPlaneType = VoidRay_Plane;
		VoidRayData.PlaneName = VOIDRAY;
		VoidRayData.NameData = VOIDRAY_NAME;

	}
	AllPlaneData.push_back(VoidRayData);
	
	PlaneData PhoenixData;
	if (UserDefault::getInstance()->getBoolForKey(IS_GET_PHOENIX, 0) == true && UserDefault::getInstance()->getBoolForKey(IS_GET_PHOENIX_S, 0) == true)
	{
		PhoenixData.MyPlaneSprite = Sprite::createWithSpriteFrameName(PHOENIX_S);
		PhoenixData.GetIt = true;
		PhoenixData.MyPlaneType = Phoenix_Plane_S;
		PhoenixData.PlaneName = PHOENIX_S;
		PhoenixData.NameData = PHOENIX_NAME_S;
	}
	else if (UserDefault::getInstance()->getBoolForKey(IS_GET_PHOENIX, 0) == true && UserDefault::getInstance()->getBoolForKey(IS_GET_PHOENIX_S, 0) == false)
	{
		PhoenixData.MyPlaneSprite = Sprite::createWithSpriteFrameName(PHOENIX);
		PhoenixData.GetIt = true;
		PhoenixData.MyPlaneType = Phoenix_Plane;
		PhoenixData.PlaneName = PHOENIX;
		PhoenixData.NameData = PHOENIX_NAME;
	}
	else if (UserDefault::getInstance()->getBoolForKey(IS_GET_PHOENIX, 0) == false && UserDefault::getInstance()->getBoolForKey(IS_GET_PHOENIX_S, 0) == false)
	{
		PhoenixData.MyPlaneSprite = Sprite::createWithSpriteFrameName(PHOENIX_SHADOW);
		PhoenixData.GetIt = false;
		PhoenixData.MyPlaneType = Phoenix_Plane;
		PhoenixData.PlaneName = PHOENIX;
		PhoenixData.NameData = PHOENIX_NAME;
	}

	AllPlaneData.push_back(PhoenixData);

	PlaneData TempestData;
	if (UserDefault::getInstance()->getBoolForKey(IS_GET_TEMPEST, 0) == true)
	{
		TempestData.MyPlaneSprite = Sprite::createWithSpriteFrameName(TEMPEST);
		TempestData.GetIt = true;
	}
	else
	{
		TempestData.MyPlaneSprite = Sprite::createWithSpriteFrameName(TEMPEST_SHADOW);
		TempestData.GetIt = false;
	}
	TempestData.MyPlaneType = Tempest_Plane;
	TempestData.PlaneName = TEMPEST;
	TempestData.NameData = TEMPEST_NAME;
	AllPlaneData.push_back(TempestData);


	for (int i = 0; i < 6; i++)
	{
		AllPlaneData.at(i).MyPlaneSprite->setPosition(MyWinSize.width / 2 + MyWinSize.width/2.5*i, MyWinSize.height / 2);
		AllPlaneData.at(i).MyPosition = AllPlaneData.at(i).MyPlaneSprite->getPosition();
		AllPlaneData.at(i).LengthToCenter = AllPlaneData.at(i).MyPosition.x - MyWinSize.width / 2;
		this->addChild(AllPlaneData.at(i).MyPlaneSprite,2);
	}
	this->schedule(schedule_selector(PlaneChooseLayer::PlaneScale));
	MoveToChoose();

	
	return true;
}

bool PlaneChooseLayer::onTouchBegan(Touch* pTouch, Event* pEvent)
{

	Size MyWinSize = Director::getInstance()->getVisibleSize();
	Point touchLocation = pTouch->getLocationInView();
	touchLocation = Director::getInstance()->convertToGL(touchLocation);
	LastTouchPoint = touchLocation;
	for (int i = 0; i < 6; i++)
	{
		AllPlaneData.at(i).MyPosition = AllPlaneData.at(i).MyPlaneSprite->getPosition();
	}
	if (touchLocation.y <MyWinSize.height/2 + 200 && touchLocation.y > MyWinSize.height/2 - 200)
	{
		return true;
	}
	return false;
}

void PlaneChooseLayer::onTouchMoved(Touch* pTouch, Event* pEvent)
{

	Size MyWinSize = Director::getInstance()->getVisibleSize();
	Point touchLocation = pTouch->getLocationInView();
	touchLocation = Director::getInstance()->convertToGL(touchLocation);
	TouchPoint = touchLocation;
	MoveLenth = TouchPoint.x - LastTouchPoint.x;
	for (int i = 0; i < 6; i++)
	{
		AllPlaneData.at(i).MyPlaneSprite->setPositionX(AllPlaneData.at(i).MyPosition.x + MoveLenth);
		AllPlaneData.at(i).LengthToCenter = AllPlaneData.at(i).MyPlaneSprite->getPositionX() - MyWinSize.width / 2;
	}
}
void PlaneChooseLayer::onTouchEnded(Touch* pTouch, Event* pEvent)
{
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	PlaneData MinLengthToCenter;
	MinLengthToCenter.LengthToCenter = 999;
	for (int i = 0; i < 6; i++)
	{
		if (abs(AllPlaneData.at(i).LengthToCenter) < abs(MinLengthToCenter.LengthToCenter))
		{
			MinLengthToCenter = AllPlaneData.at(i);
			UserDefault::getInstance()->setIntegerForKey("ChooseNumber", i);
		}
	}
	for (int i = 0; i < 6; i++)
	{
		MoveTo* MoveAction = MoveTo::create(0.5, Vec2(AllPlaneData.at(i).MyPlaneSprite->getPositionX() - MinLengthToCenter.LengthToCenter, AllPlaneData.at(i).MyPosition.y));
		EaseExponentialOut* MoveActionEase = EaseExponentialOut::create(MoveAction);
		AllPlaneData.at(i).MyPlaneSprite->runAction(MoveActionEase);
	}
	ThePlane = MinLengthToCenter;
	UserDefault::getInstance()->setStringForKey("Choose", ThePlane.PlaneName);
	UserDefault::getInstance()->setIntegerForKey("ChooseType", ThePlane.MyPlaneType);
	MenuLayer_H::SetGoBtnstate(ThePlane.GetIt);
	if (ThePlane.GetIt == true)
	{
		PlaneNameBMFont->setString(ThePlane.NameData);
		PlaneNameBMFont->setColor(YELLOW_RGB);		
	}
	else
	{
		PlaneNameBMFont->setString("????");
		PlaneNameBMFont->setColor(RED_RGB);
	}
}

void PlaneChooseLayer::PlaneScale(float dt)
{
	Size MyWinSize = Director::getInstance()->getVisibleSize();

	for (int i = 0; i < 6; i++)
	{
		if (AllPlaneData.at(i).MyPlaneSprite->getPositionX() - MyWinSize.width / 2 < 250 &&
			AllPlaneData.at(i).MyPlaneSprite->getPositionX() - MyWinSize.width / 2 > -250)
		{
			AllPlaneData.at(i).MyPlaneSprite->setScale(1 + 0.5*(250 - abs(AllPlaneData.at(i).MyPlaneSprite->getPositionX() - MyWinSize.width / 2)) / 250);
		}
	}
}

PlaneData PlaneChooseLayer::getPlaneData()
{
	return ThePlane;
}

void PlaneChooseLayer::MoveToChoose()
{
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	int m = UserDefault::getInstance()->getIntegerForKey("ChooseNumber", 0);
	float Length = AllPlaneData.at(m).MyPlaneSprite->getPosition().x - MyWinSize.width / 2;
	for (int i = 0; i < 6; i++)
	{
		MoveTo* MoveAction = MoveTo::create(0.5, Vec2(AllPlaneData.at(i).MyPlaneSprite->getPositionX() - Length, AllPlaneData.at(i).MyPosition.y));
		EaseExponentialOut* MoveActionEase = EaseExponentialOut::create(MoveAction);
		AllPlaneData.at(i).MyPlaneSprite->runAction(MoveActionEase);
	}
	MenuLayer_H::SetGoBtnstate(AllPlaneData.at(m).GetIt);
	if (AllPlaneData.at(m).GetIt == true)
	{
		PlaneNameBMFont = LabelBMFont::create(AllPlaneData.at(m).NameData, SG14_FNT);
		PlaneNameBMFont->setColor(YELLOW_RGB);
	}
	else
	{
		PlaneNameBMFont = LabelBMFont::create("????", SG14_FNT, 30);
		PlaneNameBMFont->setColor(RED_RGB);
	}
	PlaneNameBMFont->setScale(0.8f);
	PlaneNameBMFont->setPosition(MyWinSize.width / 2, MyWinSize.height / 2 - 125);
	this->addChild(PlaneNameBMFont);
}