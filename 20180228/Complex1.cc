 ///
 /// @file    Complex1.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-28 15:22:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal,double dimag)
	:_dreal(dreal)
	,_dimag(dimag)
	{
		cout<<"Complex(double,double)"<<endl;
	}

	void display() const
	{
		cout<<_dreal;
		if(_dimag>0)
		{
			cout<<"+"<<_dimag<<"i"<<endl;
		}else if(_dimag<0)
			cout<<"-"<<_dimag*(-1)<<"i"<<endl;
	}

	Complex operator+(const Complex &rhs)
	{
		return Complex(_dreal+rhs._dreal,
						_dimag+rhs._dimag);
	}

private:
	double _dreal;
	double _dimag;
};

int main(void)
{
	Complex c1(1,2);
	Complex c2(2,-1);

	Complex c3=c1+c2;
	cout<<"c3=";
	c3.display();

	return 0;
}
