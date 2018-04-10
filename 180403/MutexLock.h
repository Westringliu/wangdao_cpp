 ///
 /// @file    MutexLock.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-03 11:26:43
 ///

#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	pthread_mutex_t * getMutexLockPtr();

	void lock();
	void unlock();
private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	:_mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock & _mutex;
};

}

#endif
