 ///
 /// @file    TaskQueue.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-03 20:30:04
 ///

#include "TaskQueue.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
TaskQueue::TaskQueue(int queSize)
: _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _queSize(queSize)
{}

bool TaskQueue::full() const
{
	return _que.size() == _queSize;
}

bool TaskQueue::empty() const
{
	return _que.size() == 0;
}

void TaskQueue::push(TaskQueue::Product product)
{
	MutexLockGuard mlg(_mutex);
	while(full())
	{
		_notFull.wait();
	}

	_que.push(product);
	_notEmpty.notify();
}

TaskQueue::Product TaskQueue::pop()
{
	MutexLockGuard mlg(_mutex);
	while(empty())
	{
		_notEmpty.wait();
	}

	Product product = _que.front();
	_que.pop();
	_notFull.notify();

	return product;
}

}
