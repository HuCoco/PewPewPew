#pragma once
#include "cocos2d.h"
#include "GameScene.h"
#include "GameOverLayer_G.h"
#include "MyPlane.h"
#include "ColorBiu.h"
#include "ColorMeteorites.h"
#include "MyAudio.h"
#include "PlaneChooseLayer.h"
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
	void AddBiu();	//添加子弹
	void Moving(float);		//移动
	void AddMeteorites(float);	//添加陨石
	void Rotating(float);	//飞船旋转
	virtual void update(float);
	void Scoreupdate(float);	//分数刷新
	void LevelUpdate(float); //游戏难度提升
	//触屏事件
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);
	void GamePause(Ref*);
	void PlaneBOOM(Vec2);
	void BiuBoom(Vec2,BiuColor);
//	void GameGo(Ref*);
	void AddFinger(Vec2);
	void RemoveFinger();
	void iSBlueBiu(Ref*); //设置子弹为蓝色
	void iSRedBiu(Ref*);	//设置子弹为红色
	void iSYellowBiu(Ref*);	//设置子弹为黄色
	void DeleteBiu(int);	//删除子弹
	void DeleteMeteorites(int);	//删除陨石
	bool CircleCollision(Sprite* _Sp1, Sprite* _Sp2);	//圆形碰撞检测
	void AddTwoSmallMeteorites(MyColor _color, Vec2 _position,Vec2);	//添加两小陨石
	void MeteoritesBOOM(ColorMeteorites,MyColor);
	void SaveRank();
	void ReadRank();
	void MeteoritesBreak(ColorMeteorites);
	void MeteoritesDeleteCallBack();
	void ScreenShake(Layer*);
	void GetCoinAction(Sprite*);
	void GetCoinCallBack();
	//void SaveCoinData();
	//void DeleteCoin(float);
private:
	Sprite* Finger;
	BiuColor BiuColorData;	
	MyPlane BiuPlane;	//飞船
	Vec2 TouchPoint;	//触摸点坐标
	int upColor;	//上一次击打颜色
	std::vector<ColorBiu>Biu; //存储子弹
	std::vector<ColorMeteorites>Meteorites;	//存储陨石
	int MeteoritesSzie;	//陨石大小
	bool isTouchMoving;	//是否移动
	LabelBMFont* ScoreTTF;	//分数显示
	int Score;//分数
	char ScoreString[20];//当前分数（char）
	char BestScoreString[20];//最好分数
	int level;//游戏等级
	float MoreScore;//加分
	bool isPause;//暂停
	MenuItemSprite* BackBtn;	//返回按键
	EventListenerTouchOneByOne* touch_listener;
	char* DataString;//需存储分数数据
	GameLevel Level;//游戏难度
	double UpdataTime;//陨石出现频率
	bool BlueCome;//蓝色陨石到来
	bool RedCome;//红色陨石到来
	MenuItemSprite* BlueBiuBtn; //蓝色子弹按钮
	MenuItemSprite* YellowBiuBtn; //黄色子弹按钮
	MenuItemSprite* RedBiuBtn;	//红色子弹按钮
	LabelBMFont* BiuState;
	RankingData RankingList[6];
	MenuItemSprite* ContinueBtn;
	MenuItemSprite* PauseBtn;
	int BreakNumber;
	std::vector<CoinData> MyCoin;
	Sprite* CoinSprite;
	LabelBMFont* CoinBMFont;
	char CoinNumber[20];
};

