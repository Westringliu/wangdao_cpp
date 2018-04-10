///
/// @file    namespace2.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-21 15:34:09
///

#include <iostream>

namespace A
{

	void displayA()
	{
		//命名空间的第二种使用方式：作用域限定符
		std::cout << "displayA()" << std::endl;
	}
}

using namespace A;

int cout(int a)
{
	return 1;
}

int main(void)
{
	displayA();

	cout(1);
	return 0;
}
