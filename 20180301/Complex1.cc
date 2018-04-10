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

	friend std::ostream &operator<<(std::ostream &os,const Complex &);
	friend std::istream &operator>>(std::istream &is,Complex &);

	friend Complex operator+(const Complex &lhs,const Complex &rhs);

private:
	double _dreal;
	double _dimag;
};

Complex operator+(const Complex &lhs,const Complex &rhs)
{
	return Complex(lhs._dreal + rhs._dimag,
					lhs._dimag + rhs._dimag);
}

std::ostream & operator<<(std::ostream &os,const Complex &rhs)
{
	os << rhs._dreal;
	
	if(rhs._dimag > 0)
	{
		os << "+" << rhs._dimag << "i" <<endl;
	}else if(rhs._dimag < 0)
		os << "-" << rhs._dimag * (-1) << "i" << endl;

	return os;

}
	
std::istream & operator>>(std::istream &is,Complex &rhs)
	{
		is >> rhs._dreal;
		while(is.get()!='*');
		is >> rhs._dimag;
		return is;
	}

int main(void)
{
	Complex c1(1,2);
	Complex c2 = c1 + 5;
	c2.display();

	Complex c3 = 5 + c1;
	c3.display();

	int a = 1;
	cout << "a = " << a << endl;

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;

	cout << ">pls input a Complex number:" << endl;
	std::cin >> c3;
	cout << "c3 = " << c3 << endl;

	return 0;
}
