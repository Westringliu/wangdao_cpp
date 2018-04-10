 ///
 /// @file    test.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-15 08:33:31
 ///

#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main()
{
	char str[10] = "hello";
	string ch = "world!";
	char * chr = str;
	strcpy(chr,str);
	cout << strlen("world!") << endl;
	cout << sizeof str << endl;
	cout << sizeof(ch) << endl;
	cout << sizeof("hello") << endl;
	return 0;
}
