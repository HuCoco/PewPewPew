#pragma once
#include "cocos2d.h"
#include "GameScene.h"
#include "GameOverLayer_G.h"
#include "MyPlane.h"
#include "ColorBiu.h"
#include "ColorMeteorites.h"
#include "MyAudio.h"
#include "PlaneChooseLayer.h"
#include "MobClickCpp.h"
#include "AdsMogoInterstitial.h"
#include "MissionControlSystem.h"
USING_NS_CC;
enum GameLevel
{
	Levelv1, Levelv2, Levelv3, Levelv4, Levelv5
}; 

struct RankingData
{
	int SocreData;
	std::string PlaneDataPNG;
};

struct CoinData
{
	Sprite* Coin;
	bool isGet;
};
class GameLayer_G
	:public Layer
{
public:
	GameLayer_G();
	~GameLayer_G();
	CREATE_FUNC(GameLayer_G);
	virtual bool init();
	void AddBiu();
	void Moving(float);
	void AddMeteorites(float);
	void Rotating(float);
	virtual void update(float);
	void Scoreupdate(float);
	void LevelUpdate(float);
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);
	void GamePause(Ref*);
	void PlaneBOOM(Vec2);
	void BiuBoom(Vec2,BiuColor);
	void AddFinger(Vec2);
	void RemoveFinger();
	void iSBlueBiu(Ref*);
	void iSRedBiu(Ref*);
	void iSYellowBiu(Ref*);
	void DeleteBiu(int);
	void DeleteMeteorites(int);
	bool CircleCollision(Sprite* _Sp1, Sprite* _Sp2);
	void AddTwoSmallMeteorites(MyColor _color, Vec2 _position,Vec2);
	void MeteoritesBOOM(ColorMeteorites,MyColor);
	void SaveRank();
	void ReadRank();
	void MeteoritesBreak(ColorMeteorites);
	void MeteoritesDeleteCallBack();
	void ScreenShake(Layer*);
	void GetCoinAction(Sprite*);
	void GetCoinCallBack();
    void GoOn();
    void BluePauseHelp(float dt);
    void RedPauseHelp(float dt);
    void requestInterstitialCallback();
    void showInterstitialCallback();
    void CloseInterstitialCallback();
    void addOverLayer(float);
private:
	Sprite* Finger;
	BiuColor BiuColorData;	
	MyPlane BiuPlane;
	Vec2 TouchPoint;
	int upColor;
	std::vector<ColorBiu>Biu;
	std::vector<ColorMeteorites>Meteorites;
	int MeteoritesSzie;
	bool isTouchMoving;
	LabelBMFont* ScoreTTF;
	int Score;
	char ScoreString[20];
	char BestScoreString[20];
	int level;
	float MoreScore;
	bool isPause;
	MenuItemSprite* BackBtn;
	EventListenerTouchOneByOne* touch_listener;
	char* DataString;
	GameLevel Level;
	double UpdataTime;
	bool BlueCome;
	bool RedCome;
	MenuItemSprite* BlueBiuBtn;
	MenuItemSprite* YellowBiuBtn;
	MenuItemSprite* RedBiuBtn;	
	LabelBMFont* BiuState;
	RankingData RankingList[6];
	MenuItemSprite* ContinueBtn;
	MenuItemSprite* PauseBtn;
	int BreakNumber;
	std::vector<CoinData> MyCoin;
	Sprite* CoinSprite;
	LabelBMFont* CoinBMFont;
	char CoinNumber[20];
    int AddTime;
    bool FirstGame;
    bool RedHelp;
    bool BlueHelp;
    MissionControlSystem MissionSystem;
};

