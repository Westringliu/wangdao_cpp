 ///
 /// @file    arrow.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-13 15:30:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	int length()
	{
		return 5;
	}
};

class DataPtr
{
public:
	DataPtr()
	:_data(new Data)
	{
		cout << "DataPtr()" << endl;
	}

	~DataPtr()
	{
		cout << "~DataPtr()" << endl;
		delete _data;
	}

	Data *operator->()
	{
		return _data;
	}

	Data &operator*()
	{
		return *_data;
	}
private:
	Data *_data;
};

class ThirdLayer
{
public:
	ThirdLayer()
	:_p(new DataPtr)
	{
		cout << "ThirdLayer()" << endl;
	}

	DataPtr &operator->()
	{
		return *_p;
	}

	~ThirdLayer()
	{
		cout << "ThirdLayer()" << endl;
		delete _p;
	}
private:
	DataPtr *_p;
};

int main(void)
{
	DataPtr dp;
	cout << dp.operator->()->length() << endl;
	cout << dp->length() << endl;

	cout << (*dp).length() << endl;

	ThirdLayer tl;
	cout << tl.operator->().operator->()->length() << endl;
	cout << tl->length() << endl;

	return 0;
}
