/// @file    Computer2.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-02-22 11:21:57
///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, float price)
	: _brand(new char[strlen(brand) + 1]()) //深拷贝
	, _price(price)
	{
		cout << "Computer(const char *,float)" << endl;
		strcpy(_brand, brand);
	}
#if 0
	//系统赋值运算符函数原型
	Computer(const Computer & rhs)
	: _brand(rhs._brand)
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
	}
#endif
	//系统的赋值运算符函数为浅拷贝，不能满足需求。手动改为深拷贝	
	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
		strcpy(_brand, rhs._brand);
	}
	
	Computer & operator=(const Computer &rhs)
	{
		cout<<"Computer & operator=(const Computer & rhs)"<<endl;
		if(this!=&rhs)
		{
			delete [] _brand;

			this->_brand=new char[strlen(rhs._brand)+1]();
			strcpy(_brand,rhs._brand);

			_price=rhs._price;
		}
		return *this;
	}

	~Computer()
	{
		cout << "~Computer()" << endl;
		delete [] _brand;
	}

		void print();
	private:
		char * _brand;
		float _price;
};


void print()
{
	cout << "print()" << endl;
}

//在类之外实现成员函数
void Computer::print()
{
	cout << "品牌:" << _brand << endl;
	cout << "价格:" << _price << endl;
}


int test0(void)
{
	int a = 3;
	int b = a;

	char brand[] = "Xiaomi";
	Computer com(brand, 4999);//栈对象
	com.print();

	Computer com2 = com;
	com2.print();

	return 0;
}

void test1(void)
{
	int a = 3;
	int b = a;
	a=b;

	Computer pc1("Xiaomi",4999);
	pc1.print();
	Computer pc2("Mac",10000);
	pc2.print();
	pc2=pc1;
	pc2.print();

	pc2=pc2;
}

int main()
{
	test1();
	return 0;
}
