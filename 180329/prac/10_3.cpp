 ///
 /// @file    10_3.cpp
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-29 09:46:32
 ///
 
#include <iostream>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::cin;

template <typename T,typename InputIterator,typename OutputIterator>
void mySort(InputIterator first,InputIterator last,OutputIterator result)
{
	std::vector<T> s;
	for(;first != last; ++first)
	{
		s.push_back(*first);
	}

	sort(s.begin(),s.end());
	
	copy(s.begin(),s.end(),result);
}

int main(void)
{
	double a[5] = {1.2,2.4,0.8,3.3,3.2};
	mySort<double>(a,a+5,std::ostream_iterator<double>(cout," "));
	cout << endl;

	//输入流迭代器，以ctrl＋d作为结束
	mySort<int>(std::istream_iterator<int>(cin),std::istream_iterator<int>(),std::ostream_iterator<int>(cout," "));

	cout << endl;

	return 0;
}
