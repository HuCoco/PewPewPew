//
//  MissionControlSystem.cpp
//  pewpewpew
//
//  Created by 胡可 on 15/4/27.
//
//

#include "MissionControlSystem.h"


MissionControlSystem::MissionControlSystem()
{
    MissionOne = -1;
    MissionTwo = -1;
    MissionThree = -1;
    MissionVector = new std::vector<BaseMission*>;
}

MissionControlSystem::~MissionControlSystem()
{
    
}

void MissionControlSystem::Reset()
{
    UserDefault::getInstance()->setIntegerForKey("MissionNumber", 0);
    UserDefault::getInstance()->setIntegerForKey("MissionOne", 0);
    UserDefault::getInstance()->setIntegerForKey("MissionTwo", 0);
    UserDefault::getInstance()->setIntegerForKey("MissionThree", 0);
    UserDefault::getInstance()->setIntegerForKey("MissionDay",-1);
}

BaseMission* MissionControlSystem::Factory(int _No)
{
    switch (_No) {
        case 0:
            return new ThreeHighScoreMission;
            break;
        case 1:
            return new BreakRedMission;
            break;
        case 2:
            return new BreakYellowMission;
            break;
        case 3:
            return new BreakBlueMission;
            break;
        case 4:
            return new ShootMission;
            break;
        default:
            return new BaseMission;
            break;
    }
}

void MissionControlSystem::InitData()
{
    Read();
    for(int i = 0;i<MissionNumber;i++)
    {
        MissionVector->at(i)->Read();
    }
}

void MissionControlSystem::Read()
{
    MissionNumber = UserDefault::getInstance()->getIntegerForKey("MissionNumber", 0);
    //int No_Mission;
    BaseMission* BaseExample;
    for(int i = 0;i<MissionNumber;i++)
    {
        switch (i)
        {
            case 0:
                MissionOne = UserDefault::getInstance()->getIntegerForKey("MissionOne", 0);
                BaseExample = Factory(MissionOne);
                break;
            case 1:
                MissionTwo = UserDefault::getInstance()->getIntegerForKey("MissionTwo", 0);
                BaseExample = Factory(MissionTwo);
                break;
            case 2:
                MissionThree = UserDefault::getInstance()->getIntegerForKey("MissionThree", 0);
                BaseExample = Factory(MissionThree);
                break;
            default:
                break;
        }
        
        MissionVector->push_back(BaseExample);
        MissionVector->back()->init();
    }
}

void MissionControlSystem::Save()
{
    UserDefault::getInstance()->setIntegerForKey("MissionNumber", MissionNumber);
    UserDefault::getInstance()->setIntegerForKey("MissionOne", MissionOne);
    UserDefault::getInstance()->setIntegerForKey("MissionTwo", MissionTwo);
    UserDefault::getInstance()->setIntegerForKey("MissionThree", MissionThree);
    for(int i = 0;i<MissionNumber;i++)
    {
        MissionVector->at(i)->Save();
    }
}

MissionType MissionControlSystem::getType(int _mission)
{
    MissionType TYPE;
    switch (_mission) {
        case 0:
            TYPE = THREE_HIGH_SCORE;
            break;
        case 1:
            TYPE = BREAK_RED;
            break;
        case 2:
            TYPE = BREAK_BLUE;
            break;
        case 3:
            TYPE = BREAK_YELLOW;
            break;
        case 4:
            TYPE = SHOOT;
            break;
    }
    return TYPE;
}

void MissionControlSystem::UpdataAllMission(MissionType _type)
{
    MissionType NowType;
    NowType = getType(MissionOne);
    if(_type == NowType)
    {
        MissionVector->at(0)->UpdateMission(1);
        return;
    }
    
    NowType = MissionType(MissionTwo);
    if(_type == NowType)
    {
        MissionVector->at(1)->UpdateMission(1);
        return;
    }
    
    NowType = MissionType(MissionThree);
    if(_type == NowType)
    {
        MissionVector->at(2)->UpdateMission(1);
        return;
    }
}

void MissionControlSystem::GetNewMission()
{
    MyTime.SetLocalTime();
    int NowDay = MyTime.GetDay();
    int LastDay = UserDefault::getInstance()->getIntegerForKey("MissionDay",-1);
    if(NowDay == LastDay)
    {
        return;
    }
    if(MissionNumber == 3)
    {
        return;
    }
    int Rand = CCRANDOM_0_1()*1000;
    int Random = Rand%5;
    MissionVector->push_back(Factory(Random));
    MissionVector->back()->init();
    UserDefault::getInstance()->setIntegerForKey("MissionDay",NowDay);
    log("getnew");
    switch (MissionNumber) {
        case 0:
            MissionOne = Random;
            break;
        case 1:
            MissionTwo = Random;
            break;
        case 2:
            MissionThree = Random;
            break;
        default:
            break;
    }
    MissionNumber++;
}


void MissionControlSystem::CompleteMission()
{
    std::vector<BaseMission*> *MissionVectorTemp;
    MissionVectorTemp = new std::vector<BaseMission*>;
    for(int i = 0;i<MissionNumber;i++)
    {
        if(MissionVector->at(i)->GetComplete())
        {
            UserDefault::getInstance()->setIntegerForKey(COIN_NUM, UserDefault::getInstance()->getIntegerForKey(COIN_NUM)+50);
            MissionNumber--;
        }
        else
        {
            BaseMission* Temp = MissionVector->at(i);
            MissionVectorTemp->push_back(Temp);
        }
    }
    delete MissionVector;
    MissionVector = new std::vector<BaseMission*>;
    MissionVector = MissionVectorTemp;
    
    Save();
}





















