/// @file    String2.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-02-22 11:21:57
///

#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

class String
{

	public:
	String()
	{
	
	}
		String(const char * pstr)
			: _pstr(new char[strlen(pstr) + 1]()) //深拷贝
	{
		cout << "String(const char *,float)" << endl;
		strcpy(_pstr, pstr);
	}
#if 0
		//系统赋值运算符函数原型
		String(const String & rhs)
			: _pstr(rhs._pstr)
	{
		cout << "String(const String&)" << endl;
	}
#endif
		//系统的赋值运算符函数为浅拷贝，不能满足需求。手动改为深拷贝	
		String(const String & rhs)
		: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		cout << "String(const String&)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

		String & operator=(const String &rhs)
		{
			cout<<"String & operator=(const String & rhs)"<<endl;
			if(this!=&rhs)
			{
				delete [] _pstr;

				this->_pstr=new char[strlen(rhs._pstr)+1]();
				strcpy(_pstr,rhs._pstr);

			}
			return *this;
		}

		~String()
		{
			cout << "~String()" << endl;
			delete [] _pstr;
		}

		void print();
	private:
		char * _pstr;
};


void print()
{
	cout << "print()" << endl;
}

//在类之外实现成员函数
void String::print()
{
	cout << "pstr:" << _pstr << endl;
}

int main()
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");

	str2.print();		
	str3.print();	

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
