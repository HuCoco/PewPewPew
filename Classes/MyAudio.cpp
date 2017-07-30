#include "MyAudio.h"
#include "GameConfig.h"
bool MyAudio::BGM_On = true;
MyAudio::MyAudio()
{
	
}


MyAudio::~MyAudio()
{
}

void MyAudio::BGM_State(bool Con)
{
	BGM_On = Con;
}

bool MyAudio::getBGMState()
{
	return BGM_On;
}

void MyAudio::PlayHeadSceneBGM()
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(HEADSCENE_BGM_MP3, true);
}
void MyAudio::PlayGameSceneBGM()
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(GAMESCENE_BGM_MP3, true);

}
void MyAudio::StopBGM()
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}
void MyAudio::PauseBGM()
{
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}
void MyAudio::rePlayBGM()
{
	SimpleAudioEngine::sharedEngine()->rewindBackgroundMusic();
}
void MyAudio::resumeBGM()
{
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
void MyAudio::PlayShootEffect()
{
	SimpleAudioEngine::sharedEngine()->playEffect(SHOOT_WAV, false);

}
void MyAudio::PlayBoomEffict()
{
	SimpleAudioEngine::sharedEngine()->playEffect(BREAK_MET, false);
}