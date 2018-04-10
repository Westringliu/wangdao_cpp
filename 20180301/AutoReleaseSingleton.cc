 ///
 /// @file    AutoReleaseSingleton.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-01 20:55:49
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton *getInstance()
	{//delay mode,not safe in pthreads
		if(NULL == _pInstance)
			_pInstance = new Singleton;
		return _pInstance;
	}

	class WallE
	{
	public:
		WallE(){cout << "WallE" << endl;}

		~WallE()
		{
			if(_pInstance)
			{
				delete _pInstance;
				cout << "~WallE" << endl;
			}
		}
	};

private:
	Singleton(){cout << "Singleton" << endl;}
	~Singleton(){cout << "~Singleton" << endl;}

private:
	static Singleton *_pInstance;
	static WallE _we;
};

Singleton *Singleton::_pInstance = NULL;
Singleton::WallE Singleton::_we;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);

	return 0;
}

