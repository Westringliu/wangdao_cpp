 ///
 /// @file    MutexLock.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-27 15:53:58
 ///

#include <string>
#include <limits>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(void)
{
	int number;
	cout<<">pls input a number:"<<endl;
	while(cin>>number,!cin.eof())
	{
		if(cin.bad())
		{
			cout<<"io is corrupted!"<<endl;
			return -1;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout<<">pls input a number:"<<endl;
			continue;
		}
		cout<<"number = "<<number<<endl;
	}
	return 0;
}
