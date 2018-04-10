 ///
 /// @file    explict.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-12 10:10:47
 ///

#include <array>
#include <iostream>
using std::cout;
using std::endl;
using std::array;

class Classobj
{
public:
	int num;
public:
	explicit Classobj(int data)
	{
		this->num = data;
		cout << "Classobj(int)  " << num << endl;
	}
	~Classobj()
	{
		cout << "~Classobj() "  << endl;
	}
};

void test0(void)
{
	Classobj obj(0);
	Classobj obj1[3] = {Classobj(0),Classobj(1),Classobj(2)};
	Classobj(*pobjA)[3] = &obj1;
	Classobj *pobj(new Classobj(0));

	Classobj *pobjB[3];
	pobjB[0] = new Classobj(0);
	pobjB[1] = new Classobj(1);
	pobjB[2] = new Classobj(2);
}

void test1(void)
{
	//Classobj num = 5;
	Classobj data(6);

	Classobj obj(0);

	Classobj *p = new Classobj(7);
	array <Classobj,2> myarray= {obj,*p};
}

int main(void)
{
	test1();
	return 0;
}
