//
//  ShootMission.h
//  pewpewpew
//
//  Created by 胡可 on 15/4/27.
//
//

#ifndef __pewpewpew__ShootMission__
#define __pewpewpew__ShootMission__

#include <stdio.h>
#include "cocos2d.h"
#include "BaseMission.h"
USING_NS_CC;

class ShootMission
:public BaseMission
{
public:
    ShootMission();
    ~ShootMission();
    virtual bool UpdateMission(int);
    virtual void init();
    virtual void Save();
    virtual void Read();
};

class BreakRedMission
:public BaseMission
{
public:
    BreakRedMission();
    ~BreakRedMission();
    virtual bool UpdateMission(int);
    virtual void init();
    virtual void Save();
    virtual void Read();
};


class BreakBlueMission
:public BaseMission
{
public:
    BreakBlueMission();
    ~BreakBlueMission();
    virtual bool UpdateMission(int);
    virtual void init();
    virtual void Save();
    virtual void Read();
};


class BreakYellowMission
:public BaseMission
{
public:
    BreakYellowMission();
    ~BreakYellowMission();
    virtual bool UpdateMission(int);
    virtual void init();
    virtual void Save();
    virtual void Read();
};


class ThreeHighScoreMission
:public BaseMission
{
public:
    ThreeHighScoreMission();
    ~ThreeHighScoreMission();
    virtual bool UpdateMission(int);
    virtual void init();
    virtual void Save();
    virtual void Read();
};
#endif /* defined(__pewpewpew__ShootMission__) */
