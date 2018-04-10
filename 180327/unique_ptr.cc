 ///
 /// @file    unique_ptr.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-27 17:05:58
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

unique_ptr<int> getValue()
{
	unique_ptr<int> up(new int(66));
	return up;
}

int main(void)
{
	unique_ptr<int> up(new int(10));

	cout << "*up = " << *up << endl;
	cout << "up.get() = " << up.get() << endl;

	unique_ptr<int> up3(new int(20));

	up = getValue();
	cout << "*up = " << * up << endl;
	cout << "up.get() = " << up.get() << endl;

	unique_ptr<int> up4 = getValue();
	cout << "*up4 = " << * up4 << endl;
	cout << "up4.get() = " << up4.get() << endl;

	vector<unique_ptr<int>> vec;
	//vec.push_back(std::move(up));
	vec.push_back(up);

	cout << "*up = " << * up << endl;
	cout << "up.get() = " << up.get() << endl;
	return 0;
}
