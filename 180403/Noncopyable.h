 ///
 /// @file    Noncopyable.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-03 12:05:14
 ///

#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd
{

class Noncopyable
{
	Noncopyable();
	~Noncopyable();

	Noncopyable(const Noncopyable &) = delete;
	Noncopyable & operator=(const Noncopyable &) = delete;
};
}

#endif
