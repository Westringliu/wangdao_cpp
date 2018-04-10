 ///
 /// @file    TaskQueue.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-04 11:27:24
 ///

#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"

#include <queue>

namespace wd
{

class Task;

class TaskQueue
{
	using Product = Task *;
public:
	TaskQueue(int queSize);

	void push(Product);
	Product pop();

	bool full() const;
	bool empty() const;
	
	void wakeup();

private:
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	size_t _queSize;
	std::queue<Product> _que;
	bool _flag;
};

}

#endif
