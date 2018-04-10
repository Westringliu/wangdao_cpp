 ///
 /// @file    usetime0.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-02 17:07:05
 ///

#include "mytime0.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Time planning;
	Time coding(2,40);
	Time fixing(5,55);
	Time total;

	planning.Reset(9,10);
	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;
	
	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.Show();
	cout << endl;

	coding.Reset(0,0);
	total = coding.Sum(fixing);
	cout << "after reset coding,coding.Sum(fixing) = ";
	total.Show();
	cout << endl;

	return 0;
}
