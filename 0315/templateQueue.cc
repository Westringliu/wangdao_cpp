 ///
 /// @file    templateQueue.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-15 16:46:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T,int kSize = 10>
class Queue
{
public:
	Queue();
	~Queue();

	bool full() const;
	bool empty() const;

	void push(const T &data);
	void pop();
	T front();
	T back();

private:
	int _front;
	int _rear;
	T *_array;
};

template <typename T,int kSize>
Queue<T,kSize>::Queue()
:_front(0)
,_rear(0)
,_array(new T[kSize]())
{

}

template <typename T,int kSize>
Queue<T,kSize>::~Queue()
{
	delete []_array;
}

template <typename T,int kSize>
bool Queue<T,kSize>::empty() const
{
	return _front == _rear;
}

template <typename T,int kSize>
bool Queue<T,kSize>::full() const
{
	return _front == (_rear + 1) % kSize;
}

template <typename T,int kSize>
void Queue<T,kSize>::push(const T &data)
{
	if(!full())
	{
		_array[_rear++] = data;
		_rear %= kSize;
	}
	else cout << "Queue is now full" << endl;
}

template <typename T,int kSize>
void Queue<T,kSize>::pop()
{
	if(!empty())
	{
		++_front;
		_front %= kSize;
	}
	else
		cout << "Queue is now empty" << endl;
}

template <typename T,int kSize>
T Queue<T,kSize>::front()
{
	return _array[_front];
}

template <typename T,int kSize>
T Queue<T,kSize>::back()
{
	return _array[(_rear - 1 + kSize) % kSize];
}

int main(void)
{
	Queue<int> queue;
	cout << "is now queue empty?" << queue.empty() << endl;
	queue.push(1);
	cout << "is now queue empty?" << queue.empty() << endl;

	for(size_t idx = 2;idx != 12;++idx)
	{
		queue.push(idx);
	}
	cout << "is now queue full?" << queue.full() << endl;
	
	while(!queue.empty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}

	return 0;
}
