 ///
 /// @file    istream_iterator.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-06 23:18:41
 ///

#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::copy;

void test0(void)
{
	vector<int> numbers;
	std::istream_iterator<int> isi(cin);

	cout << ">had cin the first elem: " <<endl;

	copy(isi,std::istream_iterator<int>(),std::back_inserter(numbers));

	std::ostream_iterator<int> osi(cout," - ");
	copy(numbers.begin(),numbers.end(),osi);
	cout << endl;

#if 0
	for(auto &elem : numbers)
	{
		cout << elem << " ";
	}
	cout << endl;
#endif
}

int main(void)
{
	test0();
	return 0;
}
