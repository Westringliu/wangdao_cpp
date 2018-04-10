 ///
 /// @file    TestThread.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-02 14:59:48
 ///

#include "Thread.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

struct Task
{
	void getNumber(void);
#if 0
	{
		::srand(::time(NULL));
		int cnt = 10;
		while(cnt--)
		{
			int number = ::rand() % 100;
			cout << "> " << pthread_self() << ":number = " << number << endl;
			::sleep(1);
		}
	}
#endif
};

void getNumber(void)
{
	::srand(::time(NULL));
	int cnt = 3;
	while(cnt--)
	{
		int number = ::rand() % 100;
		cout << "> " << pthread_self() << ":number = " << number << endl;
		::sleep(1);
	}
}

int main(void)
{
	cout << "main " << pthread_self() << endl;
	
	wd::Thread thread(getNumber);

	thread.start();

	thread.join();

	return 0;
}
