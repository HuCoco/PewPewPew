#pragma once
#include "cocos2d.h"
#include "math/CCMath.h"
#include "MyPlane.h"
USING_NS_CC;

enum BiuColor
{
	Blue, Red, Yellow
};

class ColorBiu
{
public:
	ColorBiu();
	~ColorBiu();
	void CreateBiu(BiuColor,PlaneType);   //创建子弹
	Vec2 getPosition();		//获取位置坐标
	void setPosition(Vec2);		//设置坐标
	Vec2 getContentSize();		//获取大小
	Sprite* getSprite();	//获取精灵
	void setDirection(Vec2,Vec2);	//设置方向
	void setSpeed(float);	//设置子弹速度
	void setSpeed();	//设置子弹速度（默认2像素）
	void BiuMoving();	//子弹移动
	void setSpriteNULL();	//设置精灵为NULL
	int getColor();		//获取颜色
	BiuColor getColorData();
private:
	Sprite* BiuSprite;	//子弹
	float xDirection;	//x方向
	float yDirection;	//y方向
	float BiuSpeed;		//子弹速度
	float xSpeed;	//x速度
	float ySpeed;	//y速度
	int Color;	//颜色
	BiuColor ColorData;
};

