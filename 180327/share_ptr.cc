 ///
 /// @file    share_ptr.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-27 18:03:39
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

int main(void)
{
	shared_ptr<int> sp(new int(10));
	cout << "*sp = " << *sp << endl;
	cout << "sp.get() = " << sp.get() << endl;

	cout << "sp.use_count = " << sp.use_count() << endl;

	shared_ptr<int> sp2(sp);
	cout << "*sp2 = " << *sp2 << endl;
	cout << "sp2.get() = " << sp2.get() << endl;
	cout << "*sp = " << *sp << endl;
	cout << "sp.get() = " << sp.get() << endl;

	cout << "sp2.use_count = " << sp2.use_count() << endl;

	shared_ptr<int> sp3(new int(11));
	cout << "*sp3 = " << *sp3 << endl;
	cout << "sp3.get() = " << sp3.get() << endl;
	sp3 = sp2;
	cout << "*sp3 = " << *sp3 << endl;
	cout << "sp3.get() = " << sp3.get() << endl;

	cout << "sp3.use_count = " << sp3.use_count() << endl;

	return 0;
}
