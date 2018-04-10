 ///
 /// @file    Queue.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-12 19:39:11
 ///

#include <string>
#include <iostream>
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(int size)
	:_front(0)
	,_rear(0)
	,_size(size)
	,_parr(new int[_size]())
	{}
	~Queue()
	{
		delete []_parr;
	}

	bool empty() const
	{
		return _rear == _front;
	}

	bool full() const
	{
		return (_rear + 1) % _size == _front; 
	}

	int front()
	{
		return _parr[_front];
	}

	int back()
	{
		return _parr[(_rear - 1 + _size) % _size];
	}

	void push(int num)
	{
		if(!full())
		{
			_parr[_rear] = num;
			++_rear;
			_rear %= _size;
		}
		else
			cout << "Queue is now full!" << endl;
	}

	void pop()
	{
		if(!empty())
		{
			++_front;
			_front %= _size; 
		}
		else 
			cout << "Queue is now empty!" << endl;
	}
private:
	int _front;
	int _rear;
	int _size;
	int *_parr;
};

int main(void)
{
	Queue queue(10);
	cout << "is now queue empty?" << queue.empty() << endl;
	queue.push(0);
	cout << "is now queue empty?" << queue.empty() << endl;
	
	for(int idx = 2;idx < 12; ++idx)
	{
		queue.push(idx);
	}

	cout << "is now queue full?" << queue.full() << endl;

	queue.pop();
	queue.push(10);
	cout << "queue.back() is " << queue.back() << endl; 

	while(!queue.empty())
	{
		queue.pop();
		cout << queue.front() << " ";
	}
	cout << endl;

	return 0;

}
