///
/// @file    insert_iterator.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-03-06 16:41:39
///

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;
using std::vector;
using std::list;
using std::copy;

template <typename Container>
void displayContainer(const Container & c)
{
	typename Container::const_iterator cit;
	for(cit = c.begin(); cit != c.end(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}


void test0(void)
{
	vector<int> numbers{1, 2, 3};
	list<int> listInt;

	copy(numbers.begin(), numbers.end(), 
			front_insert_iterator<list<int> >(listInt));//调用的是push_front方法, 针对的容器有：list, deque
	displayContainer(listInt);


	copy(numbers.begin(), numbers.end(),
			back_insert_iterator<list<int> >(listInt));//调用的是push_back方法
	displayContainer(listInt);

	//在容器的任意位置添加元素
	copy(numbers.begin(), numbers.end(),
			insert_iterator<list<int>>(listInt, ++listInt.begin()));//调用的是insert方法
	displayContainer(listInt);
}

int main(void)
{
	test0();
	return 0;
}


