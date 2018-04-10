 ///
 /// @file    multi_inherit.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-10 14:41:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
public:
	void setA(int);
	void showA() const;
private:
	int a;
};

class B{
public:
	void setB(int);
	void showB() const;
private:
	int b;
};

class C:public A,private B{
public:
	void setC(int,int,int);
	void showC() const;
private:
	int c;
};

void A::setA(int x){
	a = x;
}
#if 0
void A::showA(){
	cout << "showA()" << endl;
}

void B::showB(){
	cout << "showB()" << endl;
}
#endif
void B::setB(int x){
	b = x;
}

void C::setC(int x,int y,int z){
	setA(x);
	setB(y);
	c = z;
}

int main(void){
	C obj;
	obj.setA(5);
	obj.showA();
	//obj.setB(6);
	//obj.showB();
	obj.setC(6,7,9);
	obj.showC();

	return 0;
}

