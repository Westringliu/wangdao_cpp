 ///
 /// @file    Thread.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-02 11:51:07
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include <pthread.h>
#include <functional>

namespace wd
{
class Thread
{
	typedef std::function<void()> ThreadCallback;
	//using ThreadCallback = std::function<void()>;
public:
	Thread(ThreadCallback);
	~Thread();

	void start();
	void join();
private:
	static void * threadFunc(void * arg);

private:
	pthread_t _pthId;
	bool _isRunning;
	ThreadCallback _cb;
};
}


#endif
