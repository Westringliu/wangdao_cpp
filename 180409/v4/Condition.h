 ///
 /// @file    Condition.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-27 15:54:32
 ///
 
#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include <pthread.h>

namespace wd
{

class MutexLock;//类的前向声明, 减少头文件的依赖

class Condition
{
public:
	Condition(MutexLock & );
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
