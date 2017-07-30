#pragma once
#include "cocos2d.h"
#include "math/CCMath.h"
#include "MyPlane.h"
USING_NS_CC;
enum MyColor
{
	VerySmallBlue, 
	VerySmallRed, 
	VerySmallYellow, 
	VeryBigBlue, 
	VeryBigRed, 
	VeryBigYellow, 
	BigYellow, 
	SmallYellow, 
	MiddleYellow
};

class ColorMeteorites
{
private:
	Sprite* Meteorites; //陨石
	Size MyMeteoritesSize; //陨石大小
	float xDirection;	//x方向
	float yDirection;	//y方向
	float MeteoritesSpeed;		//陨石速度
	float xSpeed;		//x速度
	float ySpeed;		//y速度
	int Life;		//生命
	int RotationNum;	//旋转角度
	int Score;	//分数
	int Color;	//颜色
	MyColor ColorType;  //陨石大小颜色种类
	bool BigBreak;
public:
	ColorMeteorites();
	~ColorMeteorites();
	void CreateMyMeteorites(MyColor);
	Vec2 getPosition();
	void setPosition(Vec2);
	Vec2 getContentSize();
	int getLife();
	Sprite* getSprite();
	void setDirection(Vec2);
	void setMeteoritesSpeed(float);
	void setSpeed();
	void setSpeed(float);
	void Moving();
	void MeteoritesRotation();
	void setSpriteNULL();
	void LoseLife(MyPlane);
	int getScore();
	int getColor();
	MyColor getColorType();
	bool getBreak();
	void setBreak(bool);
};