///
/// @file    namespace5.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-21 15:31:54
///
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
//C的所有库函数，在C++之中都是位于匿名命名空间的

int a = 100;//全局变量, 它是位于匿名命名空间的

namespace B
{
	int a = 1000;
}

namespace A
{
	int a = 10;

	void displayA(int a)
	{
		//using std::cout;// using声明机制可以尽量放在小范围内使用
		cout << "形参a = " << a << endl;
		cout << "名称空间A中的a = " << A::a << endl;
		cout << "名称空间B中的a = " << B::a << endl;
		cout << "全局变量a = " << ::a << endl;
	}
}//end of namespace A


namespace B
{
	//int a = 1;

	void displayB()
	{
		cout << "displayB()" << endl;
	}
}

int main(void)
{
	::printf("hello,world!\n");
	A::displayA(3);

	return 0;
}
