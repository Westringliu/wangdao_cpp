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
	void print()
	{
		cout<<"品牌:"<<_brand<<endl;
		cout<<"价格:"<<_price<<endl;
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
	int a;

	Computer com;
	com.setBrand("Xiaomi");
	com.setPrice(4999);
	com.print();
	return 0;
}
