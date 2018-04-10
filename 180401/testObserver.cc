 ///
 /// @file    testObserver.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-01 18:16:00
 ///

#include "observer.h"
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

int main(void)
{
	unique_ptr<Subject> pSubject(new ConcreateSubject);

	unique_ptr<Observer> pObserver1(new ConcreateObserver("zhangsan",-1));
	unique_ptr<Observer> pObserver2(new ConcreateObserver("Lisi",-1));
	unique_ptr<Observer> pObserver3(new ConcreateObserver("Wangwu",-1));
	unique_ptr<Observer> pObserver4(new ConcreateObserver("zhaoliu",-1));

	pSubject->attach(pObserver1.get());
	pSubject->attach(pObserver2.get());
	pSubject->attach(pObserver3.get());
	pSubject->attach(pObserver4.get());

	pSubject->setState(10);
	cout << endl;

	pSubject->detach(pObserver4.get());

	pSubject->setState(20);

	return 0;
}
