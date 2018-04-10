 //
 /// @file    namespace.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-21 10:40:04
 ///
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

int i=100;

namespace B{
	void displayB()
	{
		cout<<"displayB()"<<::i<<endl;
	}
}

namespace A{
	void displayA()
	{
		cout<<"displayA()"<<endl;
		B::displayB();
	}
}

int main(void)
{
	::printf("hello world\n");
	A::displayA();
	B::displayB();
	return 0;
}
