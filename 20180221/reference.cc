///
/// @file    reference.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-21 13:16:54
///

#include <iostream>
using std::cout;
using std::endl;

//1. 函数传参的方式 --> 值传递 --> 进行复制

#if 0
void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
#endif

//2. 函数传参的方式 --> 地址传递 --> 值传递 --> 进行复制
void swap(int * p, int * q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

//3. 函数传参的方式 --> 引用传递 --> 没有复制，直接操作实参本身, 
//执行效率要比值传递要高。使用起来也比较直观
void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}


int test0(void)
{
	int a = 100;
	int & refa = a;//引用, 就是一个变量的别名

	cout << "a = " << a << endl;
	refa = 10;

	cout << "a = " << a << endl;
	cout << "refa = " << a << endl;

	//int & refb;//引用不能单独存在，必须要进行初始化,绑定到一个实体之上
	return 0;
}

void test1()
{
	int a = 3;
	int b = 4;
	cout << "交换之前: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	swap(a, b);
	//swap(&a, &b);
	cout << "交换之后: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main(void)
{
	test1();

	return 0;
}
