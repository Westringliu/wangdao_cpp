 ///
 /// @file    Point2.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-28 14:52:23
 ///

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;

class Line
{
	friend class Point;
public:
	Line(int iz=0)
	:_iz(iz)
	{
		cout<<"Line(int)"<<endl;
	}

	float distance(const Point &lhs,const Point &rhs);

	void setPoint(Point &rhs,int ix,int iy);

private:
	int _iz;
};

class Point
{
	friend class Line;
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
			<<","<<_iy
			<<")";
	}

	void setZ(Line &rhs,int iz)
	{
		rhs._iz=iz;
	}

private:
	int _ix;
	int _iy;
};

float Line::distance(const Point &lhs,const Point &rhs)
{
	return sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)+
				(lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
}

void Line::setPoint(Point &rhs,int ix,int iy)
{
	rhs._ix=ix;
	rhs._iy=iy;
}

int main(void)
{
	Point pt1(1,2);
	Point pt2(3,4);
	pt1.print();
	cout<<"--->";
	pt2.print();

	Line line;
	cout<<"distance"<<line.distance(pt1,pt2)<<endl;

	line.setPoint(pt1,10,11);
	cout<<"after alter,pt1= ";
	pt1.print();
	cout<<endl;

	return 0;

}

