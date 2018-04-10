 ///
 /// @file    Book.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-01 16:00:17
 ///
#include "public.h"
#include "private.h"
#include <iostream>
using std::cout;
using std::endl;

Book::Book()
{
	pimpl=new BookImpl();
}

Book::~Book()
{
	delete pimpl;
}

void Book::print()
{
	pimpl->print();
}

void Book::BookImpl::print()
{
	cout<<"print from BookImpl"<<endl;
}

int main(void)
{
	Book bk;
	bk.print();

	return 0;
}
