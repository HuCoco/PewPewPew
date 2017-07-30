#pragma once
#include "cocos2d.h"
#include "math/CCMath.h"
USING_NS_CC;
enum PlaneType
{
	Battlecruiser_Plane,
	Viking_Plane,
	Banshee_Plane,
	Tempest_Plane,
	VoidRay_Plane,
	Phoenix_Plane,
	Battlecruiser_Plane_S,
	Viking_Plane_S,
	Banshee_Plane_S,
	VoidRay_Plane_S,
	Phoenix_Plane_S
};
class MyPlane
{
private:
	Sprite* Plane;	//·É´¬
	Size PlaneSize;	
	int PlaneLife;
	int PlanePower;
	int PlaneSpeed;
	int PlaneCoin;
	double PI;
	static PlaneType PlaneTypeData;
	std::string PlanePNG;
	static float Rotation;
public:
	MyPlane();
	~MyPlane();
	void CreatePlane(PlaneType _planetype);
	Vec2 getPosition();
	void setPosition(Vec2);
	void setPosition(int,int);
	Size getContentSize();
	void setLife(int);
	int getLife();
	int getPower();
	int getPlaneCoin();
	int getSpeed();
	Sprite* getSprite();
	void setRotation(Vec2);
	void SetSpriteNULL();
	static PlaneType getPlaneType();
	static float getRotation();
	std::string getPlanePNG();
};
