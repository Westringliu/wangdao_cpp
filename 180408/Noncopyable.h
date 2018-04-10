 ///
 /// @file    Noncopyable.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-08 17:06:17
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
private:
	Noncopyable(const Noncopyable &);
	Noncopyable & operator=(const Noncopyable &);
};
}

#endif
