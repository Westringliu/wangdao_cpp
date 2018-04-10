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

class MyThread
:public wd::Thread
{
public:
	~MyThread(){	cout << "~MyThread()" << endl;}

private:
	void run()
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

private:
	double _d;
};

int main(void)
{
	unique_ptr<wd::Thread> pThread(new MyThread);

	cout << "main " << pthread_self() << endl;
	
	pThread->start();

	pThread->join();

	return 0;
}
