 ///
 /// @file    observer.h
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-01 17:46:34
 ///

#ifndef __WD_OBSERVER_H__
#define __WD_OBSERVER_H__
#include <list>
#include <string>
#include <iostream>
using std::list;
using std::string;
using std::cout;
using std::endl;

typedef int State;

class Observer;

class Subject
{
public:
	void attach(Observer *);
	void detach(Observer *);
	void notify();

	virtual State getState() = 0;
	virtual void setState(State) = 0;

	virtual ~Subject(){}

protected:
	list<Observer *> _observerList;

	State _state;
};

class ConcreateSubject
:public Subject
{
public:
	virtual State getState();
	virtual void setState(State state);
	virtual ~ConcreateSubject(){	cout << "~ConcreateSubject()" << endl;	}
};

class Observer
{
public:
	virtual void update(Subject *) = 0;

	virtual ~Observer(){}
};

class ConcreateObserver
:public Observer
{
public:
	ConcreateObserver(const string & name,State state = 0)
	:_name(name)
	,_state(state)
	{}

	void update(Subject *);

	virtual ~ConcreateObserver(){cout << "~ConcreateSubject()" << endl;}

private:
	string _name;
	State _state;
};

#endif


