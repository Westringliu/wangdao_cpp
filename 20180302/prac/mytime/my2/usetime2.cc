 //
 /// @file    usetime0.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-02 17:07:05
 ///

#include "mytime2.h"
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;

void test1()
{
	Time planning;
	Time weeding(2,40);
	Time waxing(5,55);
	Time total;
	Time diff;
	Time adjusted;

	planning.Reset(9,10);
	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "weeding time = ";
	weeding.Show();
	cout << endl;
	
	cout << "waxing time = ";
	waxing.Show();
	cout << endl;

	total = weeding + waxing;
	cout << "weeding + waxing = ";
	total.Show();
	cout << endl;

	total = weeding + waxing + planning;
	cout << "weeding + waxing + planning = ";
	total.Show();
	cout << endl;

	weeding.Reset(0,0);
	total = weeding + waxing;
	cout << "after reset weeding,weeding + waxing = ";
	total.Show();
	cout << endl;
	cout << "now total = ";
	total.Show();
	cout << endl;


	diff = weeding - waxing;
	cout << "weeding - waxing = ";
	diff.Show();
	cout << endl;

	adjusted = 1.5 * total;
	cout << "total * 1.5 = ";
	adjusted.Show();
	cout << endl;	
}

void test2()
{
	Time trip(3,4);
	cout << trip;
	cout << endl;
	std::ofstream fout;
	fout.open("save.txt");
	fout << trip;
}

int main()
{
	//test1();
	test2();
	return 0;
}
