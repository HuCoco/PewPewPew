#include "ColorMeteorites.h"
#include "GameConfig.h"
ColorMeteorites::ColorMeteorites()
{
	Meteorites = NULL;
	MyMeteoritesSize = Size(0, 0);
	xDirection = 0;
	yDirection = 0;
	xSpeed = 0;
	ySpeed = 0;
	MeteoritesSpeed = 0;
	Life = 0;
	RotationNum = 0;
	Color = 0;   
	BigBreak = false;
}

ColorMeteorites::~ColorMeteorites()
{

}
void ColorMeteorites::CreateMyMeteorites(MyColor _Color)
{
	switch (_Color)
	{
	case VerySmallBlue:
		Meteorites = Sprite::createWithSpriteFrameName(VERY_SMALL_BLUE_MET_PNG);
		Life = TWO_LIFES;
		MeteoritesSpeed = VERY_FAST;
		Score = TWO;
		Color = BLUE;
		ColorType = VerySmallBlue;
		break;
	case VerySmallRed:
		Meteorites = Sprite::createWithSpriteFrameName(VERY_SMALL_RED_MET_PNG);
		Life = TWO_LIFES;
		MeteoritesSpeed = VERY_FAST;
		Score = TWO;
		Color = RED;
		ColorType = VerySmallRed;
		break;
	case VerySmallYellow:
		Meteorites = Sprite::createWithSpriteFrameName(VERY_SMALL_YELLOW_MET_PNG);
		Life = TWO_LIFES;
		MeteoritesSpeed = VERY_FAST;
		Score = TWO;
		Color = YELLOW;
		ColorType = VerySmallYellow;
		break;
	case VeryBigBlue:
		Meteorites = Sprite::createWithSpriteFrameName(VERY_BIG_BLUE_MET_PNG);
		Life = SIX_LIFES;
		MeteoritesSpeed = VERY_SLOW;
		Score = SIX;
		Color = BLUE;
		ColorType = VeryBigBlue;
		break;
	case VeryBigRed:
		Meteorites = Sprite::createWithSpriteFrameName(VERY_BIG_RED_MET_PNG);
		Life = SIX_LIFES;
		MeteoritesSpeed = VERY_SLOW;
		Score = SIX;
		Color = RED;
		ColorType = VeryBigRed;
		break;
	case BigYellow:
		Meteorites = Sprite::createWithSpriteFrameName(BIG_YELLOW_MET_PNG);
		Life = FIVE_LIFES;
		MeteoritesSpeed = SLOW;
		Score = FIVE;
		Color = YELLOW;
		ColorType = BigYellow;
		break;
	case MiddleYellow:
		Meteorites = Sprite::createWithSpriteFrameName(MIDDLE_YELLOW_MET_PNG);
		Life = FOUR_LIFES;
		MeteoritesSpeed = MIDDLE;
		Score = FOUR;
		Color = YELLOW;
		ColorType = MiddleYellow;
		break;
	case VeryBigYellow:
		Meteorites = Sprite::createWithSpriteFrameName(VERY_BIG_YELLOW_MET_PNG);
		Life = SIX_LIFES;
		MeteoritesSpeed = VERY_SLOW;
		Score = SIX;
		Color = YELLOW;
		ColorType = VeryBigYellow;
		break;
	case SmallYellow:
		Meteorites = Sprite::createWithSpriteFrameName(SMALL_YELLOW_MET_PNG);
		Life = THREE_LIFES;
		MeteoritesSpeed = FAST;
		Score = THREE;
		Color = YELLOW;
		ColorType = SmallYellow;
		break;
	}
	if (Meteorites != NULL)
	{
		MyMeteoritesSize = Meteorites->getContentSize();
		Size MyWinSize = Director::getInstance()->getVisibleSize();
		if (CCRANDOM_MINUS1_1() >= 0)		// [-1,0) 上方出现 ， [0,1] 屏幕左边出现
		{
			if (CCRANDOM_MINUS1_1() >= 0)	// [-1,0) 屏幕左边出现 ， [0,1] 屏幕左边出现
			{
				Meteorites->setPosition(
					-MyMeteoritesSize.width / 2,                  
					CCRANDOM_0_1() * (MyWinSize.height / 2) + MyWinSize.height / 2);  
			}
			else
			{
				Meteorites->setPosition(
					MyWinSize.width + MyMeteoritesSize.width / 2,
					CCRANDOM_0_1() * (MyWinSize.height / 2) + MyWinSize.height / 2);
			}
		}
		else
		{
			Meteorites->setPosition(
				(CCRANDOM_0_1() * (MyWinSize.width + MyMeteoritesSize.width) - (MyMeteoritesSize.width / 2)),
				MyWinSize.height + MyMeteoritesSize.height / 2);
		}

	}
}

Vec2 ColorMeteorites::getPosition()
{
	if (Meteorites != NULL)
		return Meteorites->getPosition();
	else
		return NULL;
}
void ColorMeteorites::setPosition(Vec2 _position)
{
	Meteorites->setPosition(_position);
}
Vec2 ColorMeteorites::getContentSize()
{
	if (Meteorites != NULL)
		return Meteorites->getContentSize();
	else
		return NULL;
}
Sprite* ColorMeteorites::getSprite()
{
	if (Meteorites != NULL)
		return Meteorites;
	else
		return NULL;
}
void ColorMeteorites::setDirection(Vec2 _PlanePosition)
{
	Vec2 NowPosition = Meteorites->getPosition();
	float Len = sqrt((NowPosition.x - _PlanePosition.x)*(NowPosition.x - _PlanePosition.x) + (NowPosition.y - _PlanePosition.y)*(NowPosition.y - _PlanePosition.y));
	xDirection = (_PlanePosition.x - NowPosition.x) / Len;
	yDirection = (_PlanePosition.y - NowPosition.y) / Len;
}
void ColorMeteorites::setMeteoritesSpeed(float _MeteoritesSpeed)
{
	MeteoritesSpeed = _MeteoritesSpeed;
}
void ColorMeteorites::setSpeed()
{
	xSpeed = xDirection * MeteoritesSpeed;
	ySpeed = yDirection * MeteoritesSpeed;
}

void ColorMeteorites::setSpeed(float)
{
	xSpeed = xSpeed * 1.5;
	ySpeed = ySpeed * 1.5;
}
void ColorMeteorites::Moving()
{
	if (Meteorites != NULL && xSpeed != 0 && ySpeed != 0)
	{
		Vec2 NowPosition = Meteorites->getPosition();
		Meteorites->setPosition(NowPosition.x + xSpeed, NowPosition.y + ySpeed);
	}
}

void ColorMeteorites::MeteoritesRotation()
{
	if (Meteorites != NULL)
	{
		Meteorites->setRotation(RotationNum++);
		if (RotationNum > 360)
			RotationNum = 0;
	}

}
void ColorMeteorites::setSpriteNULL()
{
	Meteorites = NULL;
}
int ColorMeteorites::getLife()
{
	return Life;
}
void ColorMeteorites::LoseLife(MyPlane _plane)
{
	Life = Life - _plane.getPower();
}
int ColorMeteorites::getScore()
{
	return Score;
}
int ColorMeteorites::getColor()
{
	return Color;
}

MyColor ColorMeteorites::getColorType()
{
	return ColorType;
}

bool ColorMeteorites::getBreak()
{
	return BigBreak;
}

void ColorMeteorites::setBreak(bool _isbreak)
{
	BigBreak = _isbreak;
}