 ///
 /// @file    Base.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-10 14:22:47
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base1{
public:
	void display() const{
		cout << "Base1::display()" << endl;
	}
};

class Base2:public Base1{
public:
	void display() const{
		cout << "Base2::display()" << endl;//继承而来的同名函数不要再写一遍
	}
};

class Derived: public Base2{
public:
	void display() const{
		cout << "Derived::display()" << endl;
	}
};

void fun(Base1 *ptr){
	ptr->display();
}

int main(void){
	Base1 bs1;
	Base2 bs2;
	Derived der;

	fun(&bs1);
	fun(&bs2);
	fun(&der);

	return 0;
}
