 ///
 /// @file    operator.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-01 20:08:02
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
public:
	CharArray(int size)
	:_size(size)
	,_parr(new char[size+1]())
	{}

	char &operator[](int idx)
	{
		static char nullchar = '\0';
		if(idx >= 0 && idx < _size)
		{
			return _parr[idx];
		}
		return nullchar;
	}

	int size()
	{
		return strlen(_parr);
	}

	~CharArray()
	{
		delete [] _parr;
	}

private:
	int _size;
	char *_parr;
};

int main(void)
{
	const char *pstr = "hello,world";

	CharArray carr(strlen(pstr)+1);
	for(int idx = 0;idx < strlen(pstr);++idx)
	{
		carr[idx] = pstr[idx]; 
	}

	for(int idx = 0;idx < carr.size(); ++idx)
	{
		cout << carr[idx];
	}
	cout << endl;

	return 0;
}
