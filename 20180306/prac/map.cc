 ///
 /// @file    map.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-07 10:00:47
 ///

#include <map>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

void test0(void)
{
	map<int,string> mapStudent;
	mapStudent.insert(pair<int,string>(1,"st1"));
	mapStudent.insert(pair<int,string>(1,"st2"));//will not cover the old
	mapStudent.insert(pair<int,string>(3,"st3"));
	map<int,string>::iterator iter;
	for(iter = mapStudent.begin();iter != mapStudent.end();++iter)
	{
		cout << iter->first << "--->" << iter->second << endl;
	}
}
void test1(void)
{
	map<int,string> mapStudent;
	mapStudent.insert(map<int,string>::value_type(1,"ty_one"));
	mapStudent.insert(map<int,string>::value_type(1,"ty_two"));//will not cover the old
	mapStudent.insert(map<int,string>::value_type(3,"ty_three"));
	map<int,string>::iterator iter;
	for(iter = mapStudent.begin();iter != mapStudent.end();++iter)
	{
		cout << iter->first << "--->" << iter->second << endl;
	}
}

void test2(void)
{
	map<int,string> mapStudent;
	mapStudent[1] = "student_one";
	mapStudent[1] = "student_two";//will cover the old
	mapStudent[3] = "student_three";
	map<int,string>::iterator iter;
	for(iter = mapStudent.begin();iter != mapStudent.end();++iter)
	{
		cout << iter->first << "--->" << iter->second << endl;
	}

}

void test3(void)
{
	map<int,string> mapStudent;
	pair<map<int,string>::iterator,bool> Insert_pair;
	Insert_pair = mapStudent.insert(pair<int,string>(1,"student_one"));
	if(Insert_pair.second == true)
		cout << "Insert success" << endl;
	else
		cout << "Insert failed" << endl;
	Insert_pair = mapStudent.insert(pair<int,string>(3,"student_two"));
	if(Insert_pair.second == true)
		cout << "Insert success" << endl;
	else
		cout << "Insert failed" << endl;
	map<int,string>::iterator iter;
	for(iter = mapStudent.begin();iter != mapStudent.end();++iter)
	{
		cout << iter->first << "--->" << iter->second << endl;
	}
	cout << "size of map is " << mapStudent.size() << endl;

}

void test4(void)
{
	map<int,string> mapStudent;
	mapStudent.insert(pair<int,string>(4,"std_four"));
	mapStudent.insert(pair<int,string>(1,"std_one"));
	mapStudent.insert(pair<int,string>(2,"std_two"));
	mapStudent.insert(pair<int,string>(7,"std_seven"));
	map<int,string>::reverse_iterator iter;
	for(iter = mapStudent.rbegin();iter != mapStudent.rend();++iter)
	{
		cout << iter->first << " --->" << iter->second << endl;
	}
}


int main(void)
{
//	test0();
//	test1();
//	test2();
//	test3();
	test4();
	return 0;
}
