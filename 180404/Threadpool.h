 ///
 /// @file    Threadpool.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-04 10:42:04
 ///

#ifndef __WD_THREADPOOL_H__
#define __WD_THREADPOOL_H__ 

#include "TaskQueue.h"

#include <memory>
#include <vector>
using std::vector;
using std::shared_ptr;

namespace wd
{
class Task
{
public:
	virtual void process() = 0;
};

class Thread;
class WorkerThread;

class Threadpool
{
	friend WorkerThread;
public:
	Threadpool(size_t threadNum,size_t queSize);
	~Threadpool();

	void start();
	void stop();

	void addTask(Task *);
private:
	Task * getTask();

	void threadFunc(void);
private:
	size_t _threadNum;
	size_t _queSize;
	vector<shared_ptr<Thread>> _threads;
	TaskQueue _taskque;
	bool _isExit;
};

}

#endif
