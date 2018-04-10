 ///
 /// @file    MutexLock.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-03 21:27:25
 ///

#include "MutexLock.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

MutexLock::MutexLock()
: _isLocking(false)
{
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

pthread_mutex_t * MutexLock::getMutexLockPtr()
{
	return & _mutex;
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocking = false;
}

}
