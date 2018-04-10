 ///
 /// @file    10_1.cpp
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-29 09:13:23
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::vector;
 
int main(void)
{
	const int N = 5;
	vector<int> s(N);
	for(int i = 0;i < N; ++i)
	{
		std::cin >> s[i];
	}

	std::transform(s.begin(),s.end(),std::ostream_iterator<int>(cout," "),std::negate<int>());

	cout << endl;
	return 0;
}
