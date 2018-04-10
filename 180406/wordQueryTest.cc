 ///
 /// @file    wordQueryTest.cc
 /// @author  westring(1364643962@qq.com)
 /// @date    2018-04-07 18:43:51
 ///
 
#include "Query.h"
#include "TextQuery.h"

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
#include <fstream>
using std::istream;
#include <cctype>
#include <cstring>

int main(int argc,char **argv)
{
	TextQuery file = get_file(argc,argv);

	do{
		string sought;
		if(!get_word(sought)) break;

		Query name(sought);
		const QueryResult results = name.eval(file);

		cout << "\nExcuting Query for: " << name << endl;

		print(cout,results) << endl;
	}while(true);

	return 0;
}
