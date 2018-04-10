 ///
 /// @file    template1.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-03 16:18:46
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

template <class T>
T add(T x,T y)
{
	cout << "T add(T,T)" << endl;
	return x + y;
}

template <class T>
T add(T x,T y,T z)
{
	return x + y + z;
}

int add(int x,int y)
{
	cout << "int add(int,int)" << endl;
	return x + y;
}

template <>
char *add<char *>(char *p1,char *p2)
{
	char *ptmp = new char[strlen(p1) + strlen(p2) + 1]();
	strcpy(ptmp, p1);
	strcat(ptmp, p2);

	return ptmp;
}

int test0(void)
{
	int a = 1,b = 2,ia = 3;
	double c = 1.1,d = 2.2;
	char e = 'a',f = 1;
	
	cout << "a + b = " << add(a, b) << endl;//隐式实例化
	cout << "c + d = " << add<double>(c, d) << endl;//显式实例化
	cout << "e + f = " << add(e, f) << endl;

	cout << "a + b + ia = " << add(a,b,ia) << endl;

	return 0;
}

int test1(void)
{
	char s1[] = "hello";
	char s2[] = "world";

	cout << add(s1,s2) << endl;

	return 0;
}

int main(void)
{
	//test0();

	test1();
	
	return 0;
}
