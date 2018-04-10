 ///
 /// @file    string.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-10 21:09:19
 ///
 
#include <string.h>
#include <stdlib.h>

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0()
{
	char arr1[] = "hello";
	char arr2[] = ",world";

	cout << sizeof(arr1) << endl;
	cout << sizeof(arr2) << endl;
	int length = sizeof(arr1) + sizeof(arr2);
	char * pstr = (char *)malloc(length);
	memset(pstr,0,length);
	strcpy(pstr,arr1);
	strcpy(pstr,arr2);

	cout << "arr1 = " << arr1 << endl;
	cout << "arr2 = " << arr2 << endl;
	cout << "pstr = " << pstr <<  endl;

	char * p1 = strstr(pstr,"world");
	char * psubstr = (char *)malloc(6);
	memset(psubstr,0,6);
	strncpy(psubstr,p1,5);
	cout << "psubstr = " << psubstr << endl;

	free(pstr);
	free(psubstr);
}

void test1()
{
	int a = 100;
	(void)a;

	string s1 = "hello";
	string s2 = ",world";
	string s3 = s1 + s2 + "shenzhen";
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	s3.append("nihao");
	cout << "s3 = " << s3 << endl;

	for(size_t idx = 0;idx != s3.size();++idx)
	{
		cout << s3[idx];
	}

	cout << endl;

	size_t pos = s3.find("ll");
	cout << "pos = " << pos << endl;
	string s4 = s3.substr(pos,5);
	cout << "s4 = " << s4 << endl;

	string s5 = s3.substr(s3.find("lo"),5);
	cout << "s5 = " << s5 << endl;
}
int main(void)
{
	cout << "---test0()---" << endl;
	test0();
	cout << "---test1()---" << endl;
	test1();
	return 0;
}
