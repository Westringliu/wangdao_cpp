 ///
 /// @file    Thread.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-02 11:51:07
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include <pthread.h>

namespace wd
{
class Thread
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();
private:
	static void * threadFunc(void * arg);
	virtual
		void run() = 0;

private:
	pthread_t _pthId;
	bool _isRunning;
};
}


#endif
