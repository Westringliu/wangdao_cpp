 ///
 /// @file    trans.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-10 15:17:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class B{
public:
	B();
	B(int i);
	~B();
	void print() const;
private:
	int b;
};

B::B(){
	b = 0;
	cout << "B default constructor called." << endl;
}

B::B(int i){
	b = i;
	cout << "B constructor called." << endl;
}

B::~B(){
	cout << "B destructor called." << endl;
}

void B::print() const{
	cout << b << endl;
}

class C:public B{
public:
	C();//只要派生类有默认构造构造函数，基类就必须有默认构造函数
	C(int i,int j);
	~C();
private:
	int c;
};

C::C(){
	c = 0;
	cout << "C default constructor called." << endl;
}

C::C(int i,int j):B(i){
	c = j;
	cout << "C constructor called." << endl;
}

C::~C(){
	cout << "C destructor called." << endl;
}

int main(void){
	C c1;
	return 0;

}
