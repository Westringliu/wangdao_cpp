 ///
 /// @file    Condition.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-04 11:36:34
 ///

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__  

#include <pthread.h>

namespace wd
{
class MutexLock;

class Condition
{
public:
	Condition(MutexLock &);

	~Condition();

	void wait();
	void notify();
	void notifyall();

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};
}

#endif
