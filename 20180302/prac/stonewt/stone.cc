 ///
 /// @file    stone.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-02 21:08:52
 ///

#include "stonewt.h"
#include <iostream>
using std::cout;
using std::endl;

void display(const Stonewt &st,int n)
{
	for(int i = 0;i < n;i++)
	{
		cout << "Wow! ";
		st.show_stn();
	}
}

int test0()
{
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21,8);

	cout << "The celebrity weighed";
	incognito.show_stn();
	cout << "The detective weighed";
	wolfe.show_stn();
	cout << "The President weighed";
	taft.show_stn();
	incognito = 276.8;
	taft = 325;
	cout << "After dinner,the celebrity weight ";
	incognito.show_stn();
	cout << "After dinner,the President weight ";
	taft.show_lbs();
	display(taft,2);
	cout << "The wrestler weight even more \n";
	display(422,2);
	cout << "No stone left unearned\n";
	return 0;
}

int test1()
{
	Stonewt poppins(9,2.8);
	double p_wt = poppins;
	cout << "Convert to double => ";
	cout << "Popins: " << p_wt << "pounds.\n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int (poppins) << " pounds.\n";
	return 0;
}
int main()
{
	test1();
	return 0;
}
