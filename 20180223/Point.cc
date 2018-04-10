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
private:
	const int _ix;
	const int _iy;

};

int main(void)
{
	Point pt(1,2);

	return 0;
}
