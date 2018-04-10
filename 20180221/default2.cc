 ///
 /// @file    default.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-21 19:39:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int add(int x,int y=0)
{
	return x+y;
}

double add(double x,double y,double z=1.1)
{
	return x+y+z;
}

int main(void)
{
	int a=1,b=2;
	cout << "a+b=" << add(a,b) <<endl;
	cout << "a+b=" << add(a) << endl;
	cout << "a+b+c=" << add(a,b) <<endl;
	return 0;
}
