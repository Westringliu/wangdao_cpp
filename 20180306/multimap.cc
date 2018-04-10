 ///
 /// @file    multimap.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-07 20:13:12
 ///
 
#include <utility>
#include <string>
#include <map>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::multimap;
using std::pair;

void test0(void)
{
	std::pair<int,string> t(600036,"");
	cout << t.first << "--->" << t.second << endl;
}

void test1(void)
{
	multimap<int,string,std::greater<int>> multimapInstr = {
		pair<int,string>(1,"北京"),
		pair<int,string>(2,"深圳"),
		pair<int,string>(3,"广州"),
		pair<int,string>(2,"苏州")
	};
	for(auto & elem : multimapInstr)
	{
		cout << elem.first << " --->" << elem.second << endl;
	}

	multimap<int,string,std::greater<int>>::const_iterator cit;
	for(cit = multimapInstr.begin();cit != multimapInstr.end();++cit)
	{
		cout << cit->first << " --->" << cit->second << endl;
	}
}

void test2(void)
{
	multimap<string,string,std::greater<string>> multimapInstr = {
	pair<string,string>("s1","北京"),
	pair<string,string>("s2","深圳"),
	pair<string,string>("s3","广州"),
	pair<string,string>("s4","苏州")
	};

	for(auto & elem : multimapInstr)
	{
		cout << elem.first << " --->" << elem.second << endl;
	}
}

int main(void)
{
//	test0();
	test1();
	test2();
	return 0;
}
