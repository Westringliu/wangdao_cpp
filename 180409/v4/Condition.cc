 ///
 /// @file    Condition.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-27 16:03:59
 ///
 
#include "Condition.h" //相对应的头文件一定要放在实现文件的第一位

#include "MutexLock.h"

namespace wd
{

Condition::Condition(MutexLock & mutex)
: _mutex(mutex)
{
	pthread_cond_init(&_cond, NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond, _mutex.getMutexLockPtr());
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
