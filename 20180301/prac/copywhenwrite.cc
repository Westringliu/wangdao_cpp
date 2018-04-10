 ///
 /// @file    copywhenwrite.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-02 10:40:39
 ///

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

struct shared_ptr
{
	char *data;
	int ref;
};

class String
{
public:
	String(const char *str=NULL)
	:iswrite(false)
	{
		p=new shared_ptr;
		if(str!=NULL)
		{
			p->data=new char[strlen(str)+1];
			strcpy(p->data,str);
		}
		else
		{
			p->data=new char[1];
			p->data[0]='\0';
		}
		p->ref=1;
	}

	String(const String &s)
	:iswrite(false)
	{
		p=s.p;
		p->ref+=1;
	}

	~String()
	{
		if(p->ref == 1)
		{
			delete p->data;
			delete p;
		}
		else{
			p->ref-=1;
		}
	}

	String &erase(int first,int last)
	{
		if(first<0||last>strlen(p->data))
			return *this;
		if(!iswrite)
		{
			shared_ptr *t=p;
			p=new shared_ptr;
			p->data=new char[strlen(t->data)+1];
			strcpy(p->data,t->data);
			p->ref=1;
			t->ref-=1;
		}
		int len=strlen(p->data);
		for(int i=0;i<len-last+1;i++)
		{
			p->data[first+i]=p->data[last+i];
		}
		return *this;
	}

	void show()const
	{
		printf("ref=%d,data:%s\n",p->ref,p->data);
	}

private:
	shared_ptr *p;
	bool iswrite;
};

int main()
{
	String s1("hello world");
	String s2(s1);
	String s3(s2);
	s1.show();
	s2.show();
	s3.show();
	
	s2.erase(5,10);
	s1.show();
	s2.show();
	s3.show();

}
