 ///
 /// @file    Stack.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-12 11:56:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack(int size);
	~Stack();

	bool empty() const;
	bool full() const;

	void push(int num);
	void pop();
	int top();

private:
	int _top;
	int _size;
	int *_parr;
};

Stack::Stack(int size)
:_top(-1)
,_size(size)
,_parr(new int[_size]())
{
	cout << "Stack(int)" << endl;
}

Stack::~Stack()
{
	delete [] _parr;
	cout << "~Stack()" << endl;
}

bool Stack::empty() const
{
	return _top == -1;
}

bool Stack::full() const
{
	return _top == _size - 1;
}

void Stack::push(int num)
{
	if(!full())
	{
		_parr[++_top] = num;
	}
	else
		cout << "Stack now full!" << endl;
}

void Stack::pop()
{
	if(!empty())
	{
		--_top;
	}
	else
		cout << "Stack now empty!" << endl;
}

int Stack::top()
{
	return _parr[_top];
}

int main(void)
{
	Stack stack(10);
	cout << "is now Stack empty?" << stack.empty() << endl;
	stack.push(1);
	cout << "is now Stack empty?" << stack.empty() << endl;

	for(int idx = 2;idx < 12; ++idx)
	{
		stack.push(idx);
	}
	cout << "is now Stack full?" << stack.full() << endl;

	while(!stack.empty())
	{
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	cout << "is now Stack empty?" << stack.empty() << endl;

	return 0;
}
