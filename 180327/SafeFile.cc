 ///
 /// @file    SafeFile.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-03-27 15:51:52
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


class SafeFile
{
public:
	SafeFile(FILE * filePointer)
	:_filePointer(filePointer)
	{}

	void write(const string & msg)
	{
		fwrite(msg.c_str(),msg.size(),1,_filePointer);
	}
	
	~SafeFile()
	{
		if(_filePointer)
		{
			fclose(_filePointer);
			cout << "~SafeFile()" << endl;
		}
	}
private:
	 FILE *_filePointer;
};

int main(void)
{
	SafeFile sf(fopen("text.txt","wr+"));
	sf.write("hello,world\n");

	return 0;
}
