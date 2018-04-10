 ///
 /// @file    empty.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-23 13:23:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Empty
{};

int main()
{
	Empty e1;
	Empty e2;
	cout<<sizeof(Empty)<<endl;

	return 0;
}
