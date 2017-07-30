#pragma 
#include "cocos2d.h"
#include "MenuLayer_R.h"
#include "BGImageLayer_R.h"

USING_NS_CC;
class RankScene
	:public Scene
{
public:
	RankScene();
	~RankScene();
	virtual bool init();
	CREATE_FUNC(RankScene);
	void GotoRankScene(Ref*);
};