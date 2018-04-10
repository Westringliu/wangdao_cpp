 ///
 /// @file    AutoReleaseSingleton.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-01 20:55:49
 ///

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton *getInstance()
	{//delay mode,not safe in pthreads
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
			::atexit(destroy);
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton(){cout << "Singleton" << endl;}
	~Singleton(){cout << "~Singleton" << endl;}

private:
	static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance = getInstance();

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);

	return 0;
}

