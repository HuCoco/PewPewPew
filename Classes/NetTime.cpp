#include "NetTime.h"

NetTime::NetTime()
{
	Year = 0;
	Month= 0;
	Day=0;
	Hour=0;
	Minute=0;
	Second=0;
}

NetTime::~NetTime()
{
}

void NetTime::Timeinit()
{
	
	
}


void NetTime::SetLocalTime()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	struct timeval nowTimeval;
	struct tm * tm;
	gettimeofday(&nowTimeval, NULL);
	time_t time_sec;
	time_sec = nowTimeval.tv_sec;
	tm = localtime(&time_sec);
	Year = tm->tm_year + 1900;
	Month = tm->tm_mon;
	Day = tm->tm_mday;
	Hour = tm->tm_hour;
	Minute = tm->tm_min;
	Second = tm->tm_sec;
#endif
#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	struct tm * tm;
	time_t time_sec;
	time(&time_sec);
	tm = localtime(&time_sec);
	Year = tm->tm_year + 1900;
	Month = tm->tm_mon+1;
	Day = tm->tm_mday;
	Hour = tm->tm_hour;
	Minute = tm->tm_min;
	Second = tm->tm_sec;

#endif
}
