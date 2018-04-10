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
	void print(){
		cout << "_brand: " << _brand << endl;
		cout << "_price: " << _price << endl;
	}

	void setBrand(const char *brand){
		strcpy(_brand,brand);
	}
	void setPrice(const float price){
		_price = price;
	}

private:
	char _brand[20];
	float _price;
};

int main(void){
	Computer com;
	com.setBrand("XiaoMi");
	com.setPrice(2999);
	com.print();
	return 0;
}
