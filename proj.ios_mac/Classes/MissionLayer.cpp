//
//  MissionLayer.cpp
//  pewpewpew
//
//  Created by 胡可 on 15/4/28.
//
//

#include "MissionLayer.h"

MissionLayer::MissionLayer()
{
    
}

MissionLayer::~MissionLayer()
{
    
}

bool MissionLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    touch_listen = EventListenerTouchOneByOne::create();
    touch_listen->setSwallowTouches(true);
    touch_listen->onTouchBegan = CC_CALLBACK_2(MissionLayer::onTouchBegan,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touch_listen, this);
    MissionSystem.InitData();
    
    Size MyWinSize = Director::getInstance()->getVisibleSize();
    Sprite* Background = Sprite::createWithSpriteFrameName("PopupBGI.png");
    Background->setPosition(MyWinSize.width/2,MyWinSize.height/2);
    this->addChild(Background,1);
    
    LabelBMFont* MissionBMF = LabelBMFont::create("Mission", SG14_FNT);
    MissionBMF->setPosition(MyWinSize.width/2,MyWinSize.height/20*19);
    this->addChild(MissionBMF,3);
    
    LabelBMFont* MissionOneBMF = LabelBMFont::create("Mission 1", SG14_FNT);
    MissionOneBMF->setPosition(MyWinSize.width/2,MyWinSize.height/20*17);
    this->addChild(MissionOneBMF,3);
    ShowMissionData(MissionSystem.GetMissionOne(), 1);
    
    LabelBMFont* MissionTwoBMF = LabelBMFont::create("Mission 2", SG14_FNT);
    MissionTwoBMF->setPosition(MyWinSize.width/2,MyWinSize.height/20*11+100);
    this->addChild(MissionTwoBMF,3);
    ShowMissionData(MissionSystem.GetMissionTwo(), 2);
    
    LabelBMFont* MissionThreeBMF = LabelBMFont::create("Mission 3", SG14_FNT);
    MissionThreeBMF->setPosition(MyWinSize.width/2,MyWinSize.height/20*5+200);
    this->addChild(MissionThreeBMF,3);
    ShowMissionData(MissionSystem.GetMissionThree(), 3);
    //Mis
    
    return true;
}

bool MissionLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    return true;
}

void MissionLayer::ShowMissionData(int _mission,int Num)
{
    Size MyWinSize = Director::getInstance()->getVisibleSize();
    if(_mission == -1)
    {
        LabelBMFont* NoMission = LabelBMFont::create("None", SG14_FNT);
        NoMission->setPosition(MyWinSize.width/2,MyWinSize.height/20*((4-Num)*6-2)+100*(Num-1));
        this->addChild(NoMission);
    }
    else
    {
       
        LabelBMFont* MissionData;
        char NowData[20];
        switch (_mission) {
            case 0:
                MissionData = LabelBMFont::create("Get 200+ Score", SG14_FNT);
                 sprintf(NowData, "%d/200",UserDefault::getInstance()->getIntegerForKey("threeHigh", 0));
                break;
            case 1:
                MissionData = LabelBMFont::create("Break 50 Red", SG14_FNT);
                sprintf(NowData, "%d/50",UserDefault::getInstance()->getIntegerForKey("breakred", 0));
                break;
            case 2:
                MissionData = LabelBMFont::create("Break 50 Yellow", SG14_FNT);
                sprintf(NowData, "%d/50",UserDefault::getInstance()->getIntegerForKey("breakYellow", 0));
                break;
            case 3:
                MissionData = LabelBMFont::create("Break 50 Blue", SG14_FNT);
                sprintf(NowData, "%d/50",UserDefault::getInstance()->getIntegerForKey("breakBlue", 0));
                break;
            case 4:
                MissionData = LabelBMFont::create("shoot 600 times", SG14_FNT);
                sprintf(NowData, "%d/600",UserDefault::getInstance()->getIntegerForKey("shoot", 0));
                break;
            default:
                break;
        }
        MissionData->setPosition(MyWinSize.width/2,MyWinSize.height/20*((4-Num)*6-2)+100*(Num-1));
        this->addChild(MissionData,3);
        
        
        LabelBMFont* MissionNumber = LabelBMFont::create(NowData, SG14_FNT);
        MissionNumber->setPosition(MyWinSize.width/2,MyWinSize.height/20*((4-Num)*6-3)+100*(Num-1));
        this->addChild(MissionNumber,3);
        
        


    }
    Sprite* MissionBar = Sprite::create("MissionBar.png");
    MissionBar->setPosition(MyWinSize.width/2,MyWinSize.height/20*((4-Num)*6-2)+100*(Num-1));
    MissionBar->setScale(1.25f, 1.45f);
    this->addChild(MissionBar,2);
}