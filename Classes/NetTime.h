#pragma once
#include "cocos2d.h"
#include "GameConfig.h"
USING_NS_CC;
class NetTime
{
private:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
public:
	void Timeinit();
	NetTime();
	~NetTime();
	void SetLocalTime();
	int GetYear() { return Year; }
	int GetMouth(){ return Month; }
	int GetDay(){ return Day; }
	int GetHour(){ return Hour; }
	int GetMinute(){ return Minute; }
	int GetSecond(){ return Second; }
};

