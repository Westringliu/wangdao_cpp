 ///
 /// @file    test.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-16 16:32:40
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	*(int * const)(0x67a9) = 0xaa66;
	cout << (int *)0x67a9 << endl;
}
