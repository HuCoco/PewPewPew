#include "BGImageLayer_A.h"
#include "GameConfig.h"
BGImageLayer_A::BGImageLayer_A()
{

}
BGImageLayer_A::~BGImageLayer_A()
{

}

bool BGImageLayer_A::init()
{
	if (!Layer::init())
	{
		return false;
	}
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();


    
    Sprite* BGImage = Sprite::createWithSpriteFrameName(BACKGROUND_IMAGE_PNG);
    BGImage->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    this->addChild(BGImage);
    

    //this->schedule(schedule_selector(BGImageLayer_A::BGIGo));
    
    
    Sprite* AboutData = Sprite::createWithSpriteFrameName("AboutData.png");
    AboutData->setPosition(visibleSize.width/2,visibleSize.height/2);
    this->addChild(AboutData,3);
    
    Sprite* Red = Sprite::createWithSpriteFrameName(RED_BIU_BTN_PNG);
    Red->setPosition(Red->getContentSize().width,Red->getContentSize().height);
    this->addChild(Red,3);
    Sprite* Blue = Sprite::createWithSpriteFrameName(BLUE_BIU_BTN_PNG);
    Blue->setPosition(Red->getContentSize().width*3/2,Red->getContentSize().height);
    this->addChild(Blue,3);
    Sprite* Yellow = Sprite::createWithSpriteFrameName(YELLOW_BIU_BTN_PNG);
    Yellow->setPosition(Red->getContentSize().width*2,Red->getContentSize().height);
    this->addChild(Yellow,3);
    
    LabelBMFont* words = LabelBMFont::create(" Click it to \nchange color", SG14_FNT);
    words->setAnchorPoint(Vec2(0,0.5));
    words->setScale(0.8);
    words->setPosition(Red->getContentSize().width*5/2+10 + 10,Red->getContentSize().height);
    this->addChild(words,3);
    
    
    
	return true;
}

