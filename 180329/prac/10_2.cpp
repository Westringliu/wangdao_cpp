 ///
 /// @file    10_2.cpp
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-29 09:34:43
 ///
 
#include <iostream>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::cin;
using std::iterator;
using std::istream_iterator;
using std::ostream_iterator;

double square(double x)
{
	return x * x;
}

int main(void)
{
	std::transform(istream_iterator<double>(cin),istream_iterator<double>(),ostream_iterator<double>(cout,"\t"),square);

	cout << endl;
	return 0;
}
