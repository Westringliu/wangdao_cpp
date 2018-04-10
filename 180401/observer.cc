 ///
 /// @file    observer.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-01 17:45:28
 ///

#include "observer.h"
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

void Subject::attach(Observer * ob)
{
	auto it = std::find(_observerList.begin(),_observerList.end(),ob);
	if(it == _observerList.end())
	{
		_observerList.push_front(ob);
	}
}

void Subject::detach(Observer * ob)
{
	auto it = std::find(_observerList.begin(),_observerList.end(),ob);
	if(it != _observerList.end())
	{
		_observerList.erase(it);
	}
}

void Subject::notify()
{
	for(auto & observer : _observerList)
	{
		observer->update(this);
	}
}

State ConcreateSubject::getState()
{
	return _state;
}

void ConcreateSubject::setState(State state)
{
	_state = state;
	cout << "> Subject modify state " << _state << endl;
	notify();
}

void ConcreateObserver::update(Subject * subject)
{
	State subjectState = subject->getState();
	if(_state != subjectState)
	{
		_state = subjectState;
		cout << " update state: " << endl;
	}
}

