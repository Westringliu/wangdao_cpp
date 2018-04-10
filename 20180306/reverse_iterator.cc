 ///
 /// @file    reverse_iterator.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-07 21:33:00
 ///

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void test0(void)
{
	vector<int> numbers{1,2,3,4,5,6};

	vector<int>::const_reverse_iterator cit;

	for(cit = numbers.rbegin();cit != numbers.rend();++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

int main(void)
{
	test0();
	return 0;
}
