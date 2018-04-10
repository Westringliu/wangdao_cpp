 ///
 /// @file    Point.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-11 14:19:08
 ///

#include <string>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	Point(const Point &rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	~Point()
	{
		cout << "~Point" << endl;
	}
	void print()
	{
		cout << "(" << _ix
			<< "," << _iy
			<< ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

void func1(Point pt)
{
	cout << "func1(Point)" << endl;
	pt.print();
}

Point func2()
{
	cout << "func2()" << endl;
	Point pt(5,6);
	pt.print();
	return pt;
}

int test(void)
{
	Point pt1(1,2);
	pt1.print();

	Point pt2 = pt1;
	pt2.print();

	Point pt3 = func2();

	return 0;
}

void test2(void)
{
	//const int &ref = 10;

	Point(10,11).print();

	const Point &ref = Point(12,13);

	cout << "-----" << endl;
}

int main(void)
{
	cout << "----test----" << endl;
	test();
	cout << "----test2----" << endl;
	test2();
	return 0;
}

