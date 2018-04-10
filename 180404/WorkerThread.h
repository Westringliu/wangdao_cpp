 ///
 /// @file    WorkerThread.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-04 10:34:13
 ///

#ifndef __WD_WORKERTHREAD_H__
#define __WD_WORKERTHREAD_H__

#include "Thread.h"
#include "Threadpool.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

class WorkerThread
:public Thread
{
public:
	WorkerThread(Threadpool & threadpool)
	: _threadpool(threadpool)
	{
		std::cout << "WorkerThread()" << std::endl;
	}

	~WorkerThread()
	{
		std::cout << "~WorkerThread()" << std::endl;
	}

private:
	void run()
	{
		_threadpool.threadFunc();
	}

private:
	Threadpool & _threadpool;
};

}

#endif
