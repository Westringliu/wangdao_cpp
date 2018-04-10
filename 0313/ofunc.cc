 ///
 /// @file    ofunc.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-13 16:44:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Linear
{
private:
	double slope;
	double y0;
public:
	Linear(double s1_ = 1,double y_ = 0)
	:slope(s1_),y0(y_){}
	double operator()(double x){return y0 + slope * x;}
};

void test(void)
{
	Linear f1;
	Linear f2(2.5,10.0);
	double y1 = f1(12.5);
	double y2 = f2(0.4);

	cout << "f1(12.5) = " << y1 << endl;
	cout << "f2(0.4) = " << y2 << endl;
}

int main(void)
{
	test();

	return 0;
}
