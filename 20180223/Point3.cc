 ///
 /// @file    Point.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-23 13:35:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
	}
#if 1
	void print(/*const Point *const this*/)const
	{
		cout<<"Point::print()"<<endl;
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
#endif
	
#if 0
	void print()
	{
		cout<<"Point::print()"<<endl;
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
#endif

private:
	int _ix;
	int _iy;
};




int main(void)
{
	const Point pt(1,2);

	Point pt2(3,4);
	pt2.print();

	return 0;
}
