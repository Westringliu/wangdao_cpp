///
/// @file    overload.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-21 19:16:16
///

#include <stdio.h>
#include <iostream>
//希望他以C的方式调用
#ifdef __cplusplus
extern "C"
{
#endif
	int add(int x,int y)
	{
		return x+y;
	}
#ifdef __cplusplus
}
#endif
int add(int x,int y,int z)
{
	return x+y+z;
}

double add(double x,double y,double z)
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
