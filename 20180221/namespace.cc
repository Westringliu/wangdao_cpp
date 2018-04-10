 //
 /// @file    namespace.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-21 10:40:04
 ///
 
#include <iostream>

using std::cout;
using std::endl;

namespace B{
	void displayB()
	{
		cout<<"displayB()"<<endl;
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
	A::displayA();
	B::displayB();
	return 0;
}
