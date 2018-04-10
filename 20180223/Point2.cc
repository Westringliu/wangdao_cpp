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
	Point(int ix,int iy,int & ref)
	:_ix(ix)
	,_iy(iy)
	,_ref(ref)
	{
	
	}
private:
	int _ix;
	int _iy;
	int & _ref;

};

int main(void)
{
	int a=10;
	Point pt(1,2,a);

	return 0;
}
