#include "MyPlane.h"
#include "GameConfig.h"
float MyPlane::Rotation = 0;
PlaneType MyPlane::PlaneTypeData = Battlecruiser_Plane;
MyPlane::MyPlane()
{
	Plane = NULL;
	PlaneSize = Vec2(0, 0);
	PI = 3.14;
	PlaneLife = 1;
	PlanePower = 1;
	PlaneSpeed = 1;
	PlaneCoin = 1;
}
MyPlane::~MyPlane()
{

}
void MyPlane::CreatePlane(PlaneType _planetype)
{
	switch (_planetype)
	{
	case Battlecruiser_Plane:
		Plane = Sprite::createWithSpriteFrameName(BATTLECRUISER);
		PlaneSize = Plane->getContentSize();
		PlanePNG = BATTLECRUISER;
		PlaneTypeData = Battlecruiser_Plane;
		PlanePower = BATTLECRUISER_POWER;
		PlaneLife = BATTLECRUISER_LIFE;
		PlaneSpeed = BATTLECRUISER_BIU_SPEED;
		PlaneCoin = BATTLECRUISER_COIN;
		break;
	case Viking_Plane:
		Plane = Sprite::createWithSpriteFrameName(VIKING);
		PlaneSize = Plane->getContentSize();
		PlanePNG = VIKING;
		PlaneTypeData = Viking_Plane;
		PlanePower = VIKING_POWER;
		PlaneLife = VIKING_LIFE;
		PlaneSpeed = VIKING_BIU_SPEED;
		PlaneCoin = VIKING_COIN;
		break;
	case Banshee_Plane:
		Plane = Sprite::createWithSpriteFrameName(BANSHEE);
		PlaneSize = Plane->getContentSize();
		PlanePNG = BANSHEE;
		PlaneTypeData = Banshee_Plane;
		PlanePower = BANSHEE_POWER;
		PlaneLife = BANSHEE_LIFE;
		PlaneSpeed = BANSHEE_BIU_SPEED;
		PlaneCoin = BANSHEE_COIN;
		break;
	case Tempest_Plane:
		Plane = Sprite::createWithSpriteFrameName(TEMPEST);
		PlaneSize = Plane->getContentSize();
		PlanePNG = TEMPEST;
		PlaneTypeData = Tempest_Plane;
		PlanePower = TEMPEST_POWER;
		PlaneLife = TEMPEST_LIFE;
		PlaneSpeed = TEMPEST_BIU_SPEED;
		PlaneCoin = TEMPEST_COIN;

		break;
	case VoidRay_Plane:
		Plane = Sprite::createWithSpriteFrameName(VOIDRAY);
		PlaneSize = Plane->getContentSize();
		PlanePNG = VOIDRAY;
		PlaneTypeData = VoidRay_Plane;
		PlanePower = VOIDRAY_POWER;
		PlaneLife = VOIDRAY_LIFE;
		PlaneSpeed = VOIDRAY_BIU_SPEED;
		PlaneCoin = VOIDRAY_COIN;

		break;
	case Phoenix_Plane:
		Plane = Sprite::createWithSpriteFrameName(PHOENIX);
		PlaneSize = Plane->getContentSize();
		PlanePNG = PHOENIX;
		PlaneTypeData = Phoenix_Plane;
		PlanePower = PHOENIX_POWER;
		PlaneLife = PHOENIX_LIFE;
		PlaneSpeed = PHOENIX_BIU_SPEED;
		PlaneCoin = PHOENIX_COIN;
		break;
	case Battlecruiser_Plane_S:
		Plane = Sprite::createWithSpriteFrameName(BATTLECRUISER);
		PlaneSize = Plane->getContentSize();
		PlanePNG = BATTLECRUISER;
		PlaneTypeData = Battlecruiser_Plane;
		PlanePower = BATTLECRUISER_POWER;
		PlaneLife = BATTLECRUISER_LIFE;
		PlaneSpeed = BATTLECRUISER_BIU_SPEED;
		PlaneCoin = BATTLECRUISER_COIN;
		break;
	case Viking_Plane_S:
		Plane = Sprite::createWithSpriteFrameName(VIKING_S);
		PlaneSize = Plane->getContentSize();
		PlanePNG = VIKING_S;
		PlaneTypeData = Viking_Plane_S;
		PlanePower = VIKING_POWER_S;
		PlaneLife = VIKING_LIFE_S;
		PlaneSpeed = VIKING_BIU_SPEED_S;
		PlaneCoin = VIKING_COIN_S;
		break;
	case Banshee_Plane_S:
		Plane = Sprite::createWithSpriteFrameName(BANSHEE_S);
		PlaneSize = Plane->getContentSize();
		PlanePNG = BANSHEE_S;
		PlaneTypeData = Banshee_Plane_S;
		PlanePower = BANSHEE_POWER_S;
		PlaneLife = BANSHEE_LIFE_S;
		PlaneSpeed = BANSHEE_BIU_SPEED_S;
		PlaneCoin = BANSHEE_COIN_S;
		break;
	case VoidRay_Plane_S:
		Plane = Sprite::createWithSpriteFrameName(VOIDRAY_S);
		PlaneSize = Plane->getContentSize();
		PlanePNG = VOIDRAY_S;
		PlaneTypeData = VoidRay_Plane_S;
		PlanePower = VOIDRAY_POWER_S;
		PlaneLife = VOIDRAY_LIFE_S;
		PlaneSpeed = VOIDRAY_BIU_SPEED_S;
		PlaneCoin = VOIDRAY_COIN_S;

		break;
	case Phoenix_Plane_S:
		Plane = Sprite::createWithSpriteFrameName(PHOENIX_S);
		PlaneSize = Plane->getContentSize();
		PlanePNG = PHOENIX;
		PlaneTypeData = Phoenix_Plane_S;
		PlanePower = PHOENIX_POWER_S;
		PlaneLife = PHOENIX_LIFE_S;
		PlaneSpeed = PHOENIX_BIU_SPEED_S;
		PlaneCoin = PHOENIX_COIN_S;
		break;
	default:
		break;
	}
}
Vec2 MyPlane::getPosition()
{
	return Plane->getPosition();
}
void MyPlane::setPosition(Vec2 _position)
{
	Plane->setPosition(_position);
}
void MyPlane::setPosition(int _x, int _y)
{
	Plane->setPosition(_x, _y);

}
Size MyPlane::getContentSize()
{
	if (Plane != NULL)
		return Plane->getContentSize();
	else
		return Size(0, 0);
}
void MyPlane::setLife(int _life)
{
	PlaneLife = _life;
}
int MyPlane::getLife()
{
	if (Plane != NULL)
		return PlaneLife;
	else
		return -1;
}
int MyPlane::getPower()
{
	return PlanePower;
}
int MyPlane::getPlaneCoin()
{
	return PlaneCoin;
}
int MyPlane::getSpeed()
{
	return PlaneSpeed;
}

