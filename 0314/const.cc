 ///
 /// @file    const.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-14 16:03:51
 ///

#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

char *GetMemory(void)
{
	char p[] = "hello ,world";
	return p;
}

void test(void)
{
	char *str = NULL;
	str = GetMemory();
	cout << str << endl;
}

int main(void)
{
	while(1)
	{
		test();
		cout << "run test() " << endl;
		sleep(1);
	}
}
