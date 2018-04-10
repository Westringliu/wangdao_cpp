 ///
 /// @file    templateStack.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-03 16:34:06
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T,int kSize = 10>
class Stack
{
public:
	Stack();
	~Stack();

	bool empty() const;
	bool full() const;

	void push(const T &data);
	void pop();
	T top();

private:
	int _top;
	T * _array;
};

template <typename T,int kSize>
Stack<T,kSize>::Stack()
:_array(new T[kSize]())
,_top(-1)
{
	cout << "~Stack()" << endl;
}

template <typename T,int kSize>
Stack<T,kSize>::~Stack()
{
	cout << "~Stack" << endl;
	delete [] _array;
}

template <typename T,int kSize>
bool Stack<T,kSize>::empty() const
{
	return _top == -1;
}

template <typename T,int kSize>
bool Stack<T,kSize>::full() const
{
	return _top == kSize - 1;
}

template <typename T,int kSize>
void Stack<T,kSize>::push(const T &data)
{
	if(!full())
	{
		_array[++_top] = data;
	}
	else
		cout << "stack is full" << endl;
}

template <typename T,int kSize>
void Stack<T,kSize>::pop()
{
	if(!empty())
	{
		--_top;
	}
	else
		cout << "stack is empty" << endl;
}

template <typename T ,int kSize>
T Stack<T,kSize>::top()
{
	return _array[_top];
}

void test0(void)
{
	Stack<int,10> stack;
	cout << "is now Stack empty? " << stack.empty() << endl;
	stack.push(1);
	cout << "is now Stack empty? " << stack.empty() << endl;

	for(int idx = 2;idx != 12;++idx)
	{
		stack.push(idx);
	}
	cout << "is now Stack full? " << stack.full() << endl;

	while(!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << "is now Stack empty? " << stack.empty() << endl;
}

void test1(void)
{
	Stack<string> stack;
	cout << "is now Stack empty? " << stack.empty() << endl;
	string s1(6,'a');
	stack.push(s1);
	cout << "is now Stack empty? " << stack.empty() << endl;

	for(int idx = 2;idx != 12;++idx)
	{
		char ch = 'a' + idx;
		stack.push(string(6,ch));
	}
	cout << "is now Stack full? " << stack.full() << endl;

	while(!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	
	cout << "is now Stack empty? " << stack.empty() << endl;
}

int main(void)
{
	test0();
	return 0;
}
