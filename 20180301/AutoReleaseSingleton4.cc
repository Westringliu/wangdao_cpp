///
/// @file    Singleton.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-03-01 15:20:34
///

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;


//单例对象的自动释放
//方法三：pthread_once + atexit
class Singleton
{
	public:
		static Singleton * getInstance() 
		{
			//pthread_once方法的作用：在多线程环境之下，其注册的函数只会被执行一次
			::pthread_once(&_once, init);
			return _pInstance;
		}

		static void init(void)
		{
			_pInstance = new Singleton;
			::atexit(destroy);
		}

		static void destroy()
		{
			if(_pInstance)
				delete _pInstance;
		}

	private:
		Singleton(){	cout << "Singleton()" << endl;}
		~Singleton(){	cout << "~Singleton()" << endl;}

	private:
		static Singleton * _pInstance;
		static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = NULL ;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	//....do something;
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);


	return 0;
}

