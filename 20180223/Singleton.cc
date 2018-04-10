 ///
 /// @file    Singleton.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-23 17:17:48
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
			if(NULL==_pInstance)
			{
				_pInstance=new Singleton;
			}
			return _pInstance;
		}
	private:
		Singleton(){}

		static Singleton * _pInstance;
};
Singleton * Singleton::_pInstance=NULL;

int main(void)
{
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	Singleton *p3=Singleton::getInstance();

	printf("p1=%p\n",p1);
	printf("p2=%p\n",p2);
	printf("p3=%p\n",p3);

	return 0;
}
