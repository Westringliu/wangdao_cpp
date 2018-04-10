 ///
 /// @file    deleter.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-27 19:50:51
 ///
 
#include <string>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;

struct Fpcloser
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout << "> fclose(fp)" << endl;
		}
	}
};

void test0(void)
{
	shared_ptr<FILE> sp(fopen("test.txt","rw+"),Fpcloser());

	string s1("nihao");
	fwrite(s1.c_str(),s1.size(),1,sp.get());
}

void test1(void)
{
	unique_ptr<FILE,Fpcloser> up(fopen("test.txt","rw+"),Fpcloser());

	string s1("nihao");
	fwrite(s1.c_str(),s1.size(),1,up.get());
}

int main(void)
{
	test0();
	test1();
	return 0;
}
