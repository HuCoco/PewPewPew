//
//  MissionControlSystem.h
//  pewpewpew
//
//  Created by 胡可 on 15/4/27.
//
//

#ifndef __pewpewpew__MissionControlSystem__
#define __pewpewpew__MissionControlSystem__

#include <stdio.h>
#include "NetTime.h"
#include "BaseMission.h"
#include "Mission.h"
#include "cocos2d.h"
USING_NS_CC;

class MissionControlSystem
{
public:
    MissionControlSystem();
    ~MissionControlSystem();
    void InitData();
    void Save();
    void Read();
    void UpdataAllMission(MissionType);
    void GetNewMission();
    void Reset();
    BaseMission* Factory(int);
    int GetMissionOne(){return MissionOne;}
    int GetMissionTwo(){return MissionTwo;}
    int GetMissionThree(){return MissionThree;}
    MissionType getType(int);
    void CompleteMission();
private:
    std::vector<BaseMission*> *MissionVector;
    int MissionOne;
    int MissionTwo;
    int MissionThree;
    int MissionNumber;
    NetTime MyTime;
};

#endif /* defined(__pewpewpew__MissionControlSystem__) */
