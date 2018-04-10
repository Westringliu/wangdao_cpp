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
	{
		cout << "Point(int,int)" << endl;
		_ix = ix;
		_iy = iy;
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

int main(void)
{
	Point pt;
	pt.print();
	
	Point pt2(1,2);
	pt2.print();

	Point pt3(3);
	pt3.print();

	return 0;
}

