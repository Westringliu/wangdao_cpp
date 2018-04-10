 ///
 /// @file    Complex1.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-01 18:06:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal=0,double dimag=0)
	:_dreal(dreal)
	,_dimag(dimag)
	{
		cout<<"Complex(double,double)"<<endl;
	}

	void display()const
	{
		cout<<_dreal;
		if(_dimag>0)
		{
			cout << "+" << _dimag << "i" << endl;
		}else if(_dimag < 0)
		{
			cout << "-" <<_dimag * (-1) << "i" << endl;
		}
	}

	Complex & operator += (const Complex &rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;

		return *this;
	}

	Complex &operator++()
	{
		++_dreal;
		++_dimag;
		return *this;
	}

	Complex operator ++ (int)
	{
		Complex temp(*this);
		++_dreal;
		++_dimag;
		return temp;
	}

	Complex operator+(const Complex &rhs)
	{
		return Complex(_dreal + rhs._dreal,
						_dimag + rhs._dimag);
	}

private:
	double _dreal;
	double _dimag;
};

int main(void)
{
	Complex c1(1,2);
	Complex c2 = c1 + 5;
	c2.display();

//	Complex c3 = 5 + c1;//error
//	c3.display();

	return 0;
}
