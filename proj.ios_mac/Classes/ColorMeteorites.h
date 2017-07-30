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
	Sprite* Meteorites; //��ʯ
	Size MyMeteoritesSize; //��ʯ��С
	float xDirection;	//x����
	float yDirection;	//y����
	float MeteoritesSpeed;		//��ʯ�ٶ�
	float xSpeed;		//x�ٶ�
	float ySpeed;		//y�ٶ�
	int Life;		//����
	int RotationNum;	//��ת�Ƕ�
	int Score;	//����
	int Color;	//��ɫ
	MyColor ColorType;  //��ʯ��С��ɫ����
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