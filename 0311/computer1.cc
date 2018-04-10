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
	void setBrand(const char *brand);
	void setPrice(const float price);
	void print() const;
private:
	char _brand[20];
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
	Computer com;
	com.setBrand("XiaoMi");
	com.setPrice(2999);
	com.print();

	print();
	return 0;
}
