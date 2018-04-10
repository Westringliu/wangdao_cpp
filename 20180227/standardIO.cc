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

void printCin()
{
	cout<<"cin's badbit = "<<cin.bad()<<endl;
	cout<<"cin's failbit = "<<cin.fail()<<endl;
	cout<<"cin's eofbit = "<<cin.eof()<<endl;
	cout<<"cin's goodbit = "<<cin.good()<<endl;
}

int main(void)
{
	printCin();

	cout<<"sizeof(cin)= "<<sizeof(cin)<<endl;
	cout<<"sizeof(cout) = "<<sizeof(cout)<<endl;
	
	int number;
	while(cin>>number)
	{
		cout<<"number = "<<number<<endl;
	}

	printCin();

	cout<<endl<<"fflush"<<endl;
	cin.clear();
	printCin();

	cout<<"fflush"<<endl;

	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	string line;
	cin>>line;

	cout<<"line = "<<line<<endl;
	return 0;
}
