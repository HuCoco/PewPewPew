#include "ColorBiu.h"
#include "GameConfig.h"

ColorBiu::ColorBiu()
{
	xDirection = 0;
	yDirection = 0;
	BiuSpeed = 0;
	xSpeed = 0;
	ySpeed = 0;
	Color = 0;
}


ColorBiu::~ColorBiu()
{

}
void ColorBiu::CreateBiu(BiuColor _color,PlaneType _planetype)
{
	switch (_planetype)
	{
	case Battlecruiser_Plane:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(BATTLECRUISER_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(BATTLECRUISER_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(BATTLECRUISER_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		BiuSprite->setScale(2);
		break;
	case Viking_Plane:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(VIKING_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(VIKING_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(VIKING_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		BiuSprite->setScale(2);
		break;
	case Banshee_Plane:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(BANSHEE_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(BANSHEE_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(BANSHEE_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		BiuSprite->setScale(2);
		break;
	case Tempest_Plane:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(TEMPEST_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(TEMPEST_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(TEMPEST_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		break;
	case VoidRay_Plane:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(VOIDRAY_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(VOIDRAY_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(VOIDRAY_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		break;
	case Phoenix_Plane:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(PHOENIX_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(PHOENIX_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(PHOENIX_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		BiuSprite->setScale(2);
		break;
	case Battlecruiser_Plane_S:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(BATTLECRUISER_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(BATTLECRUISER_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(BATTLECRUISER_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		BiuSprite->setScale(2);
		break;
	case Viking_Plane_S:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(VIKING_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(VIKING_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(VIKING_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		BiuSprite->setScale(2);
		break;
	case Banshee_Plane_S:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(BANSHEE_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(BANSHEE_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(BANSHEE_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		BiuSprite->setScale(2);
		break;
	case VoidRay_Plane_S:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(VOIDRAY_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(VOIDRAY_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(VOIDRAY_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		break;
	case Phoenix_Plane_S:
		switch (_color)
		{
		case Blue:
			BiuSprite = Sprite::createWithSpriteFrameName(PHOENIX_BLUEBIU);
			Color = BLUE;
			break;
		case Red:
			BiuSprite = Sprite::createWithSpriteFrameName(PHOENIX_REDBIU);
			Color = RED;
			break;
		case Yellow:
			BiuSprite = Sprite::createWithSpriteFrameName(PHOENIX_YELLOWBIU);
			Color = YELLOW;
			break;
		}
		BiuSprite->setScale(2);
	default:
		break;
	}
	ColorData = _color;
}
Vec2 ColorBiu::getPosition()
{
	return BiuSprite->getPosition();
}
void ColorBiu::setPosition(Vec2 _position)
{
	BiuSprite->setPosition(_position);
}
Vec2 ColorBiu::getContentSize()
{
	return BiuSprite->getContentSize();
}
Sprite* ColorBiu::getSprite()
{
	return BiuSprite;
}
//获得单位向量计算方向
void ColorBiu::setDirection(Vec2 _position,Vec2 _PlanePosition)
{
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	float Len = sqrt((_position.x - _PlanePosition.x)*(_position.x - _PlanePosition.x) + (_position.y - _PlanePosition.y)*(_position.y - _PlanePosition.y));
	xDirection = (_position.x - _PlanePosition.x ) / Len;
	yDirection = (_position.y - _PlanePosition.y) / Len;
}

void ColorBiu::setSpeed(float _BiuSpeed)
{
	BiuSpeed = _BiuSpeed;
}
void ColorBiu::setSpeed()
{
	xSpeed = xDirection * BiuSpeed;
	ySpeed = yDirection * BiuSpeed;
}
void ColorBiu::BiuMoving()
{
	if (xSpeed != 0 && ySpeed != 0 && BiuSprite != NULL)
	{
		Vec2 NowPosition = BiuSprite->getPosition();
		BiuSprite->setPosition(NowPosition.x + xSpeed, NowPosition.y + ySpeed);
	}
}

void ColorBiu::setSpriteNULL()
{
	BiuSprite = NULL;
}
int ColorBiu::getColor()
{
	return Color;
}

BiuColor ColorBiu::getColorData()
{
	return ColorData;
}