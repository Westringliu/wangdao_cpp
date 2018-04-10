 ///
 /// @file    String.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-27 15:05:12
 ///

#include <string.h>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class String
{
public:
	String()
	:_pstr(new char[1]())
	{
		cout << "String()" << endl;
	}

	String(const char * pstr)
	:_pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr,pstr);
		cout << "String(const char *)" << endl;
	}

	String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr,rhs._pstr);
		cout << "String(const String &)" << endl;
	}

	String & operator=(const String & rhs)
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

	String(String && rhs)
	:_pstr(rhs._pstr)
	{
		rhs._pstr = NULL;
		cout << "String(String &&)" << endl;
	}

	String & operator=(String && rhs)
	{
		cout << "String & operator=(String &&)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = NULL; 
		}
		return * this;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}

friend std::ostream & operator<<(std::ostream &os,const String &);

private:
	 char * _pstr;
};

std::ostream & operator<<(std::ostream & os,const String & rhs)
{
	os << rhs._pstr;
	return os;
}

int main(void)
{
#if 0
	vector<String> vec;
	vec.push_back("hello,world");
	cout << " ";
#endif

	String s1("hello,world");
	s1 = String("shenzhen");
	cout << "s1 = " << s1 << endl;

	String s2 = std::move(s1);

	cout << "s1 = " << s1 << endl;

	cout << "-----" << endl;
	return 0;
}
