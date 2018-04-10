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
	//: _brand(brand)
	, _price(price)
	{
		cout << "Computer(const char *,float)" << endl;
		strcpy(_brand,brand);
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

int main(void){
	char brand[] = "XiaoMi";
	Computer com(brand,4999);
	com.print();

	Computer *p = new Computer("Mac",10000);
	p->print();
	delete p;

	print();
	return 0;
}
