 ///
 /// @file    Point.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-28 14:41:20
 ///

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	friend float distance(const Point &lhs,const Point &rhs);
public:
	Point(int ix=0,int iy=0)
	:_ix(ix)
	,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}

	void print() const
	{
		cout<<"("<<_ix
			<<"'"<<_iy
			<<")";
	}

private:
	int _ix;
	int _iy;
};

float distance(const Point &lhs,const Point &rhs)
{
	return sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)+
				(lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
}

int main(void)
{
	Point pt1(1,2);
	Point pt2(3,4);
	pt1.print();
	cout<<"--->";
	pt2.print();
	cout<<" distance:"<<distance(pt1,pt2)<<endl;
}