Sprite* MyPlane::getSprite()
{
	if (Plane != NULL)
		return Plane;
	else
		return NULL;
}
//·É´¬Ðý×ª
void MyPlane::setRotation(Vec2 _touchpoint)
{

	if (Plane != NULL)
	{
		
		if (_touchpoint.x - Plane->getPosition().x > 0 && _touchpoint.y - Plane->getPosition().y > 0)            // 0 - 89
		{
			Rotation = atanf((_touchpoint.x - Plane->getPosition().x) / (_touchpoint.y - Plane->getPosition().y)) / PI * 180;
		}
		else if (_touchpoint.x - Plane->getPosition().x > 0 && _touchpoint.y - Plane->getPosition().y == 0)		//90
		{
			Rotation = 90;
		}
		else if (_touchpoint.x - Plane->getPosition().x > 0 && _touchpoint.y - Plane->getPosition().y < 0)		//91-179
		{
			Rotation = atanf((Plane->getPosition().y - _touchpoint.y) / (_touchpoint.x - Plane->getPosition().x)) / PI * 180 + 90;
		}
		else if (_touchpoint.x - Plane->getPosition().x == 0 && _touchpoint.y - Plane->getPosition().y < 0)		//180
		{
			Rotation = 180;
		}
		else if (_touchpoint.x - Plane->getPosition().x < 0 && _touchpoint.y - Plane->getPosition().y < 0)		// 181-269
		{
			Rotation = atanf((Plane->getPosition().x - _touchpoint.x) / (Plane->getPosition().y - _touchpoint.y)) / PI * 180 + 180;
		}
		else if (_touchpoint.x - Plane->getPosition().x < 0 && _touchpoint.y - Plane->getPosition().y == 0)		//270
		{
			Rotation = 270;
		}
		else if (_touchpoint.x - Plane->getPosition().x < 0 && _touchpoint.y - Plane->getPosition().y > 0)		//271-359
		{
			Rotation = atanf((_touchpoint.y - Plane->getPosition().y) / (Plane->getPosition().x - _touchpoint.x)) / PI * 180 + 270;
		}
		else if (_touchpoint.x - Plane->getPosition().x == 0 && _touchpoint.y - Plane->getPosition().y > 0)		//360
		{
			Rotation = 360;
		}
		Plane->setRotation(Rotation);
	}
}
void MyPlane::SetSpriteNULL()
{
	Plane = NULL;
}

PlaneType MyPlane::getPlaneType()
{
	return PlaneTypeData;
}
float MyPlane::getRotation()
{
	return Rotation;
}
std::string MyPlane::getPlanePNG()
{
	return PlanePNG;
}
