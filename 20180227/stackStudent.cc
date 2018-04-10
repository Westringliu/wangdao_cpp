 ///
 /// @file    stackStudent.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-27 19:02:49
 ///


#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(const char *name,int id)
	:_name(new char[strlen(name)+1]())
	,_id(id)
	{
		cout<<"Student(const char *,int)"<<endl;
		strcpy(_name,name);
	}

	void print() const
	{
		cout<<"name:"<<_name<<endl;
		cout<<"id	"<<_id<<endl;
	}

	~Student()
	{
		cout<<"Student"<<endl;
		delete [] _name;
	}

private:
	void *operator new(size_t sz);
	void operator delete(void *ret);

private:
	char *_name;
	int _id;

};

int main(void)
{
	Student s1("Mike",100);
	return 0;
}
