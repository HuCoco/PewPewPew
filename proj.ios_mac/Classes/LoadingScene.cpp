#include "LoadingScene.h"
#include "GameConfig.h"
#include "HeadScene.h"


int LoadingScene::LoadingNum = 0;
LoadingScene::LoadingScene()
{

}

LoadingScene::~LoadingScene()
{

}


bool LoadingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
    Size MyWinSize = Director::getInstance()->getVisibleSize();
    Ring = Sprite::create("Ring.png");
    Ring->setPosition(MyWinSize.width/2 , MyWinSize.height / 10 *2);
    this->addChild(Ring,10);
    this->schedule(schedule_selector(LoadingScene::RingGo));
	Director::getInstance()->getTextureCache()->addImageAsync("AllRes.png", CC_CALLBACK_1(LoadingScene::AllResCallback, this));
    LoadingAction();

	return true;
}

void LoadingScene::AllResCallback(Texture2D* texture)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("AllRes.plist", texture);
    LoadingComplete();
	LoadingNum++;
}

void LoadingScene::LoadingComplete()
{
		MyAudio::PlayHeadSceneBGM();
		HeadScene* scene = HeadScene::create();
		Director* pDirector = Director::getInstance();
		TransitionFade* jump = TransitionFade::create(0.3f, scene);
		pDirector->replaceScene(jump);
}
Sequence* LoadingScene::LoadingActioninit(Sprite* _sprite,Vec2 _position, float _delaytime,bool _callback)
{
    Size MyWinSize = Director::getInstance()->getVisibleSize();
    MoveTo* SpriteMoveIn = MoveTo::create(2.5f, _position);
    MoveTo* SpriteMoveOut = MoveTo::create(1.5f, Vec2(MyWinSize.width + _sprite->getContentSize().width,_position.y));
    EaseExponentialIn* MoveOne =EaseExponentialIn::create(SpriteMoveIn);
    EaseExponentialOut* MoveTwo = EaseExponentialOut::create(SpriteMoveOut);
    DelayTime* MoveDelay = DelayTime::create(_delaytime);
    DelayTime* MiddleDelay = DelayTime::create(1);
    Sequence* Move;
    if(_callback == 0)
    {
        Move = Sequence::create(MoveDelay,MoveOne,MiddleDelay,MoveTwo, NULL);
    }
    else if(_callback == 1)
    {
        CallFunc* MoveCallBack = CallFunc::create(this,callfunc_selector(LoadingScene::LoadingComplete));
        Move = Sequence::create(MoveDelay,MoveOne,MiddleDelay,MoveTwo,MoveCallBack, NULL);
    }
    
    return Move;
}
void LoadingScene::LoadingAction()
{
    Size MyWinSize = Director::getInstance()->getVisibleSize();
    Sprite* NameOne = Sprite::create("StartImage.png");
    NameOne->setPosition(MyWinSize.width/2, MyWinSize.height/2);
    this->addChild(NameOne);
}
void LoadingScene::RingGo(float dt)
{
    Ring->setRotation(Ring->getRotation()+20);
}