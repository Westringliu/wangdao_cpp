///
/// @file    memory.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-22 13:06:47
///
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int a=1;
char *p1;
const int d=100;

int test(void)
{
	int b;
	char s[] = "123456";//栈区
	char * p2;
	const char * p3 = "123456";//文字常量区
	//*p3 = 'H';//error
	
	s[1]='9';
	printf("s[1]=%s\n",s);

	const int e = 10;//栈区,没有放在文字常量区，与生命周期有关

	static int c = 1;//没有入栈，在全局/静态区

	p1 = new char[10];
	p2 = new char[20];

	printf("&a = %p\n", &a);
	printf("&p1 = %p\n", &p1);
	printf("p1 = %p\n", p1);
	printf("&b = %p\n", &b);
	printf("s = %p\n", s);
	printf("&p2 = %p\n", &p2);
	printf("p2 = %p\n", p2);
	printf("p3 = %p\n", p3);
	printf("&p3 = %p\n", &p3);
	printf("&c = %p\n", &c);
	printf("&test = %p\n", test);
	printf("&d = %p\n", &d);
	printf("&e = %p\n", &e);
	
	return 0;
}
int main(void)
{
	test();
	return 0;
}
