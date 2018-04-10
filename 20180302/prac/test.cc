 ///
 /// @file    test.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-02 16:16:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
private:
	int _c;
	int _d;
	int _e;
public:
	int _b;
	int _a;
	A();
	A(int a,int b)
	:_b(b)
	,_a(a)
	{
		_c=a+b;
	}
	int mul()
	{
		_a=_c*2;
		_d=10;
		return _d;
	}
	int min();
};

int A::min()
{
	_e=100;
	return _e;
}

int main(void)
{
	A a(5,6);
	cout << a.mul() << endl;	
	cout << a.min() << endl;
	cout << a._a << endl;
	cout << a._b << endl;
}
