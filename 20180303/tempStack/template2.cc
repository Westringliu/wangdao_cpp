 ///
 /// @file    template2.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-03 16:28:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T,char number = 'a'>
T func(T x,T y)
{
	return x * y * number;
}

int main(void)
{
	int a = 1,b = 2;
	cout << func<int,20>(a,b) << endl;
	cout << func<int>(a,b) << endl;
	return 0;
}
