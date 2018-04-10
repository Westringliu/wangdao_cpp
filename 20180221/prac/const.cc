 ///
 /// @file    const.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-26 18:01:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int a=20;
	int b=200;
	cout <<"a="<<a<<endl;

	const int *pa=&a;
	*pa=30;
	cout<<"*pa="<<*pa<<endl;
}
