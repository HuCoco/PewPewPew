#pragma once
#include"cocos2d.h"
#include "GameConfig.h"
#include "NetTime.h"
#include "HeadScene.h"
#include "AdsMogoInterstitial.h"
USING_NS_CC;
struct PrizeData
{
	Sprite* Prize;
	char* PrizePNG;
	char* PrizeName;
	char* PrizeGet;
};

struct PrizeTimeINT
{
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;;
	int Second;
};

struct PrizeTimeCHAR
{
	char Year[10];
	char Month[10];
	char Day[10];
	char Hour[10];
	char Minute[10];
	char Second[10];
};

class LotteryLayer
	:public Layer
{
public:
	LotteryLayer();
	~LotteryLayer();
	virtual bool init();
	CREATE_FUNC(LotteryLayer);
	void setPullBar();
	void PlayPullBarAction();
	void GoGift(float);
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);
	void Prizeinit(int _num_prize);
	void GetPrize();
	static void NowTimeinit();
	static void SetTime();
	static void SaveTime();
	static void ReadTime();
	static void SaveNextTime(int _hour, int _minute);
	static bool isFullTime(int _time);
	static bool IsCan();
	static PrizeTimeINT getNowTime();
	static PrizeTimeINT getLastTime();
	void CoinNotEnough();
	void CostCoin();
	void TimeUpdate(float);
	void CoinCallBack();
    void AddNotEnoughtWindow();
    void CloseCallBack(Ref*);
    void requestInterstitialCallback(cocos2d::Ref* pSender);
    void showInterstitialCallback(cocos2d::Ref* pSender);
    void CloseInterstitialCallback(cocos2d::Ref* pSender);
    void RingGo(float);
    void ListenAd(float);
private:
	bool isCoinBlink;
	bool isCoinAction;
	LabelBMFont* TimeBMFont;
	Sprite* BGImage_One;
	Sprite* GiftOne;
	Sprite* GiftTwo;
	Sprite* PullBarPart1;
	Sprite* PullBarPart2;
	double PrizeSpeed;
	double SpeedUp;
	bool PullBarisWork;
	bool GetPrizeBool;
	int GoTiME;
	MenuItemSprite* BackBtn;
	std::vector<PrizeData> PrizeVector;
	int NumPrize;
	static NetTime *MyTime;
	static PrizeTimeINT NowTime;
	static PrizeTimeINT LastTime;
	LabelBMFont* CoinBMFont;
	char CoinNumber[20];
    bool isAddNotEnoughtWindow;
    bool wait;
    Sprite* Ring;
    MenuItemSprite* KnowBtn;
    MenuItemSprite* NotEnoughtBtn;
    MenuItemSprite* CloseBtn;
    bool AdOut;
    Layer* CantLotteryLayer ;
};