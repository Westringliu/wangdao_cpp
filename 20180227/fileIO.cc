///
/// @file    fileIO.cc
/// @author  westring(1364643962@qq.com)
/// @date    2018-02-27 20:07:04
///

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;

vector<string> lines;

void test1(void)
{
	ifstream ifs;
	ifs.open("cin.cc");
	if(!ifs)
	{
		cout<<"ifstream open error!"<<endl;
		return;
	}

	string line;
	lines.reserve(50);

	while(getline(ifs,line))
	{
		lines.push_back(line);//add a new data into tail of vector
	}

	for(auto & elem:lines)//copy lines to elem and judge type of elem automatically
	{
		cout<<elem<<endl;
	}
	ifs.close();
}

void test2(void)
{
	string filename="test.txt";
	ofstream ofs(filename);
	if(!ofs.good())
	{
		cout<<"ofstream open failed!"<<endl;
		return;
	}
	for(auto &elem:lines)
	{
		ofs<<elem<<'\n';
	}
	ofs.close();
}

void test3(void)
{
	ofstream ofs("test.txt",std::ios::app);
	if(!ofs.good())
	{
		cout<<"ofstream open error"<<endl;
		return;
	}

	int position=ofs.tellp();
	cout<<"position="<<position<<endl;

	ofs.close();
}

void test4(void)
{
	fstream fs("test.dat");
	if(!fs.good())
	{
		cout<<"fstream open error!"<<endl;
		return;
	}

	int number;

	cout<<"fs's filepointer = "<<fs.tellg()<<endl;
	for(int idx=0;idx<10;idx++)
	{
		cin>>number;
		fs<<number<<" ";
		cout<<"fs's filepointer = "<<fs.tellg()<<endl;
	}

	fs.seekg(std::ios::beg);
	for(int idx=0;idx<10;++idx)
	{
		fs>>number;
		cout<<"number = "<<number<<endl;
	}

	fs.close();
}

void test5(void)
{
	ifstream ifs("test.txt",std::ios::ate);
	if(!ifs.good())
	{
		cout<<"ifstream open error"<<endl;
		return;
	}
	int position=ifs.tellg();
	cout<<"position="<<position<<endl;

//	ofs<<"that's a new line";//error:only can be used in ifstream

	ifs.close();
}

int main(void)
{
//	test1();
//	test2();
//	test3();
//	test4();
	test5();
	return 0;
}
