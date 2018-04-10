 ///
 /// @file    test.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-16 16:32:40
 ///
 
#include <stdio.h>

int main(void)
{
	int * ptr;
	ptr = (int *)0x7ffc45179a0c;
	*ptr = 0xaa66;

	printf("%d\n",*ptr);
	printf("%p\n",ptr);
	//cout << ptr << endl;
	//cout << *ptr << endl;

	return 0;
}
