 ///
 /// @file    computer.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-11 10:09:14
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer{
public:
	Computer(const char *brand,float price)
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		cout << "Computer(const char *,float)" << endl;
		strcpy(_brand,brand);
	}

	Computer(const Computer &rhs)
	:_brand(new char[strlen(rhs._brand) + 1])
	,_price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
		strcpy(_brand,rhs._brand);
	}

	~Computer(){
		cout << "~Computer" << endl;
		delete [] _brand;
		_brand = NULL;
	}

	void print() const;

	void setBrand(const char *brand);

	void setPrice(float price);

private:
	char * _brand;
	float _price;
};
	
void print(){
	cout << "print()" << endl;
}

void Computer::print() const{
		cout << "_brand: " << _brand << endl;
		cout << "_price: " << _price << endl;
	}

	void Computer::setBrand(const char *brand){
		strcpy(_brand,brand);
	}
	void Computer::setPrice(const float price){
		_price = price;
	}

void test0(void){
	char brand[] = "XiaoMi";
	Computer com(brand,4999);
	com.print();

	Computer *p = new Computer("Mac",10000);
	p->print();
	delete p;

	print();
}

void test1(void)
{
	int a = 3;
	int b = a;

	char brand[] = "XiaoMi";
	Computer com(brand,4999);
	com.print();

	Computer com2 = com;
	com2.print();
}

int main(void)
{
	test1();
	return 0;
}
