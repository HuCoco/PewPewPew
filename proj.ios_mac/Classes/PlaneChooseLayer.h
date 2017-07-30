#pragma once
#include "cocos2d.h"
#include "MyPlane.h"
#include "math/CCMath.h"
#include "MenuLayer_H.h"
USING_NS_CC;
struct PlaneData
{
	Sprite* MyPlaneSprite;
	PlaneType MyPlaneType;
	Point MyPosition;
	float LengthToCenter;
	char* PlaneName;
	bool GetIt;
	char* NameData;
};
class PlaneChooseLayer
	:public cocos2d::Layer
{
public:
	PlaneChooseLayer();
	~PlaneChooseLayer();
	CREATE_FUNC(PlaneChooseLayer);
	virtual bool init();
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);
	void PlaneScale(float);
	static PlaneData getPlaneData();
	void MoveToChoose();
private:
	EventListenerTouchOneByOne* touch_listener;
	std::vector<PlaneData> AllPlaneData;
	Point TouchPoint;
	Point LastTouchPoint;
	float MoveLenth;
	static PlaneData ThePlane;
	LabelBMFont* PlaneNameBMFont;

};