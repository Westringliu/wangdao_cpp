 ///
 /// @file    Thread.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-04 11:42:18
 ///

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class Thread
: Noncopyable
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();

private:
	static void * threadFunc(void * arg);

	virtual
	void run()=0;

private:
	pthread_t _pthId;
	bool _isRunning;
};
}

#endif
