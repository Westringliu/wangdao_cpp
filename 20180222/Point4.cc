///
/// @file    Point.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-22 20:13:46
///

#include <iostream>
using std::cout;
using std::endl;

class Point
{

public:
	explicit
	Point(int ix=0,int iy=0)
	: _ix(ix)
	, _iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}

	~Point()
	{
		cout<<"~Point()"<<endl;
	}

	void print()
	{
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
#if 0		
		Point(int ix=0,int iy=0)
		:_ix(ix)
		,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}
#endif

	private:
		int _ix;
		int _iy;
};

int main()
{
	Point pt;
	pt.print();

//	Point pt2=10;
//	pt2.print();
	return 0;
}



