 ///
 /// @file    bind.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-26 17:43:22
 ///
 
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <iterator>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class Foo
{
public:
	int func2(int x,int y)
	{
		cout << " int Foo::func2(int ,int)" << endl;
		return x+y;
	}
};

void test1(void)
{
	Foo foo;

	auto f1 = bind(&Foo::func2,foo,std::placeholders::_1,std::placeholders::_2);
	cout << f1(1,2) << endl;//bind make a member func become a general func
	auto f2 = bind(&Foo::func2,&foo,std::placeholders::_1,std::placeholders::_2);
	cout << f2(1,2) << endl;
}

void f(int n1,int n2,int n3,int n4,int n5)
{
	cout << "(" << n1
		<< "," << n2
		<< "," << n3
		<< "," << n4
		<< "," << n5
		<< ")" << endl;
}

void test2(void)
{
	using namespace std::placeholders;
	int n = 7;
	//_2,_1是占位符，代表实际调用是形参的位置
	auto f1 = bind(f,_2,_1,42,std::cref(n),n);//cref是引用包装器,bind绑定参数时其参数位置必须要与绑定的形参一一对应
	n = 10;
	//实际调用时,可以调用N个参数，但是多余的参数都是无效参数
	f1(10,100,1000,2000);
}

int main(void)
{
	test1();
	test2();
	return 0;
}
