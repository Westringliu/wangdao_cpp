 ///
 /// @file    RAII.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-27 16:48:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{}

	void setX(int ix)
	{	_ix = ix;	}

	void setY(int iy)
	{	_iy = iy;	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os,const Point & rhs)
{
	os << "(" << rhs._ix
		<<"," << rhs._iy
		<<")" << endl;
	return os;
}

template <typename T>
class RAII
{
public:
	RAII(T * p)
	:_p(p)
	{}

	T * get()
	{
		return _p;
	}

	T * operator->()
	{
		return _p;
	}

	T & operator*()
	{
		return *_p;
	}

	~RAII()
	{
		cout << "~RAII()" << endl;
	}
private:
	T * _p;
};

int main(void)
{
	RAII<Point> pPoint(new Point(1,2));

	pPoint->setX(10);

	cout << *pPoint << endl;
	return 0;
}
