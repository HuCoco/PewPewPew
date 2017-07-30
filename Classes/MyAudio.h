#pragma once
#include <SimpleAudioEngine.h>
using namespace CocosDenshion;
class MyAudio
{
public:
	MyAudio();
	~MyAudio();
	static void preloadAll();
	static void PlayHeadSceneBGM();
	static void PlayGameSceneBGM();
	static void StopBGM();
	static void PauseBGM();
	static void rePlayBGM();
	static void resumeBGM();
	static void PlayShootEffect();
	static void PlayBoomEffict();
	static void BGM_State(bool);
	static bool getBGMState();
private:
	static bool BGM_On;
	
};

