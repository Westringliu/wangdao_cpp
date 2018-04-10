///
/// @file    static_cast.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-21 19:07:07
///

#include <iostream>
using std::cout;
using std::endl;

void test0(void)
{
	double da = 5.55;
	int ib = 10;

	ib = (int)da;
	cout << "ib = " << ib << endl;
}

void test1(void)
{
	double da = 5.55;
	int ib = 10;

	ib = static_cast<int>(da);
	cout << "ib = " << ib << endl;
}

int main(void)
{
//	test0();
	test1();
	return 0;
}
