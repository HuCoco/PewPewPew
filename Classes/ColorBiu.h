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
	void CreateBiu(BiuColor,PlaneType);   //�����ӵ�
	Vec2 getPosition();		//��ȡλ������
	void setPosition(Vec2);		//��������
	Vec2 getContentSize();		//��ȡ��С
	Sprite* getSprite();	//��ȡ����
	void setDirection(Vec2,Vec2);	//���÷���
	void setSpeed(float);	//�����ӵ��ٶ�
	void setSpeed();	//�����ӵ��ٶȣ�Ĭ��2���أ�
	void BiuMoving();	//�ӵ��ƶ�
	void setSpriteNULL();	//���þ���ΪNULL
	int getColor();		//��ȡ��ɫ
	BiuColor getColorData();
private:
	Sprite* BiuSprite;	//�ӵ�
	float xDirection;	//x����
	float yDirection;	//y����
	float BiuSpeed;		//�ӵ��ٶ�
	float xSpeed;	//x�ٶ�
	float ySpeed;	//y�ٶ�
	int Color;	//��ɫ
	BiuColor ColorData;
};

