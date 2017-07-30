//
//  ShootMission.cpp
//  pewpewpew
//
//  Created by 胡可 on 15/4/27.
//
//

#include "Mission.h"


ShootMission::ShootMission()
{
    
}

ShootMission::~ShootMission()
{
    
}

void ShootMission::init()
{
    CompleteNumber = 600;
    NowNumber = 0;
    isComplete = false;
    MissionT = SHOOT;
    log("5");
}
bool ShootMission::UpdateMission(int _data)
{
    NowNumber+=_data;
    if(NowNumber>CompleteNumber)
    {
        NowNumber = CompleteNumber;
        isComplete = true;
    }
        log("shoot++");
    return isComplete;
}

void ShootMission::Read()
{
    NowNumber = UserDefault::getInstance()->getIntegerForKey("shoot", 0);
}

void ShootMission::Save()
{
    UserDefault::getInstance()->setIntegerForKey("shoot", NowNumber);
}




BreakRedMission::BreakRedMission()
{
    
}

BreakRedMission::~BreakRedMission()
{
    
}

void BreakRedMission::init()
{
    CompleteNumber = 50;
    NowNumber = 0;
    isComplete = false;
    MissionT = BREAK_RED;
    log("2");
}
bool BreakRedMission::UpdateMission(int _data)
{
    NowNumber+=_data;
    if(NowNumber>CompleteNumber)
    {
        NowNumber = CompleteNumber;
        isComplete = true;
    }
        log("red++");
    return isComplete;
}

void BreakRedMission::Read()
{
    NowNumber = UserDefault::getInstance()->getIntegerForKey("breakred", 0);
}

void BreakRedMission::Save()
{
    UserDefault::getInstance()->setIntegerForKey("breakred", NowNumber);
}





BreakBlueMission::BreakBlueMission()
{
    
}

BreakBlueMission::~BreakBlueMission()
{
    
}

void BreakBlueMission::init()
{
    CompleteNumber = 50;
    NowNumber = 0;
    isComplete = false;
    MissionT = BREAK_BLUE;
    log("4");
}
bool BreakBlueMission::UpdateMission(int _data)
{
    NowNumber+=_data;
    if(NowNumber>CompleteNumber)
    {
        NowNumber = CompleteNumber;
        isComplete = true;
    }
    log("blue++");
    return isComplete;
}

void BreakBlueMission::Read()
{
    NowNumber = UserDefault::getInstance()->getIntegerForKey("breakBlue", 0);
}

void BreakBlueMission::Save()
{
    UserDefault::getInstance()->setIntegerForKey("breakBlue", NowNumber);
}





BreakYellowMission::BreakYellowMission()
{
    
}

BreakYellowMission::~BreakYellowMission()
{
    
}

void BreakYellowMission::init()
{
    CompleteNumber = 50;
    NowNumber = 0;
    isComplete = false;
    MissionT = BREAK_YELLOW;
    log("3");
}
bool BreakYellowMission::UpdateMission(int _data)
{
    NowNumber+=_data;
    if(NowNumber>CompleteNumber)
    {
        NowNumber = CompleteNumber;
        isComplete = true;
    }
        log("yellow++");
    return isComplete;
}

void BreakYellowMission::Read()
{
    NowNumber = UserDefault::getInstance()->getIntegerForKey("breakYellow", 0);
}

void BreakYellowMission::Save()
{
    UserDefault::getInstance()->setIntegerForKey("breakYellow", NowNumber);
}
ThreeHighScoreMission::ThreeHighScoreMission()
{
    
}

ThreeHighScoreMission::~ThreeHighScoreMission()
{
    
}

void ThreeHighScoreMission::init()
{
    CompleteNumber = 1;
    NowNumber = 0;
    isComplete = false;
    MissionT = THREE_HIGH_SCORE;
    log("1");
}
bool ThreeHighScoreMission::UpdateMission(int _data)
{
    NowNumber+=_data;
    if(NowNumber>CompleteNumber)
    {
        NowNumber = CompleteNumber;
        isComplete = true;
    }
        log("high++");
    return isComplete;
}

void ThreeHighScoreMission::Read()
{
    NowNumber = UserDefault::getInstance()->getIntegerForKey("threeHigh", 0);
}

void ThreeHighScoreMission::Save()
{
    UserDefault::getInstance()->setIntegerForKey("threeHigh", NowNumber);
}
