 ///
 /// @file    function.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-01 19:43:24
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

struct Demo
{
	Demo()
	:_cnt(0)
	{}

	int operator()(int x,int y)
	{
		++_cnt;
		cout << "this function be used" << _cnt << "times" << endl;
		return x + y;
	}

	int operator()(int x,int y,int z)
	{
		return x*y*z;
	}

private:
	int _cnt;
};

int  main(void)
{
	Demo demo;
	Demo demo2;
	cout << "demo(3,4) = " << demo(3,4) << endl;
	cout << "demo(4,5) = " << demo(4,5) << endl;
	cout << "demo(2,3,4) = " << demo(2,3,4) <<endl;

	return 0;
}
