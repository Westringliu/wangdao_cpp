 ///
 /// @file    multiDerived.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-30 17:25:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	virtual
	void a() {cout << "A::a()" << endl;}
	virtual
	void b() {cout << "A::b()" << endl;}
	virtual
	void c() {cout << "A::c()" << endl;}
};

class B
{
public:
	virtual
	void a() {cout << "B::a()" << endl;}
	virtual
	void b() {cout << "B::b()" << endl;}
	void c() {cout << "B::c()" << endl;}
	void d() {cout << "B::d()" << endl;}
};

class C
: public A
,public B
{
public:
	virtual
	void a() {cout << "C::a()" << endl;}
	
	void c() {cout << "C::c()" << endl;}
	void d() {cout << "C::d()" << endl;}
};

int main(void)
{
	C c;
	c.A::b();
	c.B::b();
	cout << endl;

	A * pA = &c;
	pA->a();
	pA->b();
	pA->c();

	cout << endl;
	B * pB = &c;
	pB->a();
	pB->b();
	pB->c();
	pB->d();
	cout << endl;

	C * pc = &c;
	pc->a();
	pc->c();
	pc->d();

	cout << "pA = " << pA << endl;
	cout << "pB = " << pB << endl;
	cout << "pC = " << pc << endl;
}
