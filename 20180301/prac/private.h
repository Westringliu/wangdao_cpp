 ///
 /// @file    impl.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-01 15:51:35
 ///

#ifndef __IMPL_H_INCLUDE__
#define __IMPL_H_INCLUDE__

#include "public.h"
#include <iostream>

class Book::BookImpl
{
public:
	void print();

private:
	std::string m_Contents;
	std::string m_Title;
};

#endif
