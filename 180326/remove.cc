 ///
 /// @file    remove.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-26 16:13:41
 ///

#include <unistd.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

void test1(void)
{
	vector<int> numbers;

	numbers.push_back(1);

	bool flag = true;
	for(auto it = numbers.begin();it != numbers.end(); ++it)
	{
		cout << *it << endl;
		cout << "numbers's size = " << numbers.size() << endl;
		cout << "numbers's capacity = " << numbers.capacity() << endl;
		sleep(1);

		if(flag)
		{
			numbers.push_back(2);//底层发生了动态扩容，it失效
			flag = false;
			it = numbers.begin();//do not push_back or erase in for,if must remember do this
		}
	}
}

int main(void)
{
	test1();
	return 0;
}

