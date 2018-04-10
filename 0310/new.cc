 ///
 /// @file    new.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-10 20:48:15
 ///

#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

void test0(void)
{
	int *pa = (int *)malloc(sizeof(int) * 10);
	cout << "*pa = " << *pa << endl;
	*pa = 10;
	free(pa);
}

void test1(void)
{
	int *pb = new int(1);
	cout << "*pb = " << *pb << endl;
	delete pb;
}

void test2(void)
{
	int *pc = new int [10];
	for(int idx = 0;idx != 10; ++idx)
	{
		pc[idx] = idx;
	}
	for(int idx = 0;idx != 10; ++idx)
	{
		cout << pc[idx] << " ";
	}
	cout << endl;
	delete [] pc;
}

int main(void)
{
	cout << "----test0()----" << endl;
	test0();	
	cout << "----test1()----" << endl;
	test1();	
	cout << "----test2()----" << endl;
	test2();	
}
