 ///
 /// @file    Condition.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-03 21:41:36
 ///
 
#include "Condition.h"
#include "MutexLock.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Condition::Condition(MutexLock & mutex)
: _mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::notifyall()
{
	pthread_cond_broadcast(&_cond);
}
}
