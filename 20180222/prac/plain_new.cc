///
/// @file    plain_new.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-26 21:13:17
///

#include <iostream>
using namespace std;
char *GetMemory(unsigned long size)
{
	char *p=new char[size];//分配失败，不是返回NULL
	return p;
}

int main()
{
	try
	{
		char *p=GetMemory(10e11);// 分配失败抛出异常std::bad_alloc
		//...........
		if(!p)//徒劳
			cout<<"failure"<<endl;
		delete [] p;
	}
	catch(const std::bad_alloc &ex)
	{
		cout<<ex.what()<<endl;
	}
	return 0;
}


