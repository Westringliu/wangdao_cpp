 ///
 /// @file    replace.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-26 14:45:53
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> numbers{1,2,3,4,5,6};
	int a[]={1,2,3,4,5,6};
	std::vector<int> arr(a,a+6);
	std::less<int> lt;

	//std::replace_if(numbers.begin(),numbers.end(),bind2nd(lt,3),7);
	std::replace_if(numbers.begin(),numbers.end(),std::bind1st(lt,3),7);
	//arr.erase(std::remove_if(arr.begin(),arr.end(),std::bind2nd(std::greater<int>(),4)),arr.end());
	std::remove_if(arr.begin(),arr.end(),std::bind2nd(std::greater<int>(),4));
	//std::ostream_iterator<int> osi(cout," ");
	//std::copy(numbers.begin(),numbers.end(),osi);
	
	std::ostream_iterator<int> osi(cout," ");
	std::copy(arr.begin(),arr.end(),osi);

	return 0;
}
