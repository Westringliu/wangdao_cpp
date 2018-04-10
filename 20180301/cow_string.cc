 ///
 /// @file    cow_string.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-01 22:04:52
 ///

#include <string.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char *pstr);
	String(const String &rhs);
	String &operator=(const String &rhs);
	~String();

	int refcount()
	{
		return *(int *)(_pstr - 4);
	}

	const char *c_str() const
	{
		return _pstr;
	}

	char &operator[](size_t idx);

	size_t size()const
	{
		return strlen(_pstr);
	}

private:
	void initRefcount()
	{
		*(int *)(_pstr - 4) = 1;
	}

	void increaseRefcount()
	{
		++*(int *)(_pstr - 4);
	}

	void decreaseRefcount()
	{
		--*(int *)(_pstr - 4);
	}

	void release()
	{
		decreaseRefcount();
		if(0==refcount())
		{
			delete [] (_pstr - 4);
			cout << "~String()" << endl;
		}
	}

	friend std::ostream &operator<<(std::ostream &os,const String &rhs);

private:
	char *_pstr;
	static int flag;
};

String::String()
:_pstr(new char[5]() + 4)
{
	initRefcount();
}

String::String(const char *pstr)
:_pstr(new char[strlen(pstr)+5]() + 4)
{
	strcpy(_pstr,pstr);
	initRefcount();
}

String::String(const String &rhs)
:_pstr(rhs._pstr)
{
	increaseRefcount();
}

String::~String()
{
	release();
}

String &String::operator=(const String &rhs)
{
	if(this != &rhs)
	{
		release();
		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

char &String::operator[](size_t idx)
{
	String str;
	static char nullchar = '\0';
	if(idx >= size())
	{
		return nullchar;
	}else if(1!=str.flag)
	{
		if(refcount() > 1)
		{
			decreaseRefcount();
			char *ptmp = new char[size() + 5]() + 4;
			strcpy(ptmp,_pstr);
			_pstr = ptmp;
			initRefcount();
		}
	}
		return _pstr[idx];
}

std::ostream &operator<<(std::ostream &os,const String &rhs)
{
	String str;
	str.flag=1;
	os << rhs._pstr;
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

int test1(void)
{
	String s1="hello,world";
	cout << "s1's refcount = " << s1.refcount() << endl;
	String s2(s1);
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());

	String s3 = "shenzhen,wangdao";
	s2 = s3;
	cout << "s1's refcount()" << s1.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());

	s3[0]= 'S';
	cout << "s1's refcount()" << s1.refcount() << endl;
	cout << "s2's refcount()" << s2.refcount() << endl;
	cout << "s3's refcount()" << s3.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	return 0;
}

int test2(void)
{
	String s1="hello,world";
	cout << "s1's refcount = " << s1.refcount() << endl;
	String s2(s1);
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());

	String s3 = "shenzhen,wangdao";
	s2 = s3;
	cout << "s1's refcount()" << s1.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());

	cout << "s3[0] = " << s3[0] <<endl;
	cout << "s1's refcount()" << s1.refcount() << endl;
	cout << "s2's refcount()" << s2.refcount() << endl;
	cout << "s3's refcount()" << s3.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("&s1 = %p\n",s1.c_str());
	printf("&s2 = %p\n",s2.c_str());
	printf("&s3 = %p\n",s3.c_str());
	return 0;
}
int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
