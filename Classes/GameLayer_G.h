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
	void AddBiu();	//����ӵ�
	void Moving(float);		//�ƶ�
	void AddMeteorites(float);	//�����ʯ
	void Rotating(float);	//�ɴ���ת
	virtual void update(float);
	void Scoreupdate(float);	//����ˢ��
	void LevelUpdate(float); //��Ϸ�Ѷ�����
	//�����¼�
	virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
	virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
	virtual void onTouchEnded(Touch* pTouch, Event* pEvent);
	void GamePause(Ref*);
	void PlaneBOOM(Vec2);
	void BiuBoom(Vec2,BiuColor);
//	void GameGo(Ref*);
	void AddFinger(Vec2);
	void RemoveFinger();
	void iSBlueBiu(Ref*); //�����ӵ�Ϊ��ɫ
	void iSRedBiu(Ref*);	//�����ӵ�Ϊ��ɫ
	void iSYellowBiu(Ref*);	//�����ӵ�Ϊ��ɫ
	void DeleteBiu(int);	//ɾ���ӵ�
	void DeleteMeteorites(int);	//ɾ����ʯ
	bool CircleCollision(Sprite* _Sp1, Sprite* _Sp2);	//Բ����ײ���
	void AddTwoSmallMeteorites(MyColor _color, Vec2 _position,Vec2);	//�����С��ʯ
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
	MyPlane BiuPlane;	//�ɴ�
	Vec2 TouchPoint;	//����������
	int upColor;	//��һ�λ�����ɫ
	std::vector<ColorBiu>Biu; //�洢�ӵ�
	std::vector<ColorMeteorites>Meteorites;	//�洢��ʯ
	int MeteoritesSzie;	//��ʯ��С
	bool isTouchMoving;	//�Ƿ��ƶ�
	LabelBMFont* ScoreTTF;	//������ʾ
	int Score;//����
	char ScoreString[20];//��ǰ������char��
	char BestScoreString[20];//��÷���
	int level;//��Ϸ�ȼ�
	float MoreScore;//�ӷ�
	bool isPause;//��ͣ
	MenuItemSprite* BackBtn;	//���ذ���
	EventListenerTouchOneByOne* touch_listener;
	char* DataString;//��洢��������
	GameLevel Level;//��Ϸ�Ѷ�
	double UpdataTime;//��ʯ����Ƶ��
	bool BlueCome;//��ɫ��ʯ����
	bool RedCome;//��ɫ��ʯ����
	MenuItemSprite* BlueBiuBtn; //��ɫ�ӵ���ť
	MenuItemSprite* YellowBiuBtn; //��ɫ�ӵ���ť
	MenuItemSprite* RedBiuBtn;	//��ɫ�ӵ���ť
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

