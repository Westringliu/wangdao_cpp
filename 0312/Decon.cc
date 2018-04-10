 ///
 /// @file    Decon.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-12 09:57:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Myclass
{
public:
	int num;
public:
	Myclass()
	{
		cout << "Myclass()" << endl;
	}
	Myclass(int data)
	{
		cout << "Mycalss(int)" << endl;
		num = data;
	}
	~Myclass()
	{
		cout << "~Mycalss()" << endl;
	}
};

void test0()
{
	Myclass my1(10);
	cout << my1.num << endl;
	Myclass my2 = 101;
	cout << my2.num << endl;
	Myclass *my3(new Myclass(102));
	cout << (*my3).num << endl;
	delete my3;
	Myclass *my4(new Myclass(105));
	cout << my4->num << endl;
	delete my4;
}

int main(void)
{
	test0();

	int num = 4;
	num = 4;

	return 0;
}


