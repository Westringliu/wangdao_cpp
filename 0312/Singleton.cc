 ///
 /// @file    Singleton.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-12 11:33:29
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton *getInstance()
	{
		if(_pInstance == NULL)
		{
			_pInstance = new Singleton;
			return _pInstance;
		}
		return _pInstance;
	}
	static void destroy()
	{
		if(_pInstance)
		delete _pInstance;
	}
private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}
	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}
	static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance = NULL;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();

	printf("%p\n",p1);
	printf("%p\n",p2);
	printf("%p\n",p3);

	Singleton::destroy();

	return 0;
}
