 ///
 /// @file    TaskThreadpool.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-04 11:46:24
 ///
 
#include "Threadpool.h"

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class MyTask
:public wd::Task
{
public:
	void process()
	{
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << pthread_self() << " > produce a number : " << number << endl;
		::sleep(1);
	}
};

int main(void)
{
	wd::Threadpool threadpool(4,10);

	unique_ptr<wd::Task> up(new MyTask);
	threadpool.start();
	int cnt = 20;
	while(cnt--)
	{
		threadpool.addTask(up.get());

		cout << " cnt = " << cnt << endl;
	}

	threadpool.stop();

	return 0;
}


