 ///
 /// @file    Timer.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-09 20:28:45
 ///
 
#ifndef __WD_TIMER_H__
#define __WD_TIMER_H__

#include <functional>

namespace wd
{

class Timer
{
	using TimerCallback = std::function<void()>;
public:
	Timer(int initTimer,int intervalTime,TimerCallback cb);

	void start();
	void stop();
private:
	void handleRead();

private:
	int _fd;
	int _initTime;
	int _intervalTime;
	TimerCallback _cb;
	bool _isStarted;
};

}

#endif
