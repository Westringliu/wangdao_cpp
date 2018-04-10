 ///
 /// @file    inline.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-21 20:14:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#define Max(x,y) ((x)>(y)?(x):(y))
inline
int max(int x,int y)
{
	return	x>y?x:y;
}
int main(void)
{
	int a=3,b=4,c=5;
	cout << Max(a+b,b+c)<<endl;
	cout << max(a,b) <<endl;
	return 0;
}
