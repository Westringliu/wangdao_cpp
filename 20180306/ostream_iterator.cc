 ///
 /// @file    ostream_iterator.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-07 20:44:10
 ///

#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::copy;

void test0(void)
{
	vector<int> numbers{1,2,3,4,5,6};

	std::ostream_iterator<int> osi(cout," - ");

	copy(numbers.begin(),numbers.end(),osi);
	cout << endl;
}

int main(void)
{
	test0();
	return 0;
}
