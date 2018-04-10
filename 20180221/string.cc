 ///
 /// @file    string.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-21 20:23:55
 ///
#include <stdlib.h>
#include <string.h> 

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0(void)
{
	char arr1[]="hello";
	char arr2[]=",world";

	cout<<sizeof(arr1)<<endl;
	cout<<sizeof(arr2)<<endl;
	int length=sizeof(arr1)+sizeof(arr2);
	char *pstr=(char*)malloc(length);
	memset(pstr,0,length);
	strcpy(pstr,arr1);
	strcat(pstr,arr2);

	cout<<pstr<<endl;
	free(pstr);
}

void test1(void)
{
	string s1="hello";
	string s2=",world";
	string s3=s1+s2;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	cout<<"s3="<<s3<<endl;

	s3.append("wangdao");
	cout<<"s3="<<s3<<endl;

	for(size_t idx=0;idx!=s3.size();++idx)
	{
		cout<<s3[idx];
	}
	cout<<endl;
}

int main(void)
{
	test0();
	test1();
	return 0;
}
