 ///
 /// @file    set.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-07 21:36:42
 ///

#include <cmath>
#include <set>
#include <iostream>
using std::cout;
using std::endl;
using std::set;

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		
	}

	int distance() const
	{
		return _ix * _ix + _iy * _iy;
	}

	friend std::ostream & operator<<(std::ostream & os,const Point &rhs);
private:
	int _ix;
	int _iy;
};

bool operator<(const Point &lhs,const Point &rhs)
{
	return lhs.distance() < rhs.distance();
}

struct Compare
{
	bool operator()(const Point &lhs,const Point &rhs)
	{
		return lhs.distance() < rhs.distance();
	}
};

std::ostream &operator<<(std::ostream &os,const Point &rhs)
{
	os << "(" << rhs._ix
		<< "," << rhs._iy
		<< ")";
	return os;
}

void test0(void)
{
	set<int,std::greater<int>> setInt{1,9,3,5,3,1,6,4,3,2,7,6,8};

	set<int>::const_iterator cit;
	for(cit = setInt.begin();cit != setInt.end();++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
	cit = setInt.begin();
	setInt.erase(cit);
	cout << "after remove the first elem: " << endl;
	for(cit = setInt.begin();cit != setInt.end();++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

void test1(void)
{
	set<Point,Compare> points{
		Point(1,1),Point(2,3),Point(4,5),
		Point(1,1),Point(3,4),Point(5,6)
	};
	set<Point>::const_iterator cit;
	for(cit = points.begin();cit != points.end();++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
