 ///
 /// @file    map.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-06 23:26:56
 ///

#include <utility>
#include <string>
#include <map>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

void test0(void)
{
	std::pair<int,string> t(600036,"招商银行");
	cout << t.first << " -->" << t.second << endl;
}

void test1(void)
{
	map<int,string,std::greater<int>> mapInStr = {
		pair<int,string>(1,"北京"),
		pair<int,string>(1,"深圳"),
		pair<int,string>(1,"广州"),
		pair<int,string>(1,"苏州"),
	};

	for(auto &elem : mapInStr)
	{
		cout << elem.first << " --->" << elem.second <<endl;
	}

	cout << mapInStr[1] << endl;
	cout << mapInStr[0] << endl;

	pair<map<int,string,std::greater<int>>::iterator,bool> ret = mapInStr.insert(std::make_pair(4,"武汉"));
	if(ret.second)
	{
		cout << "insert success" << endl;
		cout << ret.first->first << " --->" << ret.first->second << endl;
	}
	else
	{
		cout << "insert failed" << endl;
		cout << ret.first->first << " --->" << ret.first->second << endl;
	}

	cout << endl;
	mapInStr.erase(3);
	auto it = mapInStr.begin();
	++it;
	mapInStr.erase(it);
	for(auto &elem : mapInStr)
	{
		cout << elem.first << " --->" << elem.second << endl;
	}

	mapInStr.clear();
	cout << "after clear: " << endl;
	for(auto &elem : mapInStr)
	{
		cout << elem.first << " --->" << elem.second << endl;
	}
}

void test2(void)
{
	map<string,string,std::greater<string>> mapInStr = {
		pair<string,string>("s1","北京"),
		pair<string,string>("s2","北京"),
		pair<string,string>("s3","北京"),
		pair<string,string>("s2","苏州")
	};

	for(auto & elem : mapInStr)
	{
		cout << elem.first << " --->" << elem.second << endl;
	}

	cout << mapInStr["s1"] << endl;
	cout << mapInStr["s0"] << endl;

	mapInStr["s0"] = "";
	mapInStr["s1"] = "";
	for(auto & elem : mapInStr)
	{
		cout << elem.first << " --->" << elem.second << endl;
	}
}

int main(void)
{
//	test0();
//	test1();
	test2();

	return 0;
}

