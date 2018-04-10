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
	Point()
	{
	
	}

	Point(int ix,int iy=0)
	:_ix(ix)
	,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
		_ix=ix;//并不是真正的初始化
		_iy=iy;
	}

	void print()
{
	cout<<"("<<_ix
		<<","<<_iy
		<<")"<<endl;
}
private:
int _ix;
int _iy;
};

int main()
{
	Point pt;
	pt.print();

	Point pt2(1,2);
	pt2.print();

	return 0;
}



