///
/// @file    overload.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-21 19:16:16
///

#include <stdio.h>
#include <iostream>

int add(int x,int y)
{
	return x+y;
}

int add(int x,int y,int z)
{
	return x+y+z;
}

int main(void)
{
	int a = 1,b = 2,c = 3;
	printf("a + b = %d\n",add(a,b));
	printf("a + b + c = %d\n",add(a,b,c));
	return 0;
}
