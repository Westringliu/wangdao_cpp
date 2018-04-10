 ///
 /// @file    String.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-12 10:45:30
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String()
	:_pstr(new char[1]())
	{
		cout << "String()" << endl;
	}

	String(const char *pstr)
	:_pstr(new char[strlen(pstr) + 1]())
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr,pstr);
	}
	String(const String &rhs)
	:_pstr(new char[strlen(rhs._pstr)+ 1]())
	{
		cout << "String(const String&)" << endl;
		strcpy(_pstr,rhs._pstr);
	}

	String &operator=(const String &rhs)
	{
		cout << "String &operator=(const String &)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}

	void print()
	{
		if(_pstr)
			cout << _pstr << endl;
	}

	~String()
	{
		cout << "~String()" << endl;
		delete []_pstr;
	}
private:
	char *_pstr;
};

int main(void)
{
	String s1;
	s1.print();

	String s2 = "hello";//自动类型转换,会生成临时对象
	s2.print();

	String s3("wangdao");//调用传递字符串的复制构造函数
	s3.print();

	String s4 = s3;//用s3初始化s4,调用传递对象的复制构造函数
	cout << "s4 = ";
	s4.print();

	s4 = s2;//调用赋值运算符函数，进行深拷贝
	cout << "s4 = ";
	s4.print();

	cout << "----" << endl;
	return 0;
}
