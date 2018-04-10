///
/// @file    cow_string.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-03-20 19:44:37
///

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
	class CharProxy
	{
		public:
			CharProxy(String &self,size_t idx)
				:_self(self)
				 ,_idx(idx)
		{}

			CharProxy &operator=(const char &ch);

			friend std::ostream &operator<<(std::ostream &os,const CharProxy &rhs);
		private:
			String & _self;
			size_t _idx;
	};
	friend std::ostream &operator<<(std::ostream &os,const CharProxy &rhs);

	public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();

	CharProxy operator[](size_t idx);

	int refcount()
	{
		return *(int *)(_pstr - 4);
	}

	const char * c_str() const
	{
		return _pstr;
	}

	size_t size() const
	{return strlen(_pstr);}

	private:
	void initRefcount()
	{
		*(int *)(_pstr - 4) = 1;
	}

	void increaseRefcount()
	{
		++(*(int *)(_pstr - 4));
	}

	void decreaseRefcount()
	{
		--(*(int *)(_pstr - 4));
	}

	void release()
	{
		decreaseRefcount();
		if(refcount() == 0)
		{
			delete [] (_pstr - 4);
			cout << "~String()" << endl;
		}
	}

	friend std::ostream & operator<<(std::ostream & os,const String & rhs);
	private:
	char * _pstr;
};

String::String()
	:_pstr(new char[5]() + 4)
{
	initRefcount();
}
String::String(const char * pstr)
	:_pstr(new char[strlen(pstr) + 5]() + 4)
{
	strcpy(_pstr,pstr);
	initRefcount();
}

String::String(const String & rhs)
	:_pstr(rhs._pstr)
{
	increaseRefcount();
}

String::~String()
{
	release();
}

String & String::operator=(const String & rhs)
{
	if(this != &rhs)
	{
		release();
		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

String::CharProxy String::operator[](size_t idx)
{
	return CharProxy(*this,idx);
}

String::CharProxy &String::CharProxy::operator=(const char & ch)
{
	if(_idx < _self.size())
	{
		if(_idx < _self.size())
		{
			_self.decreaseRefcount();
			char * ptmp = new char[_self.size() + 5]() + 4;
			strcpy(ptmp,_self._pstr);
			_self._pstr = ptmp;
			_self.initRefcount();
		}
		_self._pstr[_idx] = ch;
	}
	return *this;
}
std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

std::ostream & operator<<(std::ostream & os, const String::CharProxy & rhs)
{
	os << rhs._self._pstr[rhs._idx];
	return os;
}
int test0(void)
{
	String s1;
	cout << "s1's refcount = " << s1.refcount() << endl;

	String s2(s1);
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	return 0;
}

void test1(void)
{
	String s1("hello,world");
	String s2(s1);
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("&s1 = %p\n", s1.c_str());
	printf("&s2 = %p\n", s2.c_str());
	cout << endl;

	String s3 = "shenzheng,wagndao";
	s2 = s3;
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s1 = %p\n", s1.c_str());
	printf("&s2 = %p\n", s2.c_str());
	printf("&s3 = %p\n", s3.c_str());

	cout << endl << "执行写操作" <<endl;
	s3[0] = 'S';// CharProxy = char
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s2 = %p\n", s2.c_str());
	printf("&s3 = %p\n", s3.c_str());

	cout << "----test1() exit-----" << endl << endl;
}

void test2(void)
{
	cout << "----test2() start -----" << endl;
	String s1("hello,world");
	String s2(s1);
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("&s1 = %p\n", s1.c_str());
	printf("&s2 = %p\n", s2.c_str());
	cout << endl;

	String s3 = "shenzheng,wagndao";
	s2 = s3;
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s1 = %p\n", s1.c_str());
	printf("&s2 = %p\n", s2.c_str());
	printf("&s3 = %p\n", s3.c_str());

	cout << endl << "执行读操作" <<endl;
	cout << "s3[0] = " << s3[0] << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s2 = %p\n", s2.c_str());
	printf("&s3 = %p\n", s3.c_str());
}

int main(void)
{
	test0();
	test1();
	test2();
	return 0;
}

