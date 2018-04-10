 ///
 /// @file    mem_fn.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-26 20:12:21
 ///

#include <stdio.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class Number
{
public:
	Number(int val)
	:_val(val)
	{}

	void dispaly() const
	{
		cout << _val << " ";
	}

	bool isEven() const
	{
		return !_val % 2;
	}

	bool isPrime() const
	{
		for(int idx = 2;idx <= _val/2; ++idx)
		{
			if(_val % idx == 0)
				return false;
		}
		return true;
	}
private:
	int _val;
};

int main(void)
{
	vector<Number> numbers;
	for(int idx = 1;idx != 15; ++idx)
	{
		numbers.push_back(Number(idx));
	}

	std::for_each(numbers.begin(),numbers.end(),std::mem_fn(&Number::dispaly));
	cout << endl;

	numbers.erase(std::remove_if(numbers.begin(),numbers.end(),std::mem_fn(&Number::isPrime)),numbers.end());
	std::for_each(numbers.begin(),numbers.end(),std::mem_fn(&Number::dispaly));
	cout << endl;

}

