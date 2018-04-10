 ///
 /// @file    heapStudent.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-02-27 17:20:35
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
		cout<<"id  :"<<_id<<endl;
	}

	void release()
	{
		delete this;
	}
private:
	~Student()
	{
		cout<<"~Student"<<endl;
		delete [] _name;
	}

public:
	void * operator new(size_t sz)
	{
		cout<<"void *operator new(size_t)"<<endl;
		void *ret=malloc(sz);
		return ret;
	}

	void operator delete(void *ret)
	{
		cout<<"operator delete(void *)"<<endl;
		free(ret);
	}

private:
	char *_name;
	int _id;
};

int main(void)
{
	Student *pstu=new Student("Jackie",101);
	pstu->print();
	pstu->release();
//	delete pstu;
	return 0;
}
