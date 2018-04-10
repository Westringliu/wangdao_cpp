 ///
 /// @file    test.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-10 14:00:39
 ///

#include <iostream>
#include <cmath>
#include "Point.h"
#include "Rectangle.h"
using std::cout;
using std::endl;

int main(void)
{
	Rectangle rect;
	rect.initRectangle(2,3,20,10);
	rect.move(3,2);
	cout << "the data of rect(x,y,w,h): " << endl;
	cout << rect.getX() << ", "
		 << rect.getY() << ", "
		 << rect.getW() << ", "
		 << rect.getH() << endl;

	return 0;
}
