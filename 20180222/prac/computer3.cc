 ///
 /// @file    computer3.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-26 21:50:51
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
	Computer(const char *brand,float price)
	:_brand(new char[strlen(brand)+1]())
	,_price(price)
	{
		cout<<"Computer(const char *)"<<endl;
		strcpy(_brand,brand);
	}

private:
	static char *_brand;
	float _price;

};

int main(void)
{
	char brand[]="Xiaomi";
	Computer com(brand,4999);
	cout<<Computer::_brand<<endl;
}
