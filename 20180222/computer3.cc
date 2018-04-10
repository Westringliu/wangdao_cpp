///
/// @file    computer.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-22 13:13:07
///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public:
	Computer(const char *brand,float price)
	: _brand(new char[strlen(brand)+1]())//深拷贝
	, _price(price)
	{
		cout<<"Computer(const char *,float)"<<endl;
		strcpy(_brand,brand);
	}
	~Computer()
	{
		cout<<"~Computer()"<<endl;
		delete [] _brand;
		_brand=NULL;
	}

		void print();
		void setBrand(const char *brand);
		void setPrice(float price);
	private:
		char *_brand;
		float _price;
};
void print()
{
	cout<<"print()"<<endl;
}
void Computer::print()
{
	cout<<"品牌:"<<_brand<<endl;
	cout<<"价格:"<<_price<<endl;
}
void Computer::setBrand(const char *brand)
{
	strcpy(_brand,brand);
}
void Computer::setPrice(float price)
{
	_price=price;
}
int main(void)
{
	char brand[]="Xiaomi";

	Computer com(brand,4999);
	com.print();
	com.~Computer();
	return 0;
}
