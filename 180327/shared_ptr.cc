 ///
 /// @file    shared_ptr.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-27 20:11:05
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Point
:public std::enable_shared_from_this<Point>
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}
#if 0
	Point * add(Point * pt)
	{
		_ix += pt->_ix;
		_iy += pt->_iy;
		return this;
	}
#endif
	
	shared_ptr<Point> add(Point * pt)
	{
		_ix += pt->_ix;
		_iy += pt->_iy;
		return shared_from_this();
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

void test0(void)
{
	Point * pt = new Point(1,2);
	shared_ptr<Point> sp(pt);
	shared_ptr<Point> sp2(pt); 
}

void test1(void)
{
	shared_ptr<Point> sp(new Point(1,2));
	shared_ptr<Point> sp2(new Point(1,2));
	shared_ptr<Point> sp3(sp->add(sp2.get()));//original pointer be managed by to smart pointer,double free

}

int main(void)
{
	//test0();
	test1();
	return 0;
}


