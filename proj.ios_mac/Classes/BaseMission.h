//
//  BaseMission.h
//  pewpewpew
//
//  Created by 胡可 on 15/4/27.
//
//

#ifndef __pewpewpew__BaseMission__
#define __pewpewpew__BaseMission__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
enum MissionType
{
    THREE_HIGH_SCORE,
    BREAK_RED,
    BREAK_YELLOW,
    BREAK_BLUE,
    SHOOT,
    NONE
};


class BaseMission
{
public:
    BaseMission();
    ~BaseMission();
    virtual bool UpdateMission(int);
    virtual void init();
    virtual void Save();
    virtual void Read();
    bool GetComplete();
protected:
    bool isComplete;
    int CompleteNumber;
    int NowNumber;
    MissionType MissionT;
};

#endif /* defined(__pewpewpew__BaseMission__) */
