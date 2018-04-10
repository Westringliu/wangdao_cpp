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
		_totalPrice+=_price;
	}

	void print()
	{
		cout<<"品牌:"<<_brand<<endl;
		cout<<"价格:"<<_price<<endl;
	}

	void printTotalPrice()
	{
		cout<<"总价:"<<_totalPrice<<endl;
	}

	~Computer()
	{
		cout << "~Computer()" << endl;
		_totalPrice-=_price;
	}

	private:
		char * _brand;
		float _price;
		static double _totalPrice;
};

	double Computer::_totalPrice=0;

int main(void)
{
	Computer pc1("Xiaomi",5000);
	pc1.printTotalPrice();

	Computer pc2("Thinkpad",6000);
	pc2.printTotalPrice();
	
	Computer pc3("Mac",10000);
	pc3.printTotalPrice();
	pc3.~Computer();
	pc3.printTotalPrice();
	cout<<"sizeof(Computer)="<<sizeof(Computer)<<endl;
	return 0;

}
