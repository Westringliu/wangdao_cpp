 ///
 /// @file    Noncopyable.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-04 11:39:38
 ///

#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd
{

class Noncopyable
{
protected:
	Noncopyable(){}

	~Noncopyable(){}

	Noncopyable(const Noncopyable &) = delete;

	Noncopyable & operator=(const Noncopyable &) = delete;
};
}

#endif
