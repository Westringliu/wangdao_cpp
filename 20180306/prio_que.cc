 ///
 /// @file    prio_que.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-07 20:48:12
 ///
 
#include <math.h>
#include <queue>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

void test0(void)
{
	int array[] = {3,5,6,1,4,9,7,8,0,2};
	priority_queue<int> pque;

	for(int idx = 0;idx != 10;++idx)
	{
		pque.push(array[idx]);
		cout << "now the highest priority elem is: " << pque.top() << endl;
	}

	while(!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
	}
}

void test1(void)
{
	int array[] = {3,5,6,1,4,9,7,8,0,2};
	priority_queue<int,vector<int>,std::greater<int>> pque;
	for(int idx = 0;idx != 10;++idx)
	{
		pque.push(array[idx]);
		cout << "now the highest priority elem is: " << pque.top() << endl;
	}

	while(!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
	}
}

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
		return _ix*_ix+_iy*_iy;
	}

	friend std::ostream & operator<<(std::ostream &os,const Point & rhs);
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
		return lhs.distance() > rhs.distance();
	}
};

std::ostream & operator<<(std::ostream &os,const Point &rhs)
{
	os << "(" << rhs._ix
		<< "," << rhs._iy
		<< ")";
	return os;
}

void test2(void)
{
	Point array[] = {
		Point(1,2),
		Point(3,4),
		Point(5,6),
		Point(7,8)
	};
	priority_queue<Point,vector<Point>,Compare> pque;

	for(int idx = 0;idx != 4;++idx)
	{
		pque.push(array[idx]);
		cout << "now the highest priority elem is: " << pque.top() << endl;
	}

	while(!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
	}
}

int main(void)
{
//	test0();
//	test1();
	test2();
	return 0;
}
