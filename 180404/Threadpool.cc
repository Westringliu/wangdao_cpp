 ///
 /// @file    Threadpool.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-04 11:57:17
 ///

#include "Threadpool.h"
#include "WorkerThread.h"
#include <unistd.h>

namespace wd
{

Threadpool::Threadpool(size_t threadNum,size_t queSize)
: _threadNum(threadNum)
, _queSize(queSize)
, _taskque(_queSize)
, _isExit(false)
{
	_threads.reserve(_threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit)
		stop();
}

void Threadpool::start()
{
	for(size_t idx = 0;idx != _threadNum; ++idx)
	{
		shared_ptr<Thread> sp(new WorkerThread(*this));
		_threads.push_back(sp);
	}

	for(auto & subThread : _threads)
	{
		subThread->start();
	}
}

void Threadpool::stop()
{
	if(!_isExit)
	{
		while(!_taskque.empty())
		{
			::sleep(2);
		}

		_isExit = true;

		_taskque.wakeup();

		for(auto & subThread : _threads)
		{
			subThread->join();
		}
	}
}

void Threadpool::addTask(Task * ptask)
{
	_taskque.push(ptask);
}

Task * Threadpool::getTask()
{
	return _taskque.pop();
}

void Threadpool::threadFunc()
{
	while(!_isExit)
	{
		Task * ptask = getTask();
		if(ptask)
			ptask->process();
	}
}
}
