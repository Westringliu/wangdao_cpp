 ///
 /// @file    new.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-21 18:22:41
 ///
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
//malloc/free与 new/delete 的区别

int main()
{
	int * pa = (int *)malloc(sizeof(int));
	//memset/bzero
	*pa = 10;
	cout << "*pa = " << *pa << endl;
	free(pa);//防止发生内存泄

	int *pb = new int(1);
	cout << "*pb = " << *pb << endl;
	delete pb;
	
	int *pc = new int[10];
	for(int idx = 0;idx != 10; ++idx)
	{
		pc[idx] = idx;
	}
	delete [] pc;//数组回收

	return 0;
}

