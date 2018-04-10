 ///
 /// @file    Thread.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-09 20:49:55
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__    

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace wd
{

class Thread
:Noncopyable
{
	using ThreadCallback = std::function<void()>
}
}
