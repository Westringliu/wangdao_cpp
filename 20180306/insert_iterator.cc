 ///
 /// @file    insert_iterator.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-06 23:02:15
 ///

#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;
using std::vector;
using std::list;
using std::copy;

template <typename Container>
void displayConainer(const Container &c)
{
	typename Container::const_iterator cit;
	for(cit = c.begin();cit != c.end(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

void test0(void)
{
	vector<int> numbers{1,2,3};
	list<int> listInt;

	copy(numbers.begin(),numbers.end(),
		front_insert_iterator<list<int> >(listInt));
	displayConainer(listInt);

	copy(numbers.begin(),numbers.end(),
			back_insert_iterator<list<int> >(listInt));

	copy(numbers.begin(),numbers.end(),
			insert_iterator<list<int> >(listInt,++listInt.begin()));
	displayConainer(listInt);
}

int main(void)
{
	test0();
	return 0;
}
