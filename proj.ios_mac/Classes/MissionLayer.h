//
//  MissionLayer.h
//  pewpewpew
//
//  Created by 胡可 on 15/4/28.
//
//

#ifndef __pewpewpew__MissionLayer__
#define __pewpewpew__MissionLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "MissionControlSystem.h"
USING_NS_CC;

class MissionLayer
:public Layer
{
public:
    MissionLayer();
    ~MissionLayer();
    CREATE_FUNC(MissionLayer);
    virtual bool init();
    //void Close(Ref*);
    virtual bool onTouchBegan(Touch* pTouch, Event* pEvent);
    //virtual void onTouchMoved(Touch* pTouch, Event* pEvent);
    //virtual void onTouchEnded(Touch* pTouch, Event* pEvent);
    EventListenerTouchOneByOne* touch_listen;
    void ShowMissionData(int,int);
private:
    MissionControlSystem MissionSystem;
};

#endif /* defined(__pewpewpew__MissionLayer__) */
