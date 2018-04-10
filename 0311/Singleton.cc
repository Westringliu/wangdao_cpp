 ///
 /// @file    Singleton.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-11 15:45:11
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
		if(NULL == _pInatance)
		{
			_pInatance = new Singleton;
		}
		return _pInatance;
	}
private:
	Singleton(){}
	static Singleton *_pInatance;
};

Singleton * Singleton::_pInatance = NULL;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	printf("p3 = %p\n",p3);
}
