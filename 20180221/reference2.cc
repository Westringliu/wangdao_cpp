 ///
 /// @file    reference.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-21 13:04:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//作为函数的返回值
int arr[5]={1,2,3,4,5};
//如果这里直接返回int型数据，return时是要进行复制的
int func()
{
	return arr[0];
}
//如果返回值是引用，return时不会进行复制
int & func2()
{
	return arr[0];
}
//不要返回一个局部变量的引用
int & func3()
{
	int a = 10;
	return a;//不要返回一个局部变量的引
}
//不要轻易返回一个堆空间变量的引用,除非你有了一个内存回收的策
int & func5()
{
	int *pa = new int(10);
	return *pa;
}

int * func4()
{
	int a = 10;
	return &a;
}

int test0(void)
{
	func2()=10;
	cout << "arr[0] = " << arr[0] << endl;
	int & refa = func3();

	cout << "refa = " << refa << endl;
	return 0;
}

void test1(void)
{
	int x = 1;
	int y = 2;
	int z = x + y + func5();
	cout << "z = " << z << endl;

	int & ref = func5();
	cout << "ref = " << ref << endl;

	delete (&ref);
}

int main(void)
{
	test1();
	return 0;
}
