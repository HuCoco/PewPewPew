//
//  BaseMission.cpp
//  pewpewpew
//
//  Created by 胡可 on 15/4/27.
//
//

#include "BaseMission.h"

BaseMission::BaseMission()
{
    
}

BaseMission::~BaseMission()
{
    
}

void BaseMission::init()
{
    isComplete = false;
    NowNumber = 0;
    CompleteNumber = 0;
    MissionT = NONE;
}

bool BaseMission::UpdateMission(int _data)
{
    NowNumber+=_data;
    if(NowNumber>=CompleteNumber)
    {
        NowNumber = CompleteNumber;
        isComplete = true;
    }
    log("base");
    return isComplete;
}

void BaseMission::Read()
{
    NowNumber = UserDefault::getInstance()->getIntegerForKey("None", 0);
}

void BaseMission::Save()
{
    UserDefault::getInstance()->setIntegerForKey("None", NowNumber);
}

bool BaseMission::GetComplete()
{
    if(NowNumber>=CompleteNumber)
    {
        return true;
    }
    return false;
}