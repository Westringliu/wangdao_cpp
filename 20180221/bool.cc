//
/// @file    bool.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-02-21 16:10:35
///

#include <iostream>
using std::cout;
using std::endl;


int test0(void)
{
	int a = 0;
	if(a)
	{
		cout << "true" << endl;
	}else
	{
		cout << "false" << endl;
	}

	return 0;
}


int main(void)
{
	int a = 0;
	bool b = true;
	bool b1 = 0;
	bool b2 = 1;
	bool b3 = 100;
	bool b4 = -1;
	bool b5 = true;//可以直接使用
	bool b6 = false;//

	int * p = NULL;
	//*p = 10;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	//cout << "*p = " << *p << endl;

	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;
	cout << "b3 = " << b3 << endl;
	cout << "b4 = " << b4 << endl;
	cout << "b5 = " << b5 << endl;
	cout << "b6 = " << b6 << endl;
	cout << "sizeof(bool) = " << sizeof(bool) << endl;

	return 0;
}

