///
/// @file    computer.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-26 20:38:05
///

#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Computer
{
	public:
		void print()
		{
			cout<<"brand"<<_brand<<endl;
			cout<<"price"<<_price<<endl;
		}
		void setBrand(const char *brand)
		{
			strcpy(_brand,brand);
		}

		void setPrice(float price)
		{
			_price=price;
		}

	private:
		char _brand[20];
		float _price;
};


int main(void)
{
	Computer com;
	com.setBrand("Xiaomi");
	com.setPrice(4999);
	com.print();

	return 0;
}

