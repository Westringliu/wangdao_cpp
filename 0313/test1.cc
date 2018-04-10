 ///
 /// @file    test1.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-13 10:44:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int add(int a,int b);

int main()
{
	extern int x,y;
	cout << add(x,y) << endl;
}

int x= 20,y = 5;
int add(int a,int b)
{
	int s = a+b;
	return s;
}
