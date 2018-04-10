#include<iostream>
#include<stdlib.h>

using std::cout;
using std::endl;

#define SIZE 100

class Stack
{
public:
	Stack()
	{
		my_s=new int[size];
		if(my_s==NULL)
		{
			cout<<"failed"<<endl;
			return;
		}
	}
	
	~Stack();
	bool empty();
	
	int top();

	void push(int tp);

	void pop();

private:
	int s_top;
	int *my_s;
	int size;
};

Stack::~Stack()
{
	delete[] my_s;
}

	bool Stack::empty()
	{
		if(s_top==-1)
		{
	       return true;
		}
		else
		return false;
	}
	
	int Stack::top()
	{
		if(s_top!=-1)
		{
			cout<<"now the top num is "<<my_s[s_top]<<endl;
			return my_s[s_top];
		}
		else
		{
			cout<<"empty"<<endl;
			return -1;
		}
	}

	void Stack::push(int tp)
	{
		if(s_top+1<size)
		{
			my_s[++s_top]=tp;
			cout<<"i have pushed "<<tp<<endl;
		}
		else
		{
			cout<<"full\n";
			return;
		}
	}

	void Stack::pop()
	{
		if(s_top>=0)
		{
			s_top--;
			cout<<"i have poped a num"<<endl;
		}
		else
		{
			cout<<"empty\n";
			return;
		}
	}

int main(void)
{
	Stack s;
	s.push(10);
	s.push(12);
	s.push(14);
	s.top();
	s.pop();
	s.top();
	return 0;
}
