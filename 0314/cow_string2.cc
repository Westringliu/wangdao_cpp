 ///
 /// @file    cow_string.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-13 20:34:01
 ///

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	class CharProxy
	{
	public:
		CharProxy(String &self,size_t idx)
		:_self(self)
		,_idx(idx)
		{}

		CharProxy &operator=(const char &ch);

		operator char()
		{ return _self._pstr[_idx];}

	private:
		String &_self;
		size_t _idx;
	};

	String();

	String(const char *pstr);

	String(const String &rhs);

	String &operator=(const String &rhs);

	~String();

	CharProxy operator[](size_t idx);

	//char &operator[](size_t idx);
	
	const char *c_str() const
	{
		return _pstr;
	}

	size_t size() const
	{
		return strlen(_pstr);
	}

	int refcount()
	{
		return *(int *)(_pstr - 4);
	}
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
		if(refcount()==0)
		{
			delete [](_pstr - 4);
			cout << "~String()" << endl;
		}
	}


friend std::ostream &operator<<(std::ostream &os,const String &rhs);

private:
	char *_pstr;
};


String::String()
:_pstr(new char[5]()+4)
{
	initRefcount();
}

String::~String()
{
	release();
}

String::String(const char *pstr)
:_pstr(new char[strlen(pstr) + 5]() + 4)
{
	strcpy(_pstr,pstr);
	initRefcount();
}

String::String(const String &rhs)
:_pstr(rhs._pstr)
{
	increaseRefcount();
}

String & String::operator=(const String &rhs)
{
	if(this!=&rhs)
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

String::CharProxy &String::CharProxy::operator=(const char &ch)
{
	if(_idx < _self.size())
	{
		if(_self.refcount() > 1)
		{
			_self.decreaseRefcount();
			char *ptmp = new char[_self.size() + 5]() + 4;
			strcpy(ptmp,_self._pstr);//cp content to new space
			_self._pstr = ptmp;//point to new space
			_self.initRefcount();//init reference
		}
		_self._pstr[_idx] = ch;
	}
	return *this;
}

#if 0
char & String::operator[](size_t idx)
{
	static char nullchar = '\0';
	if(idx >= size())
	{
		return nullchar;
	}
	else
	{
		if(refcount() > 1)
		{
			decreaseRefcount();

			char *ptmp = new char[size() + 5]() + 4;
			strcpy(ptmp,_pstr);
			_pstr = ptmp;
			initRefcount();
		}
		return _pstr[idx];
	}
}
#endif

std::ostream &operator<<(std::ostream &os,const String &rhs)
{
	os << rhs._pstr;
	return os;
}

void test0(void)
{
	String s1;
	cout << "s1's refcount = " << s1.refcount() << endl;
	String s2(s1);
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s1's refcount = " << s2.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("s1 = %p\n",s1.c_str());
	printf("s2 = %p\n",s2.c_str());
}

void test1(void)
{
	String s1("hello,world");
	cout << "s1's refcount = " << s1.refcount() << endl;
	String s2(s1);
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("s1 = %p\n",s1.c_str());
	printf("s2 = %p\n",s2.c_str());
	cout << endl;

	String s3 = "shenzhen,wangdao";
	s2 = s3;
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1 = %p\n",s1.c_str());
	printf("s2 = %p\n",s2.c_str());
	printf("s3 = %p\n",s3.c_str());
}

void test2(void)
{
	String s1("hello,world");
	cout << "s1's refcount = " << s1.refcount() << endl;
	String s2(s1);
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	printf("s1 = %p\n",s1.c_str());
	printf("s2 = %p\n",s2.c_str());
	cout << endl;

	String s3 = "shenzhen,wangdao";
	s2 = s3;
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1 = %p\n",s1.c_str());
	printf("s2 = %p\n",s2.c_str());
	printf("s3 = %p\n",s3.c_str());

	cout << "----reading----" << endl;
	cout << "s3 = " << endl;
	for(size_t idx = 0;idx < s3.size(); ++idx)
	{
		cout << s3[idx];
	}
	cout << endl;
	cout << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s2 = %p\n",s2.c_str());
	printf("s3 = %p\n",s3.c_str());

}

int main(void)
{
	test1();
	test2();
	return 0;
}

