 ///
 /// @file    10_1.cpp
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-26 22:42:02
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main(void)
{
	const int N = 5;
	vector<int> s(N);
	for(int idx = 0;idx < N; ++idx)
	{
		cin >> s[idx];
	}
		transform(s.begin(),s.end(),std::ostream_iterator<int>(cout," "),std::negate<int>());
		cout << endl;
		return 0;
}
