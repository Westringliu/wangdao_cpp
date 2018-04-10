 ///
 /// @file    AutoReleaseSingleton.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-13 18:18:26
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
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
		}
		return _pInstance;
	}
	
	class AutoRelease
	{
	public:
		AutoRelease(){cout << "AutoRelease()" << endl;}

		~AutoRelease()
		{
			if(_pInstance)
			{
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};
private:
	static Singleton *_pInstance;
	static AutoRelease _auto;
};

Singleton *Singleton::_pInstance = NULL;//hungry man model
Singleton::AutoRelease Singleton::_auto;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);

	return 0;
}
